//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_DIR "/proc/"
#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[16];
} ProcessInfo;

void trim(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
}

void read_process_info(int pid, ProcessInfo *proc_info) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), PROC_DIR "%d/stat", pid);
    
    FILE *file = fopen(path, "r");
    if (file) {
        fscanf(file, "%d %s %s", &proc_info->pid, proc_info->name, proc_info->state);
        fclose(file);
        trim(proc_info->name);
    } else {
        proc_info->pid = -1; 
    }
}

void list_processes() {
    struct dirent *entry;
    DIR *dir = opendir(PROC_DIR);
    ProcessInfo processes[MAX_PROCESSES];
    int process_count = 0;

    if (dir == NULL) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) { 
            int pid = atoi(entry->d_name);
            ProcessInfo proc_info;
            read_process_info(pid, &proc_info);
            if (proc_info.pid != -1) {
                processes[process_count++] = proc_info;
            }
            if (process_count >= MAX_PROCESSES) break;
        }
    }
    closedir(dir);

    printf("%-7s %-25s %-10s\n", "PID", "Process Name", "State");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < process_count; i++) {
        printf("%-7d %-25s %-10s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

void display_menu() {
    printf("==============================================\n");
    printf("          Linux Process Viewer              \n");
    printf("==============================================\n");
    printf("1. List all processes\n");
    printf("2. Quit\n");
    printf("==============================================\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                printf("Exiting the Process Viewer.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 2);

    return 0;
}