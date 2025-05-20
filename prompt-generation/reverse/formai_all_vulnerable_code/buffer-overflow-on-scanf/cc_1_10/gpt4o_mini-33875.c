//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc"
#define BUFFER_SIZE 256

void list_processes();
void print_process_info(const char *pid);
char* get_process_status(const char *pid);

int main() {
    int choice;

    while (1) {
        printf("\n=== Linux Process Viewer ===\n");
        printf("1. List all processes\n");
        printf("2. Show specific process info\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2: {
                char pid[BUFFER_SIZE];
                printf("Enter Process ID (PID): ");
                scanf("%s", pid);
                print_process_info(pid);
                break;
            }
            case 3:
                printf("Exiting the Process Viewer...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("\nPID\tCOMMAND\n");
    printf("-------------------------\n");
    
    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {  // Check if the name is a number (PID)
            printf("%s\t", entry->d_name);
            // Get the command name of the process
            char command_path[BUFFER_SIZE];
            snprintf(command_path, sizeof(command_path), "%s/%s/comm", PROC_PATH, entry->d_name);
            FILE *cmd_file = fopen(command_path, "r");
            if (cmd_file) {
                char command[BUFFER_SIZE];
                fgets(command, sizeof(command), cmd_file);
                printf("%s", command);
                fclose(cmd_file);
            }
            printf("\n");
        }
    }
    
    closedir(dp);
}

void print_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "%s/%s/status", PROC_PATH, pid);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Process with PID %s does not exist.\n", pid);
        return;
    }

    printf("\nProcess Information for PID %s:\n", pid);
    printf("-------------------------------\n");
    
    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0 ||
            strncmp(line, "State:", 6) == 0 ||
            strncmp(line, "Pid:", 4) == 0 ||
            strncmp(line, "Uid:", 4) == 0 ||
            strncmp(line, "Gid:", 4) == 0 ||
            strncmp(line, "VmSize:", 7) == 0) {
            printf("%s", line);
        }
    }
    
    fclose(file);
}

char* get_process_status(const char *pid) {
    static char status[BUFFER_SIZE];
    snprintf(status, sizeof(status), "%s/%s/stat", PROC_PATH, pid);
    FILE *file = fopen(status, "r");
    
    if (file) {
        char buffer[BUFFER_SIZE];
        fgets(buffer, sizeof(buffer), file);
        fclose(file);
        return strdup(buffer);  // Return the process status line
    }
    
    return NULL;  // Return NULL if the file doesn't exist
}