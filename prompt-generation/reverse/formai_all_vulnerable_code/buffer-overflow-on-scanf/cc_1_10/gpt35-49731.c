//FormAI DATASET v1.0 Category: System process viewer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

#define SIZE 1024

// Function declaration
void printProcessDetails(char *pid);
void printProcesses();

int main() {
    int choice;
    while(1) {
        printf("1. See all running processes\n");
        printf("2. View details of a specific process\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printProcesses();
                break;
            case 2: {
                char pid[10];
                printf("Enter PID: ");
                scanf("%s", pid);

                // Check if entered PID is valid
                if(atoi(pid) != 0) {
                    printProcessDetails(pid);
                } else {
                    printf("Invalid PID!\n");
                }
                break;
            }
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
    return 0;
}

void printProcessDetails(char *pid) {
    char path[SIZE];
    char line[SIZE];
    FILE *file;

    printf("PID: %s\n", pid);

    // Read and print process details
    sprintf(path, "/proc/%s/status", pid);
    file = fopen(path, "r");
    if(file) {
        while(fgets(line, SIZE, file)) {
            if(strncmp(line, "Name:", 5) == 0) {
                printf("%s", line);
            } else if(strncmp(line, "State:", 6) == 0) {
                printf("%s", line);
            } else if(strncmp(line, "VmSize:", 7) == 0) {
                printf("%s", line);
            }
        }
        fclose(file);
    }
    printf("\n");
}

void printProcesses() {
    DIR *dir;
    struct dirent *entry;
    char path[SIZE];

    // Open /proc directory
    dir = opendir("/proc");
    if(!dir) {
        perror("Error opening directory");
        exit(1);
    }

    printf("PID\tName\n");

    // Read all directories within /proc (these represent running processes)
    while((entry = readdir(dir)) != NULL) {
        if(!isdigit(*entry->d_name)) {
            continue;
        }

        // Print PID and name of process
        printf("%s\t", entry->d_name);

        sprintf(path, "/proc/%s/cmdline", entry->d_name);
        FILE *file = fopen(path, "r");
        if(file) {
            char line[SIZE];
            fgets(line, SIZE, file);
            printf("%s", line);
            fclose(file);
        }
        printf("\n");
    }

    closedir(dir);
}