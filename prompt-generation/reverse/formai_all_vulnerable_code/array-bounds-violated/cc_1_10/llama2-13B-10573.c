//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_SIZE 256

struct log_entry {
    char timestamp[20];
    char message[256];
};

int main(void) {
    struct log_entry log[10];
    char buffer[MAX_LOG_SIZE];
    int i, j, k;

    // Initialize log array with empty strings
    for (i = 0; i < 10; i++) {
        log[i].timestamp[0] = '\0';
        log[i].message[0] = '\0';
    }

    // Read log file and store entries in log array
    FILE *log_file = fopen("brave_log.txt", "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    while (fgets(buffer, MAX_LOG_SIZE, log_file) != NULL) {
        // Parse log entry
        for (j = 0; j < MAX_LINE_SIZE; j++) {
            if (buffer[j] == '\n') {
                break;
            }
            log[i].message[j - 1] = buffer[j];
        }

        // Extract timestamp
        for (k = 0; k < 19; k++) {
            if (buffer[k] == ' ') {
                log[i].timestamp[k] = buffer[k];
            }
        }

        // Increment index and check for end of log
        i++;
        if (i == 10) {
            break;
        }
    }

    // Print log entries
    for (i = 0; i < 10; i++) {
        printf("%s %s\n", log[i].timestamp, log[i].message);
    }

    // Close log file
    fclose(log_file);

    return 0;
}