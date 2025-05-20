//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000 // Maximum number of diary entries
#define MAX_ENTRY_LENGTH 1000 // Maximum length of a diary entry (in characters)

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES]; // The digital diary
int numEntries = 0; // Number of entries in the diary

// Function to add a new diary entry
void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    printf("Enter your diary entry:\n");
    fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
    diary[numEntries].timestamp = now;
    numEntries++;
}

// Function to display all diary entries
void displayEntries() {
    printf("\nDiary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].entry);
    }
}

// Function to search for a specific diary entry
void searchEntry() {
    char search[MAX_ENTRY_LENGTH];
    printf("Enter search query:\n");
    fgets(search, MAX_ENTRY_LENGTH, stdin);

    for (int i = 0; i < numEntries; i++) {
        if (strstr(diary[i].entry, search)!= NULL) {
            printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n");
    printf("Press 1 to add an entry.\n");
    printf("Press 2 to display all entries.\n");
    printf("Press 3 to search for an entry.\n");
    printf("Press 0 to exit.\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}