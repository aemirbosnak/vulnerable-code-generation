//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_PATH 256

typedef struct {
    int pid;
    char name[64];
    char state[16];
} Process;

void get_processes(Process processes[], int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];
    FILE *stat_file;
    
    *count = 0;
    if ((dir = opendir("/proc")) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (isdigit(entry->d_name[0])) { // Only process directories 
                snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
                stat_file = fopen(path, "r");
                
                if (stat_file) {
                    int pid;
                    char name[64];
                    char state[16];
                    
                    fscanf(stat_file, "%d %s %s", &pid, name, state);
                    processes[*count].pid = pid;
                    strcpy(processes[*count].name, name);
                    strcpy(processes[*count].state, state);
                    (*count)++;
                    
                    fclose(stat_file);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Could not open /proc directory");
    }
}

void display_processes(Process processes[], int count) {
    printf("%-10s %-25s %-10s\n", "PID", "Process Name", "State");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

void search_process(Process processes[], int count) {
    int pid_to_search;
    printf("\nEnter PID of process to search: ");
    scanf("%d", &pid_to_search);
    
    for (int i = 0; i < count; i++) {
        if (processes[i].pid == pid_to_search) {
            printf("\nProcess Found:\n");
            printf("PID: %d\nName: %s\nState: %s\n", processes[i].pid, processes[i].name, processes[i].state);
            return;
        }
    }
    printf("Process with PID %d not found.\n", pid_to_search);
}

void display_menu() {
    printf("\n=== System Process Viewer ===\n");
    printf("1. View List of Processes\n");
    printf("2. Search for a Process by PID\n");
    printf("3. Exit\n");
    printf("=============================\n");
}

int main() {
    Process processes[MAX_PROCESSES];
    int process_count;
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                get_processes(processes, &process_count);
                display_processes(processes, process_count);
                break;
            case 2:
                get_processes(processes, &process_count);
                search_process(processes, process_count);
                break;
            case 3:
                printf("Exiting System Process Viewer. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}