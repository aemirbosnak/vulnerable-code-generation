//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define MAX_PID_SIZE 6
#define MAX_CMD_SIZE 256

void print_row(char pid[], char cmd[], char status[]) {
    printf("%-10s %-40s %-20s\n", pid, cmd, status);
}

void print_header() {
    printf("%-10s %-40s %-20s\n\n", "PID", "CMD", "STATUS");
}

int main() {
    // Open the directory containing the process information
    DIR *dir = opendir("/proc");

    if (!dir) {
        perror("Error opening /proc directory");
        exit(1);
    }

    print_header();

    struct dirent *entry;

    // Iterate over all directories in /proc
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is a number (i.e. a PID)
            char *endptr;
            long pid = strtol(entry->d_name, &endptr, 10);

            if (*endptr == '\0') {
                // Create the full path to the command file for this process
                char cmd_path[256];
                sprintf(cmd_path, "/proc/%ld/cmdline", pid);

                // Open the command file
                FILE *cmd_file = fopen(cmd_path, "r");

                if (!cmd_file) {
                    perror("Error opening command file");
                    exit(1);
                }

                // Read the command file
                char cmd[MAX_CMD_SIZE];
                fgets(cmd, MAX_CMD_SIZE, cmd_file);

                // Remove newline characters from the command string
                int cmd_len = strlen(cmd);
                if (cmd[cmd_len-1] == '\n') {
                    cmd[cmd_len-1] = '\0';
                }
                if (cmd[cmd_len-2] == '\n') {
                    cmd[cmd_len-2] = '\0';
                }

                // Close the command file
                fclose(cmd_file);

                // Create the full path to the status file for this process
                char status_path[256];
                sprintf(status_path, "/proc/%ld/status", pid);

                // Open the status file
                FILE *status_file = fopen(status_path, "r");

                if (!status_file) {
                    perror("Error opening status file");
                    exit(1);
                }

                // Read the status file
                char line[256];
                char status[20];
                while (fgets(line, MAX_CMD_SIZE, status_file)) {
                    if (strncmp(line, "State:", 6) == 0) {
                        strncpy(status, line+7, sizeof(status));
                        break;
                    }
                }

                // Remove newline characters from the status string
                int status_len = strlen(status);
                if (status[status_len-1] == '\n') {
                    status[status_len-1] = '\0';
                }
                if (status[status_len-2] == '\n') {
                    status[status_len-2] = '\0';
                }

                // Close the status file
                fclose(status_file);

                // Format and print the row of information
                char pid_str[MAX_PID_SIZE];
                sprintf(pid_str, "%ld", pid);
                print_row(pid_str, cmd, status);
            }
        }
    }

    // Close the /proc directory
    closedir(dir);

    return 0;
}