//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    int start_time;
    char* boot_time = "00:00:00";
    char prev_time[9] = "";
    char curr_time[9] = "";
    char* buffer;
    size_t bufsize = 32;
    FILE * fp;
    int i;

    // Record start time of program
    start_time = time(NULL);

    // Open file containing boot time
    fp = fopen("/var/log/boot.log", "r");
    if (fp == NULL) {
        printf("Error: boot.log file could not be opened\n");
        exit(EXIT_FAILURE);
    }

    // Read boot time from file
    getline(&buffer, &bufsize, fp);

    // Close file
    fclose(fp);

    // Parse boot time into hours, minutes, seconds
    sscanf(buffer, "%s", boot_time);
    for (i = 0; i < 2; i++) {
        curr_time[i] = boot_time[i];
    }
    curr_time[2] = ':';
    for (i = 3; i < 5; i++) {
        curr_time[i] = boot_time[i-1];
    }
    curr_time[5] = ':';
    for (i = 6; i < 8; i++) {
        curr_time[i] = boot_time[i-2];
    }

    // Loop until current and previous boot times match
    while (strcmp(prev_time, curr_time) != 0) {
        // Store previous boot time
        strcpy(prev_time, curr_time);

        // Delay for 1 second
        sleep(1);

        // Update boot time
        fp = fopen("/var/log/boot.log", "r");
        if (fp == NULL) {
            printf("Error: boot.log file could not be opened\n");
            exit(EXIT_FAILURE);
        }
        getline(&buffer, &bufsize, fp);
        fclose(fp);
        sscanf(buffer, "%s", boot_time);
        for (i = 0; i < 2; i++) {
            curr_time[i] = boot_time[i];
        }
        curr_time[2] = ':';
        for (i = 3; i < 5; i++) {
            curr_time[i] = boot_time[i-1];
        }
        curr_time[5] = ':';
        for (i = 6; i < 8; i++) {
            curr_time[i] = boot_time[i-2];
        }
    }

    // Calculate boot time in seconds
    int end_time = time(NULL);
    int total_time = end_time - start_time;

    // Display boot time
    printf("System booted in %d seconds", total_time);

    return 0;
}