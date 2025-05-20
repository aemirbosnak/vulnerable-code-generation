//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAX_LOG_SIZE 10000

struct log_entry {
    char timestamp[20];
    char client_ip[20];
    char request_method[20];
    char request_uri[100];
    int response_code;
    char response_reason[100];
};

int main(void) {
    char log_file[] = "/var/log/access.log";
    char line[MAX_LENGTH];
    struct log_entry entry;
    int count = 0;

    // Open the log file
    FILE *file = fopen(log_file, "r");
    if (file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    // Read the log file line by line
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        // Parse the log line
        sscanf(line, "%20s %20s %100s %d %100s",
               entry.timestamp, entry.client_ip, entry.request_uri, &entry.response_code, entry.response_reason);

        // Check if the request was successful
        if (entry.response_code == 200) {
            // Print the successful request
            printf("Request successful: %s %s %s\n", entry.timestamp, entry.client_ip, entry.request_uri);
        } else {
            // Print the failed request
            printf("Request failed: %s %s %s (%d %s)\n", entry.timestamp, entry.client_ip, entry.request_uri, entry.response_code, entry.response_reason);
        }

        // Increment the count
        count++;

        // Check if we've reached the maximum log size
        if (count >= MAX_LOG_SIZE) {
            break;
        }
    }

    // Close the log file
    fclose(file);

    // Print the final statistics
    printf("Total requests: %d\n", count);

    return 0;
}