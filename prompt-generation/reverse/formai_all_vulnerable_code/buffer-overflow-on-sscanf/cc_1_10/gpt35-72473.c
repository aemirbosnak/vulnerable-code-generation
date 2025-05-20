//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_LINE_LENGTH 1024
 
typedef struct log_entry {
    char date[20];
    char time[20];
    char component[50];
    char message[MAX_LINE_LENGTH];
} LogEntry;
 
void print_log_entry(LogEntry entry) {
    printf("[%s %s] %s: %s\n", entry.date, entry.time, entry.component, entry.message);
}
 
int main(int argc, char *argv[]) {
    // Open log file for reading
    FILE *file;
    file = fopen("example.log", "r");
    if (file == NULL) {
        printf("Error: Unable to open log file!\n");
        exit(1);
    }
 
    // Prepare buffer
    char buffer[MAX_LINE_LENGTH];
    memset(buffer, 0, MAX_LINE_LENGTH);
    int line_count = 0;
 
    // Read each line of the log file
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        line_count++;
 
        // Split line into parts (date, time, component, message)
        LogEntry entry;
        sscanf(buffer, "[%[^]]] [%[^]]] %[^:]: %s", entry.date, entry.time, entry.component, entry.message);
 
        // Print log entry
        print_log_entry(entry);
    }
 
    // Close file
    fclose(file);
 
    // Print total number of lines read
    printf("\nTotal number of lines: %d\n", line_count);
 
    return 0;
}