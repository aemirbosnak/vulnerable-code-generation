//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

// Define some colors for the output
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define RESET   "\x1b[0m"

// Define the process viewer function
void view_processes() {
    // Get the system information
    struct sysinfo info;
    sysinfo(&info);

    // Print the header
    printf("%s\n", "Running Processes:");
    printf("%s\n", "==================");

    // Get the list of processes
    FILE *fp;
    char line[1024];
    fp = popen("ps -eo pid,user,state,command", "r");
    if (fp == NULL) {
        perror("popen");
        exit(1);
    }

    // Loop through the list of processes
    while (fgets(line, sizeof(line), fp)) {
        // Parse the process information
        int pid, uid;
        char user[1024], state[1024], command[1024];
        sscanf(line, "%d %s %s %s", &pid, user, state, command);

        // Print the process information
        printf("%s%d%s %s%s%s %s%s%s\n", GREEN, pid, RESET, YELLOW, user, RESET, BLUE, state, RESET, command);
    }

    // Close the file
    pclose(fp);
}

// Define the main function
int main() {
    // View the processes
    view_processes();

    return 0;
}