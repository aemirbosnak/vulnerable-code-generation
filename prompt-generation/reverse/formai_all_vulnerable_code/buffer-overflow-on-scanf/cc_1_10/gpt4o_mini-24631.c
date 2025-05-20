//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char comm[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} ProcessInfo;

void get_process_info(ProcessInfo *proc_info, int *count) {
    DIR *proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    *count = 0;

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);

            FILE *stat_file = fopen(path, "r");
            if (stat_file) {
                ProcessInfo temp;
                temp.pid = atoi(entry->d_name);
                fscanf(stat_file, "%*d %s %*c %s", temp.comm, temp.state);
                fclose(stat_file);

                proc_info[*count] = temp;
                (*count)++;
            }
        }
    }
    closedir(proc_dir);
}

void print_process_info(ProcessInfo *proc_info, int count) {
    printf("%-10s %-25s %-10s\n", "PID", "COMMAND", "STATE");
    printf("%-10s %-25s %-10s\n", "----------", "-------------------------", "----------");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10s\n", proc_info[i].pid, proc_info[i].comm, proc_info[i].state);
    }
}

void display_menu() {
    printf("=== Process Viewer ===\n");
    printf("1. View All Processes\n");
    printf("2. Exit\n");
}

void run_process_viewer() {
    while (1) {
        display_menu();

        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            ProcessInfo proc_info[MAX_PROCESSES];
            int process_count = 0;

            // Fetch and display process information
            get_process_info(proc_info, &process_count);
            print_process_info(proc_info, process_count);
            printf("\n");
        } else if (choice == 2) {
            printf("Exiting Process Viewer...\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }

        sleep(1);
    }
}

int main() {
    run_process_viewer();
    return 0;
}