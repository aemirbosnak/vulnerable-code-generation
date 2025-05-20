//FormAI DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant variables for maximum line length and maximum number of logs
#define MAX_LINE_LENGTH 200
#define MAX_LOGS 1000

int main() {
    // Declare file pointer and open input file in read mode
    FILE *fp;
    fp = fopen("log.txt", "r");

    // Declare variables for line reading
    char line[MAX_LINE_LENGTH];

    // Declare variables for log parsing
    char timestamp[20];
    char message[100];
    int log_count = 0;

    // Declare arrays for storing parsed logs
    char timestamps[MAX_LOGS][20];
    char messages[MAX_LOGS][100];

    // Read each line of the file until the end of file is reached
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Parse the timestamp and message from each line
        sscanf(line, "%s %[^\n]", timestamp, message);

        // Store the parsed timestamp and message in their respective arrays
        strcpy(timestamps[log_count], timestamp);
        strcpy(messages[log_count], message);

        // Increment the log count
        log_count++;
    }

    // Close the input file
    fclose(fp);

    // Print the number of logs parsed
    printf("Parsed %d logs:\n", log_count);

    // Loop through each parsed log and print its timestamp and message
    for (int i = 0; i < log_count; i++) {
        printf("%s: %s\n", timestamps[i], messages[i]);
    }

    // Return success
    return 0;
}