//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_STRING_LENGTH 100

// Structure to hold each diary entry
typedef struct {
    time_t timestamp;
    char entry[MAX_STRING_LENGTH];
} DiaryEntry;

// Function to add a new diary entry to the digital diary
void addEntry(DiaryEntry *diary, int *entryCount) {
    time_t currentTime = time(NULL);
    char newEntry[MAX_STRING_LENGTH];

    printf("Enter a new diary entry: ");
    fgets(newEntry, MAX_STRING_LENGTH, stdin);

    // Assign the new entry to the next available index and increment the entry count
    strcpy(diary[*entryCount].entry, newEntry);
    diary[*entryCount].timestamp = currentTime;
    (*entryCount)++;

    printf("Entry added successfully.\n\n");
}

// Function to print all diary entries in reverse chronological order
void printEntries(DiaryEntry *diary, int entryCount) {
    printf("Diary Entries:\n\n");

    for (int i = entryCount-1; i >= 0; i--) {
        char timeString[30];
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&diary[i].timestamp));
        printf("[%s] %s", timeString, diary[i].entry);
    }

    printf("\n");
}

int main() {
    int entryCount = 0;
    DiaryEntry diary[MAX_ENTRIES];

    while (1) {
        printf("Enter 1 to add a new diary entry.\n");
        printf("Enter 2 to print all diary entries.\n");
        printf("Enter 3 to exit the program.\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            getchar(); // clear input buffer
            addEntry(diary, &entryCount);
        } else if (choice == 2) {
            printEntries(diary, entryCount);
        } else if (choice == 3) {
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}