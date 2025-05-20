//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

// Function to print system processes
void print_system_processes(char* command) {
    FILE* fp;
    char line[MAX_COMMAND_LENGTH];
    char* token;
    int pid;

    // Open the file containing system processes
    fp = popen(command, "r");

    // Check if the file was successfully opened
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read each line of the file
    while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
        // Find the process ID in the line
        token = strtok(line, " ");
        pid = atoi(token);

        // Print the process ID and name
        printf("%d: %s\n", pid, line);
    }

    // Close the file
    pclose(fp);
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    // Get the command to print system processes
    printf("Enter the command to print system processes: ");
    scanf("%s", command);

    // Print the system processes
    print_system_processes(command);

    return 0;
}