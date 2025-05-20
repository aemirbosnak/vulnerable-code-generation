//FormAI DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to represent a log entry
typedef struct {
    char type[10];
    char message[100];
} LogEntry;

//Function to parse a line from the log file and create a log entry
LogEntry parseLine(char* line) {
    LogEntry entry;
    sscanf(line, "[%[^]]] %s\n", entry.type, entry.message);
    return entry;
}

//Function to analyze the log file and print out the number of errors and warnings
void analyzeLog(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if(file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    int numErrors = 0;
    int numWarnings = 0;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&line, &len, file)) != -1) {
        LogEntry entry = parseLine(line);
        if(strcmp(entry.type, "ERROR") == 0) {
            numErrors++;
        } else if(strcmp(entry.type, "WARNING") == 0) {
            numWarnings++;
        }
    }

    printf("Number of errors: %d\n", numErrors);
    printf("Number of warnings: %d\n", numWarnings);

    free(line);
    fclose(file);
}

//Main function
int main() {
    analyzeLog("example.log");
    return 0;
}