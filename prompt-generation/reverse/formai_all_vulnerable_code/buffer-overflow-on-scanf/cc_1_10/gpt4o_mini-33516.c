//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_PATH "/proc"
#define BUF_SIZE 256

// Function Prototypes
void list_processes();
void display_process_info(int pid);
void get_process_command(int pid, char *command);

int main() {
    printf("Welcome to the Introspective Process Viewer!\n");
    printf("Listing all processes:\n\n");

    // List all processes available in /proc
    list_processes();

    // Enter loop to allow users to fetch more details about a specific process
    while (1) {
        int pid;
        printf("\nEnter a PID to display more details (0 to exit): ");
        scanf("%d", &pid);
        if (pid == 0) {
            break;
        }
        display_process_info(pid);
    }

    printf("Exiting Process Viewer. Goodbye!\n");
    return 0;
}

// Function to list all processes by reading /proc directory
void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    
    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-30s\n", "PID", "Command");
    printf("------------------------------------------\n");

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is a number (PID)
            if (isdigit(entry->d_name[0])) {
                int pid = atoi(entry->d_name);
                char command[BUF_SIZE];
                get_process_command(pid, command);
                printf("%-10d %-30s\n", pid, command);
            }
        }
    }

    closedir(dp);
}

// Function to get the command associated with a process from its PID
void get_process_command(int pid, char *command) {
    char path[BUF_SIZE];
    snprintf(path, sizeof(path), PROC_PATH "/%d/comm", pid);
    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        snprintf(command, BUF_SIZE, "<unknown>");
        return;
    }
    fgets(command, BUF_SIZE, fp);
    fclose(fp);

    // Remove the newline character from the command
    command[strcspn(command, "\n")] = '\0';
}

// Function to display detailed information about a specific process
void display_process_info(int pid) {
    char path[BUF_SIZE];
    
    printf("\nFetching information for PID: %d\n", pid);

    // Display command name
    char command[BUF_SIZE];
    get_process_command(pid, command);
    printf("Command: %s\n", command);

    // Getting other process details from /proc/[pid]/
    snprintf(path, sizeof(path), PROC_PATH "/%d/stat", pid);
    FILE *fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Process with PID %d does not exist or cannot be accessed.\n", pid);
        return;
    }

    int pid_stat;
    char comm[BUF_SIZE], state;
    unsigned long utime, stime, cutime, cstime, rss;

    fscanf(fp, "%d %s %c %*d %*d %*d %*d %lu %lu %lu %lu %lu", 
           &pid_stat, comm, &state, &utime, &stime, &cutime, &cstime, &rss);
    fclose(fp);

    printf("PID: %d\n", pid_stat);
    printf("State: %c\n", state);
    printf("User Time: %lu\n", utime);
    printf("System Time: %lu\n", stime);
    printf("Child User Time: %lu\n", cutime);
    printf("Child System Time: %lu\n", cstime);
    printf("Memory Usage (RSS): %lu\n", rss);
}