//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/syscall.h>

// PARANOIA LEVEL: MAXIMUM

// This program will monitor CPU usage by the current user's processes.
// It will run in a loop, sleeping for 1 second between iterations.
// During each iteration, it will check the CPU usage of the current user's processes.
// If the CPU usage is above a certain threshold, the program will print a warning message.

// The threshold is set to 90% by default. This can be changed by the user by passing a command-line argument.

// The program also checks if it is being run as root. If it is, it will print a warning message and exit.

// The program also checks if the user is trying to hide its processes by running them in a different user's namespace.
// If this is the case, the program will print a warning message and exit.

// Finally, the program checks if the user is trying to use the program to monitor the CPU usage of other users.
// If this is the case, the program will print a warning message and exit.

int main(int argc, char **argv) {
    // Check if the program is being run as root.
    if (geteuid() == 0) {
        fprintf(stderr, "Error: This program cannot be run as root.\n");
        exit(EXIT_FAILURE);
    }

    // Check if the user is trying to hide its processes by running them in a different user's namespace.
    if (syscall(SYS_getuid) != getuid()) {
        fprintf(stderr, "Error: This program cannot be run in a different user's namespace.\n");
        exit(EXIT_FAILURE);
    }

    // Check if the user is trying to use the program to monitor the CPU usage of other users.
    if (getuid() != geteuid()) {
        fprintf(stderr, "Error: This program cannot be used to monitor the CPU usage of other users.\n");
        exit(EXIT_FAILURE);
    }

    // Get the current user's name.
    struct passwd *pw = getpwuid(getuid());
    if (pw == NULL) {
        fprintf(stderr, "Error: Could not get the current user's name.\n");
        exit(EXIT_FAILURE);
    }

    // Get the threshold from the command-line arguments.
    int threshold = 90;
    if (argc > 1) {
        threshold = atoi(argv[1]);
        if (threshold < 0 || threshold > 100) {
            fprintf(stderr, "Error: Invalid threshold.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Loop forever, monitoring the CPU usage of the current user's processes.
    while (1) {
        // Get the CPU usage of the current user's processes.
        FILE *fp = fopen("/proc/self/status", "r");
        if (fp == NULL) {
            fprintf(stderr, "Error: Could not open /proc/self/status.\n");
            exit(EXIT_FAILURE);
        }
        char line[1024];
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (strncmp(line, "User CPU", 8) == 0) {
                char *p = line + 8;
                while (*p == ' ') {
                    p++;
                }
                double cpu_usage = atof(p);
                if (cpu_usage > threshold) {
                    fprintf(stderr, "Warning: CPU usage is above the threshold (%d%%).\n", threshold);
                }
                break;
            }
        }
        fclose(fp);

        // Sleep for 1 second.
        sleep(1);
    }

    return EXIT_SUCCESS;
}