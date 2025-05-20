//FormAI DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

// Define global variables
char diary[MAX_ENTRIES][MAX_ENTRY_LENGTH];
int num_entries = 0;

// Function declarations
void addEntry();
void viewEntry();
void deleteEntry();

int main() {
    int choice;
    // Seed random number generator for timestamp
    srand(time(NULL));
    // Main menu loop
    while (1) {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void addEntry() {
    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry (max %d characters):\n", MAX_ENTRY_LENGTH);
    fflush(stdin); // clear input buffer
    fgets(entry, MAX_ENTRY_LENGTH, stdin); // read input
    // Add timestamp to entry
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[100];
    strftime(timestamp, sizeof(timestamp), "%c", tm);
    sprintf(diary[num_entries], "%s - %s", timestamp, entry);
    num_entries++;
    printf("Entry added successfully\n");
}

void viewEntry() {
    int i;
    if (num_entries == 0) {
        printf("No entries in diary\n");
        return;
    }
    printf("Enter the entry number to view (1 - %d):\n", num_entries);
    scanf("%d", &i);
    if (i < 1 || i > num_entries) {
        printf("Invalid entry number\n");
        return;
    }
    printf("%s\n", diary[i - 1]); // Print diary entry
}

void deleteEntry() {
    int i, j;
    if (num_entries == 0) {
        printf("No entries in diary\n");
        return;
    }
    printf("Enter the entry number to delete (1 - %d):\n", num_entries);
    scanf("%d", &i);
    if (i < 1 || i > num_entries) {
        printf("Invalid entry number\n");
        return;
    }
    // Shift entries to delete ith entry
    for (j = i; j < num_entries; j++) {
        strcpy(diary[j - 1], diary[j]);
    }
    num_entries--;
    printf("Entry deleted successfully\n");
}