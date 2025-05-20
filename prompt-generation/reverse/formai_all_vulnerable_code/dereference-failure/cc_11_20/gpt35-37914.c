//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_LENGTH 100

int main(void) {
    int log_count = 0;
    char **log_entries = malloc(MAX_LOG_ENTRIES * sizeof(char*));
    
    // Read log entries from file
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to read log file.\n");
        return 1;
    }
    char line[MAX_LOG_LENGTH];
    while (fgets(line, MAX_LOG_LENGTH, fp) != NULL) {
        if (log_count >= MAX_LOG_ENTRIES) {
            printf("Error: Maximum log entries reached.\n");
            break;
        }
        log_entries[log_count] = malloc(MAX_LOG_LENGTH * sizeof(char));
        strcpy(log_entries[log_count], line);
        log_count++;
    }
    fclose(fp);
    
    // Count number of entries and errors
    int entry_count = 0;
    int error_count = 0;
    for (int i = 0; i < log_count; i++) {
        // Check if entry contains an error
        if (strstr(log_entries[i], "ERROR") != NULL) {
            error_count++;
        }
        entry_count++;
    }
    
    // Print report
    printf("Log Analysis Report\n");
    printf("====================\n");
    printf("Total Entries: %d\n", entry_count);
    printf("Error Entries: %d\n", error_count);
    printf("Error Percentage: %.2f%%\n", (float)error_count/entry_count * 100);
    
    // Find top 5 error entries
    printf("\nTop 5 Error Entries\n");
    printf("===================\n");
    int error_index[MAX_LOG_ENTRIES];
    for (int i = 0; i < log_count; i++) {
        if (strstr(log_entries[i], "ERROR") != NULL) {
            error_index[error_count-1] = i;
            error_count--;
        }
        if (error_count == 0) {
            break;
        }
    }
    for (int i = log_count-1; i >= 0; i--) {
        for (int j = 0; j < error_count; j++) {
            if (i == error_index[j]) {
                printf("%s", log_entries[i]);
                error_count--;
                if (error_count == 0) {
                    break;
                }
            }
        }
        if (error_count == 0) {
            break;
        }
    }
    
    // Free memory
    for (int i = 0; i < log_count; i++) {
        free(log_entries[i]);
    }
    free(log_entries);
    
    return 0;
}