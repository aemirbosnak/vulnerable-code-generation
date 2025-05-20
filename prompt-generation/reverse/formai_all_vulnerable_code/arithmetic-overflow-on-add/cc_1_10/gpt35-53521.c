//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROC_PATH 256
#define MAX_PROC_NAME 256

int main()
{
    FILE *fp;
    char buffer[MAX_PROC_NAME], path[MAX_PROC_PATH] = "/proc/", pid[MAX_PROC_NAME];
    int mem_usage, total_usage = 0;

    // Allow user to enter PID to monitor
    printf("Enter PID to monitor: ");
    fgets(pid, MAX_PROC_NAME, stdin);
    pid[strcspn(pid, "\n")] = 0; // remove trailing newline character

    strcat(path, pid);
    strcat(path, "/statm");

    // Read data from /proc/{pid}/statm file to get memory usage information
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Tokenize the data in the file
    if (fgets(buffer, MAX_PROC_NAME, fp) != NULL) {
        char *token = strtok(buffer, " ");

        // Iterate through tokens to find the memory usage
        for (int i = 1; i <= 7; i++) {
            token = strtok(NULL, " ");

            if (i == 2) {
                mem_usage = atoi(token) * 4; // Convert from pages to kilobytes
                printf("Memory usage: %d KB\n", mem_usage);
            }

            total_usage += mem_usage;
        }
    }

    printf("Total memory usage: %d KB\n", total_usage);

    fclose(fp);
    return 0;
}