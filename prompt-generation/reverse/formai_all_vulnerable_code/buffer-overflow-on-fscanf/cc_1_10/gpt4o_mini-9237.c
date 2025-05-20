//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define BUFFER_SIZE 256

void display_process_info(int pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "%s/%d/stat", PROC_DIR, pid);
    
    FILE *fp = fopen(path, "r");
    if (!fp) {
        return;
    }

    int ppid, pgrp, state;
    char comm[BUFFER_SIZE], state_str[2];
    
    fscanf(fp, "%d %s %s %d %d", 
           &pid, comm, state_str, &ppid, &pgrp);
    
    state = (strcmp(state_str, "R") == 0) ? 1 :
            (strcmp(state_str, "S") == 0) ? 2 :
            (strcmp(state_str, "T") == 0) ? 3 :
            (strcmp(state_str, "Z") == 0) ? 4 : 0;

    fclose(fp);
    
    // Display Process Information
    printf("PID: %d, Command: %s, State: ", pid, comm);
    switch (state) {
        case 1: printf("Running\n"); break;
        case 2: printf("Sleeping\n"); break;
        case 3: printf("Stopped\n"); break;
        case 4: printf("Zombie\n"); break;
        default: printf("Unknown\n"); break;
    }
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_DIR);
    
    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("Processes running on the system:\n");
    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            display_process_info(pid);
        }
    }
    
    closedir(dp);
}

void filter_processes_by_name(const char *name) {
    struct dirent *entry;
    DIR *dp = opendir(PROC_DIR);
    
    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("Processes matching '%s':\n", name);
    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "%s/%d/comm", PROC_DIR, pid);
            FILE *fp = fopen(path, "r");
            if (fp) {
                char proc_name[BUFFER_SIZE];
                fgets(proc_name, sizeof(proc_name), fp);
                proc_name[strcspn(proc_name, "\n")] = 0; // Remove newline

                if (strstr(proc_name, name)) {
                    display_process_info(pid);
                }
                fclose(fp);
            }
        }
    }
    
    closedir(dp);
}

void show_help() {
    printf("Usage:\n");
    printf("  process_viewer [name]\n");
    printf("  If 'name' is provided, it will filter processes by the specified name.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        show_help();
        return EXIT_FAILURE;
    }

    if (argc == 1) {
        list_processes();
    } else {
        filter_processes_by_name(argv[1]);
    }

    return EXIT_SUCCESS;
}