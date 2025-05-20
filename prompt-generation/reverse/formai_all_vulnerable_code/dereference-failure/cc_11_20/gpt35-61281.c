//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//define constants for our system
#define MAX_LOG_ENTRIES 1000
#define THRESHOLD 10
#define MAX_FAILED_ATTEMPTS 3

//create a struct to represent a log entry
typedef struct {
    char username[20];
    char ip_address[16];
    time_t timestamp;
    bool success;
} LogEntry;

//function to calculate the time difference between two timestamps in seconds
double diffTime(time_t start, time_t end) {
    return difftime(end, start);
}

int main() {
    int numEntries = 0;
    LogEntry log[MAX_LOG_ENTRIES];
    int failedAttempts = 0;
    char lastIP[16];
    bool flagged = false;
    
    //read from log file and store entries in array
    FILE* logFile = fopen("log.txt", "r");
    char line[50];
    while(fgets(line, 50, logFile) != NULL) {
        //parse log entry and store in struct
        char* token;
        token = strtok(line, ",");
        strcpy(log[numEntries].username, token);
        token = strtok(NULL, ",");
        strcpy(log[numEntries].ip_address, token);
        token = strtok(NULL, ",");
        log[numEntries].timestamp = atol(token);
        token = strtok(NULL, ",");
        log[numEntries].success = (strcmp(token, "success\n") == 0) ? true : false;
        numEntries++;
    }
    fclose(logFile);
    
    //iterate through log entries and detect intrusion attempts
    for(int i = 0; i < numEntries; i++) {
        //check for repeated failed attempts from same IP
        if(!log[i].success) {
            if(strcmp(log[i].ip_address, lastIP) == 0) {
                failedAttempts++;
                if(failedAttempts >= MAX_FAILED_ATTEMPTS) {
                    printf("Intrusion attempt detected from IP address %s\n", log[i].ip_address);
                    flagged = true;
                }
            }
            else {
                failedAttempts = 1;
                strcpy(lastIP, log[i].ip_address);
            }
        }
        
        //check for repeated attempts from same username and IP within threshold time
        for(int j = i + 1; j < numEntries; j++) {
            if(strcmp(log[i].username, log[j].username) == 0 && strcmp(log[i].ip_address, log[j].ip_address) == 0) {
                if(diffTime(log[i].timestamp, log[j].timestamp) <= THRESHOLD && log[i].success && !log[j].success) {
                    printf("Intrusion attempt detected from IP address %s and username %s\n", log[i].ip_address, log[i].username);
                    flagged = true;
                }
            }
        }
    }
    
    //write flagged entries to a new log file
    FILE* flaggedFile = fopen("flagged.txt", "w");
    fprintf(flaggedFile, "Flagged entries:\n\n");
    for(int i = 0; i < numEntries; i++) {
        if(!log[i].success && strcmp(log[i].ip_address, lastIP) == 0) {
            fprintf(flaggedFile, "%s,%s,%ld,%s", log[i].username, log[i].ip_address, log[i].timestamp, (log[i].success) ? "success\n" : "failed\n");
        }
        else {
            for(int j = i + 1; j < numEntries; j++) {
                if(strcmp(log[i].username, log[j].username) == 0 && strcmp(log[i].ip_address, log[j].ip_address) == 0) {
                    if(diffTime(log[i].timestamp, log[j].timestamp) <= THRESHOLD && log[i].success && !log[j].success) {
                        fprintf(flaggedFile, "%s,%s,%ld,%s", log[i].username, log[i].ip_address, log[i].timestamp, (log[i].success) ? "success\n" : "failed\n");
                        break;
                    }
                }
            }
        }
    }
    fclose(flaggedFile);
    
    //print final result
    if(flagged) {
        printf("Intrusion detection system flagged suspicious activity - check flagged.txt for details\n");
    }
    else {
        printf("No suspicious activity detected\n");
    }
    
    return 0;
}