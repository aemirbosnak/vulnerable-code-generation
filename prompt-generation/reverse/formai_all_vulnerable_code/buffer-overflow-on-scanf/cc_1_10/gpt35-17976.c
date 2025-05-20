//FormAI DATASET v1.0 Category: System event logger ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "system_log.txt"

void log_to_file(char *message) {
    time_t current_time;
    char *time_string;
    FILE *fw;

    current_time = time(NULL);  // get current time in seconds
    time_string = ctime(&current_time);  // convert time to string format

    // open log file in append mode
    fw = fopen(LOG_FILE, "a");

    // print timestamp and message to log file
    fprintf(fw, "%s%s\n", time_string, message);

    // close log file
    fclose(fw);
}

int main(void) {
    char command[50];

    printf("Enter a command: ");
    scanf("%s", command);

    // log command to file before executing
    log_to_file(command);

    // paranoid checks before executing command
    // check if command contains forbidden keywords
    if (strstr(command, "rm") != NULL || strstr(command, "format") != NULL ||
        strstr(command, "shutdown") != NULL || strstr(command, "reboot") != NULL) {
        printf("Command contains forbidden keywords. Aborting...\n");

        // log abortion reason to file
        log_to_file("Command contains forbidden keywords. Aborting...");
        return 1;
    }

    // run command
    system(command);

    // log command success to file
    log_to_file("Command executed successfully.");

    return 0;
}