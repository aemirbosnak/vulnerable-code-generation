//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void printColored(const char *text, const char *color) {
    printf("%s%s%s", color, text, "\033[0m");
}

void printHeader() {
    printf("\n");
    printColored("----------------------------------------------------\n", "\033[1;34m");
    printColored("| PID  |    TTY    |     TIME     | COMMAND          |\n", "\033[1;32m");
    printColored("----------------------------------------------------\n", "\033[1;34m");
}

void printProcessInfo(int pid, const char *tty, const char *time, const char *command) {
    printf("| %-4d | %-9s | %-12s | %-16s |\n", pid, tty, time, command);
}

void displayProcesses() {
    FILE *fp;
    char line[256];

    /* Open the process list */
    fp = popen("ps -eo pid,tty,time,comm --sort pid", "r");
    if (fp == NULL) {
        printColored("Error opening command!\n", "\033[1;31m");
        exit(1);
    }

    printHeader();
    
    // Skip the first line (the header from ps command)
    fgets(line, sizeof(line), fp);
    
    /* Read each line of the output */
    while (fgets(line, sizeof(line), fp) != NULL) {
        int pid;
        char tty[10];
        char time[10];
        char command[50];

        // Parse the fields from the line
        sscanf(line, "%d %s %s %s", &pid, tty, time, command);

        // Print the process information with formatted data
        printProcessInfo(pid, tty, time, command);
    }
    
    printColored("----------------------------------------------------\n", "\033[1;34m");
    pclose(fp);
}

int main() {
    printColored("***** Artistic System Process Viewer *****\n", "\033[1;35m");
    while (1) {
        displayProcesses();
        sleep(2); // Refresh every 2 seconds
        // Clear the console
        printf("\033[H\033[J");
    }
    return 0;
}