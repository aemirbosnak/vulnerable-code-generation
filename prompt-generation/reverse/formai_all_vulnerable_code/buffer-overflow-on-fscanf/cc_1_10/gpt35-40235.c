//FormAI DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESS_NAME 30
#define MAX_PROCESS_STATE 10

// Define colors for the output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define WHITE "\033[0;37m"

// Define structure for the process information
struct ProcessInfo {
    char pid[6];
    char name[MAX_PROCESS_NAME];
    char state[MAX_PROCESS_STATE];
};

void getProcessList(struct ProcessInfo *processList) {
    DIR *directory;
    struct dirent *entry;
    char cmdPath[40], statusPath[40], buffer[50];
    FILE *cmdFile, *statusFile;

    // Open directory for reading
    directory = opendir("/proc");

    if (directory != NULL) {
        // Loop through all files in directory
        while ((entry = readdir(directory))) {
            // Ignore files that are not directories
            if (entry->d_type == DT_DIR) {
                // Check if name is a number (process ID)
                if (isdigit(entry->d_name[0])) {
                    // Get paths for the cmd and status files
                    sprintf(cmdPath, "/proc/%s/cmdline", entry->d_name);
                    sprintf(statusPath, "/proc/%s/status", entry->d_name);

                    // Open the cmd and status files for reading
                    cmdFile = fopen(cmdPath, "r");
                    statusFile = fopen(statusPath, "r");

                    if (cmdFile != NULL && statusFile != NULL) {
                        // Read the process name from the cmd file
                        fscanf(cmdFile, "%s", buffer);

                        // Check if process name is too long
                        if (strlen(buffer) > MAX_PROCESS_NAME - 1) {
                            strncpy(processList->name, buffer, MAX_PROCESS_NAME - 4);
                            strcat(processList->name, "...");
                        } else {
                            strcpy(processList->name, buffer);
                        }

                        // Read the process state from the status file
                        while (fscanf(statusFile, "%s", buffer) == 1) {
                            if (strcmp(buffer, "State:") == 0) {
                                fscanf(statusFile, "%s", buffer);
                                strcpy(processList->state, buffer);
                                break;
                            }
                        }

                        // Copy the process ID to the struct
                        strcpy(processList->pid, entry->d_name);

                        // Move to the next struct
                        processList++;
                    }

                    // Close the files
                    fclose(cmdFile);
                    fclose(statusFile);
                }
            }
        }

        // Close the directory
        closedir(directory);
    }
}

void printProcessList(struct ProcessInfo *processList) {
    printf("+------+-----------------------------+---------+\n");
    printf("| %sPID%s | %sNAME%s                      | %sSTATE%s |\n", YELLOW, WHITE, YELLOW, WHITE, YELLOW, WHITE);
    printf("+------+-----------------------------+---------+\n");

    // Loop through all structs in the process list and print the information
    while (strlen(processList->pid) > 0) {
        printf("| %-4s | %-27s |", processList->pid, processList->name);

        // Print the process state in different colors
        if (strcmp(processList->state, "R") == 0) {
            printf(" %sRUNNING%s |\n", GREEN, WHITE);
        } else if (strcmp(processList->state, "S") == 0) {
            printf(" %sSLEEPING%s |\n", YELLOW, WHITE);
        } else {
            printf(" %s%s%s |\n", RED, processList->state, WHITE);
        }

        processList++;
    }

    printf("+------+-----------------------------+---------+\n");
}

int main() {
    // Initialize the process list with empty strings
    struct ProcessInfo processList[100] = {{"", "", ""}};

    // Clear the console
    system("clear");

    // Print the process list header
    printf("%sPROCESS VIEWER (post-apocalyptic style)\n\n%s", RED, WHITE);

    // Get the process list and print it
    getProcessList(processList);
    printProcessList(processList);

    return 0;
}