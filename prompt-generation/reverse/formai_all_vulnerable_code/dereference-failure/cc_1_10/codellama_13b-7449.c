//Code Llama-13B DATASET v1.0 Category: System process viewer ; Style: automated
/*
 * C System Process Viewer Example Program
 *
 * This program will display a list of all the running processes on the system,
 * along with their process ID, name, and memory usage.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {
    struct rusage usage;
    pid_t pid;
    int status;
    char *name;
    int i;

    // Get the list of running processes
    FILE *fp = popen("ps -e", "r");
    if (fp == NULL) {
        perror("Error opening ps");
        return 1;
    }

    // Read the output of ps into a buffer
    char buffer[1024];
    char *line = fgets(buffer, sizeof(buffer), fp);
    if (line == NULL) {
        perror("Error reading from ps");
        return 1;
    }

    // Parse the output of ps
    while (line != NULL) {
        // Get the process ID and name
        pid = atoi(strtok(line, " "));
        name = strtok(NULL, " ");

        // Get the process usage
        getrusage(RUSAGE_SELF, &usage);

        // Print the process information
        printf("%d %s %ld\n", pid, name, usage.ru_maxrss);

        // Get the next line of output from ps
        line = fgets(buffer, sizeof(buffer), fp);
    }

    // Close the file pointer
    pclose(fp);

    return 0;
}