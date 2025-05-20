//FormAI DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the log file path.
#define LOG_FILE_PATH "system_events.log"

// Function to generate random number in range 0-99.
int randomInRange() {
    return rand() % 100;
}

int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Open the log file in append mode.
    FILE* log_file = fopen(LOG_FILE_PATH, "a"); 

    if (log_file != NULL) {
        // Get current time.
        time_t current_time = time(NULL);

        // Convert current time to local time.
        struct tm* local_time = localtime(&current_time);

        // Print log file header.
        fprintf(log_file, "\n\n##############################################\n");
        fprintf(log_file, "#             System Event Logger             #\n");
        fprintf(log_file, "#            %02d/%02d/%4d %02d:%02d:%02d            #\n",
            local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900,
            local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
        fprintf(log_file, "##############################################\n\n");

        // Generate and log system events 10 times.
        for (int i = 0; i < 10; i++) {

            int event_type = randomInRange();

            switch (event_type) {
                case 0: 
                    fprintf(log_file, "System Alert: Critical Temperature Detected!\n");
                    break;
                case 1: 
                    fprintf(log_file, "System Alert: Memory Usage High!\n");
                    break;
                case 2:
                    fprintf(log_file, "System Alert: Disk Space Low!\n");
                    break;
                case 3: 
                    fprintf(log_file, "System Alert: Network Connection Lost!\n");
                    break;
                default:
                    fprintf(log_file, "System Event: No issues detected.\n");
            }
        }

        // Close the log file.
        fclose(log_file);
    }
    else {
        // Log error if unable to open the log file.
        fprintf(stderr, "Error opening the log file.\n");
    }

    return 0;
}