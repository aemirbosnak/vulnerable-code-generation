//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the log file
#define MAX_SIZE 100000

// Define the maximum size of each log entry
#define MAX_ENTRY_SIZE 1024

// Define the structure of a log entry
typedef struct {
    char timestamp[20];
    char level[10];
    char message[MAX_ENTRY_SIZE];
} LogEntry;

// Function to open the log file
FILE* openLogFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening log file: %s\n", filename);
        exit(1);
    }
    return file;
}

// Function to read a log entry from the file
LogEntry readLogEntry(FILE* file) {
    LogEntry entry;
    fscanf(file, "%s %s %[^\n]s", entry.timestamp, entry.level, entry.message);
    return entry;
}

// Function to print a log entry
void printLogEntry(LogEntry entry) {
    printf("%s %s: %s\n", entry.timestamp, entry.level, entry.message);
}

// Function to search for a specific log entry
int searchLogEntry(FILE* file, char* searchTerm) {
    int count = 0;
    char line[MAX_ENTRY_SIZE];
    while (fgets(line, MAX_ENTRY_SIZE, file)!= NULL) {
        LogEntry entry = readLogEntry(file);
        if (strstr(entry.message, searchTerm)!= NULL) {
            printLogEntry(entry);
            count++;
        }
    }
    return count;
}

int main() {
    FILE* file = openLogFile("logfile.txt");
    char searchTerm[MAX_ENTRY_SIZE];
    printf("Enter a search term: ");
    scanf("%s", searchTerm);
    int count = searchLogEntry(file, searchTerm);
    if (count == 0) {
        printf("No results found.\n");
    }
    fclose(file);
    return 0;
}