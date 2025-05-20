//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_PATH "/proc/"

void print_process_info(pid_t pid) {
    char path[256], line[256];
    sprintf(path, PROC_PATH "%d/status", pid);

    FILE *status_file = fopen(path, "r");
    if (status_file) {
        printf("\nProcess ID: %d\n", pid);
        while (fgets(line, sizeof(line), status_file)) {
            if (strncmp(line, "Name:", 5) == 0 || 
                strncmp(line, "State:", 6) == 0 || 
                strncmp(line, "Pid:", 4) == 0 || 
                strncmp(line, "PPid:", 5) == 0 ||
                strncmp(line, "Uid:", 4) == 0 ||
                strncmp(line, "Gid:", 4) == 0) {
                printf("%s", line);
            }
        }
        fclose(status_file);
    } else {
        perror("Failed to open status file");
    }
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    if (dp == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    printf("Current Running Processes:\n");
    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            print_process_info(pid);
        }
    }
    closedir(dp);
}

void filter_processes_by_name(const char *filter) {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    if (dp == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    printf("\nProcesses containing '%s':\n", filter);
    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            char path[256], line[256];
            sprintf(path, PROC_PATH "%d/comm", pid);

            FILE *comm_file = fopen(path, "r");
            if (comm_file) {
                if (fgets(line, sizeof(line), comm_file)) {
                    line[strcspn(line, "\n")] = 0; // Strip newline
                    if (strstr(line, filter) != NULL) {
                        print_process_info(pid);
                    }
                }
                fclose(comm_file);
            }
        }
    }
    closedir(dp);
}

void display_menu() {
    printf("===================================\n");
    printf("         Process Viewer           \n");
    printf("===================================\n");
    printf("1. List all processes\n");
    printf("2. Filter processes by name\n");
    printf("3. Exit\n");
    printf("===================================\n");
}

int main() {
    int choice;
    char filter[50];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                printf("Enter process name to filter: ");
                scanf("%s", filter);
                filter_processes_by_name(filter);
                break;
            case 3:
                printf("Exiting the Process Viewer. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar(); // consume the newline character
        getchar(); // wait for another input
    }
    return 0;
}