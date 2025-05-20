//FormAI DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
#include<stdio.h>

#define MAX_LOG_ENTRIES 1000 // maximum number of log entries to read

struct LogEntry {
    char timestamp[20]; // e.g. "2021-08-10 13:45:32"
    char message[256]; // log message content
    int severity; // log severity level, 1 (low) to 10 (high)
};

int main() {
    FILE* fp; // file pointer to the log file
    struct LogEntry log_entries[MAX_LOG_ENTRIES]; // array to store log entries
    int num_entries = 0;
    
    fp = fopen("log.txt", "r"); // open the log file for reading
    
    if(fp == NULL) { // check if the file opened successfully
        printf("Error opening file");
        return 0; // exit the program if there was an error
    }
    
    // read log entries until the end of file or maximum number of entries reached
    while(!feof(fp) && num_entries < MAX_LOG_ENTRIES) {
        fgets(log_entries[num_entries].timestamp, 20, fp); // read timestamp string
        fgets(log_entries[num_entries].message, 256, fp); // read log message string
        fscanf(fp, "%d", &log_entries[num_entries].severity); // read severity integer
        fgetc(fp); // consume end-of-line character
        
        num_entries++; // increment number of log entries read
    }
    
    fclose(fp); // close the file
    
    // analyze log entries for errors with severity greater than or equal to 8
    printf("Error log entries:\n");
    for(int i = 0; i < num_entries; i++) {
        if(log_entries[i].severity >= 8) {
            printf("%s - %s\n", log_entries[i].timestamp, log_entries[i].message);
        }
    }

    // analyze log entries for warnings with severity between 5 and 7 inclusive
    printf("Warning log entries:\n");
    for(int i = 0; i < num_entries; i++) {
        if(log_entries[i].severity >= 5 && log_entries[i].severity <= 7) {
            printf("%s - %s\n", log_entries[i].timestamp, log_entries[i].message);
        }
    }
    
    return 0; // exit the program with success
}