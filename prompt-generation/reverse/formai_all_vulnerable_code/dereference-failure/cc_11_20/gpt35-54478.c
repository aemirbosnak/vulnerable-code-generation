//FormAI DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
// As the sun sets over Verona,
// A gaze upon processes is to be showna.
// The Montagues and Capulets,
// Their differences put aside, they don't forget.
// Together they'll unveil this creation,
// A System process viewer, a true sensation.

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// Function to determine if a string is a number
int is_number(char *str) {
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char *path = "/proc";
    dir = opendir(path);
    
    // Check if directory opened successfully
    if (dir == NULL) {
        fprintf(stderr, "Unable to open directory %s\n", path);
        return EXIT_FAILURE;
    }

    // Display the header
    printf("==================================\n");
    printf(" System Process Viewer - Verona\n");
    printf("==================================\n");
    printf("%-5s%-20s%s\n", "PID", "Process Name", "Status");
    printf("----------------------------------\n");

    // Read directory and display relevant information
    while ((entry = readdir(dir)) != NULL) {
        char *status_path = malloc(strlen(path) + strlen(entry->d_name) + strlen("/status") + 1);
        strcpy(status_path, path);
        strcat(status_path, "/");
        strcat(status_path, entry->d_name);
        strcat(status_path, "/status");
        FILE *status_file = fopen(status_path, "r");
        char *process_name = malloc(1024);
        int pid = -1;

        // Parse the status file and extract relevant information
        if (status_file != NULL) {
            char *line = NULL;
            size_t len = 0;
            ssize_t read;

            while ((read = getline(&line, &len, status_file)) != -1) {
                if (strstr(line, "Name:") != NULL) {
                    char *ptr = line + 5;
                    while (*ptr == ' ')
                        ptr++;
                    strcpy(process_name, ptr);
                    // Remove newline character at end
                    process_name[strlen(process_name) - 1] = '\0';
                }
                else if (strstr(line, "Pid:") != NULL) {
                    char *ptr = line + 4;
                    while (*ptr == ' ')
                        ptr++;
                    pid = atoi(ptr);
                }
                else if (strstr(line, "State:") != NULL) {
                    char *ptr = line + 6;
                    while (*ptr == ' ')
                        ptr++;
                    // Check if the state value is numeric
                    if (is_number(ptr)) {
                        int state = atoi(ptr);
                        if (state == 1)
                            printf("%-5d%-20s%s\n", pid, process_name, "Running");
                        else if (state == 2)
                            printf("%-5d%-20s%s\n", pid, process_name, "Interruptible Sleep");
                        else if (state == 4)
                            printf("%-5d%-20s%s\n", pid, process_name, "Uninterruptible Sleep");
                        else if (state == 8)
                            printf("%-5d%-20s%s\n", pid, process_name, "Zombie");
                        else if (state == 32)
                            printf("%-5d%-20s%s\n", pid, process_name, "Idle");
                        else if (state == 64)
                            printf("%-5d%-20s%s\n", pid, process_name, "Virtual Timer Stopped");
                        else if (state == 128)
                            printf("%-5d%-20s%s\n", pid, process_name, "Profiling");
                    }
                    else {
                        printf("%-5d%-20s%s\n", pid, process_name, ptr);
                    }
                }
            }

            free(line);
            fclose(status_file);
        }

        free(status_path);
        free(process_name);
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}