//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#define LOG_FILE "system_monitor.log"
#define SLEEP_INTERVAL 2

void log_system_usage(FILE *logfile) {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    // Getting memory usage
    long memory_usage = usage.ru_maxrss; // in kilobytes

    // Getting CPU time used
    long user_time = usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;
    long sys_time = usage.ru_stime.tv_sec * 1000000 + usage.ru_stime.tv_usec;

    // Log to file
    fprintf(logfile, "Memory Usage: %ld KB, User CPU Time: %ld µs, System CPU Time: %ld µs\n",
            memory_usage, user_time, sys_time);
    fflush(logfile);
}

void display_help() {
    printf("System Monitor - Command Line Tool\n");
    printf("Commands:\n");
    printf("   log      - Log current system usage\n");
    printf("   exit     - Exit the program\n");
    printf("   help     - Display this help message\n");
}

int main() {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return EXIT_FAILURE;
    }

    char command[10];

    printf("Welcome to the System Monitor!\n");
    printf("Type 'help' for available commands.\n");

    while (1) {
        printf("Enter command: ");
        scanf("%9s", command);

        if (strcmp(command, "log") == 0) {
            log_system_usage(logfile);
            printf("System usage logged successfully.\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the System Monitor.\n");
            break;
        } else if (strcmp(command, "help") == 0) {
            display_help();
        } else {
            printf("Unknown command: %s\n", command);
            display_help();
        }

        sleep(SLEEP_INTERVAL);
    }

    fclose(logfile);
    return EXIT_SUCCESS;
}