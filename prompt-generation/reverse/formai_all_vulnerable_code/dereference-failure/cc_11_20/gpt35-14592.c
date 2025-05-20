//FormAI DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int processId;
    char command[64];
    char path[64];
    char line[256];
    char *token;

    // Check if a process id was provided
    if (argc == 1) {
        printf("Please specify the process id.\n");
        return 1;
    }

    // Get the process id from the command line arguments
    processId = atoi(argv[1]);

    // Check if the process id is greater than zero
    if (processId <= 0) {
        printf("Invalid process id.\n");
        return 1;
    }

    // Build the command to list the process information
    sprintf(command, "ls -l /proc/%d", processId);

    // Execute the command and read the output
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error executing command.\n");
        return 1;
    }

    // Parse the output and extract the process path
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " ");
        if (strcmp(token, "lrwxrwxrwx") == 0) {
            token = strtok(NULL, " ");
            sprintf(path, "/proc/%d/%s", processId, token);
            break;
        }
    }

    pclose(fp);

    // Check if the process path was found
    if (strcmp(path, "") == 0) {
        printf("Process path not found.\n");
        return 1;
    }

    // Open the process status file
    sprintf(command, "%s/status", path);
    fp = fopen(command, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Display the process information
    printf("Process: %d\n", processId);
    printf("Path: %s\n", path);
    printf("PID\tPPID\tCMD\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Pid:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, " ");
            printf("%s\t", token);
        }
        if (strstr(line, "PPid:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, " ");
            printf("%s\t", token);
        }
        if (strstr(line, "Name:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, " ");
            printf("%s", token);
        }
    }

    fclose(fp);

    return 0;
}