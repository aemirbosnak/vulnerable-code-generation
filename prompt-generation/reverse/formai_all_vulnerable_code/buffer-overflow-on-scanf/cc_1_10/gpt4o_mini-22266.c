//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a log entry in our medieval logbook.
typedef struct LogEntry {
    char date[11]; // Format: YYYY-MM-DD
    char scribe[50];
    char message[256];
} LogEntry;

// Function to create a new log entry
LogEntry createLogEntry(char *scribe, char *message) {
    LogEntry newEntry;
    
    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newEntry.date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    strcpy(newEntry.scribe, scribe);
    strcpy(newEntry.message, message);
    
    return newEntry;
}

// Function to print a log entry elegantly as a medieval scroll
void printLogEntry(LogEntry entry) {
    printf("=========================================\n");
    printf(" Date: %s\n", entry.date);
    printf(" Scribe: %s\n", entry.scribe);
    printf(" Message: %s\n", entry.message);
    printf("=========================================\n");
}

// Function to read log from a file and display it
void readLogFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Alas! The logbook was not found!\n");
        return;
    }

    LogEntry entry;
    printf("\n--- The Grand Logbook ---\n");
    while (fscanf(file, "%10s %49s %255[^\n]", entry.date, entry.scribe, entry.message) != EOF) {
        printLogEntry(entry);
    }
    fclose(file);
}

// Function to append new log entry to the log file
void appendLogToFile(char *filename, LogEntry entry) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Alas! We could not open the logbook for writing!\n");
        return;
    }
    
    fprintf(file, "%s %s %s\n", entry.date, entry.scribe, entry.message);
    fclose(file);
}

// Main function
int main() {
    char filename[] = "medieval_log.txt";
    
    printf("Welcome to the Medieval Logbook!\n");
    printf("1. Add new log entry\n");
    printf("2. View the logbook\n");
    printf("3. Exit\n");
    
    int choice;
    while (1) {
        printf("Choose thy fate: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char scribe[50];
            char message[256];

            printf("Who scribed this entry? ");
            scanf("%s", scribe);
            printf("What message dost thou wish to record? ");
            getchar(); // Consume the newline character
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0'; // Remove newline from message
            
            LogEntry newEntry = createLogEntry(scribe, message);
            appendLogToFile(filename, newEntry);
            printf("The log has been updated with thine entry.\n");
        } else if (choice == 2) {
            readLogFromFile(filename);
        } else if (choice == 3) {
            printf("Farewell, noble seeker of knowledge!\n");
            break;
        } else {
            printf("Pray, choose a valid option!\n");
        }
    }
    
    return 0;
}