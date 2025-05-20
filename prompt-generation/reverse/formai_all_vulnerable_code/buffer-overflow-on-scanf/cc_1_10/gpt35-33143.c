//FormAI DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_ENTRIES 100

void displayMenu() {
    printf("1. Add entry\n");
    printf("2. List entries\n");
    printf("3. Delete entry\n");
    printf("4. Exit\n");
    printf("Enter option (1-4): ");
}

void addEntry(char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH], int *numEntries) {
    printf("Enter diary entry (max %d characters):\n", MAX_ENTRY_LENGTH);
    getchar(); // clear input buffer
    fgets(entries[*numEntries], MAX_ENTRY_LENGTH, stdin);
    (*numEntries)++;
    printf("Entry added successfully!\n\n");
}

void printEntries(char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH], int numEntries) {
    if (numEntries == 0) {
        printf("No entries found.\n\n");
        return;
    }
    printf("Displaying %d entries:\n\n", numEntries);
    for (int i = 0; i < numEntries; i++) {
        printf("%d. %s", i + 1, entries[i]);
    }
    printf("\n");
}

void deleteEntry(char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH], int *numEntries) {
    printEntries(entries, *numEntries);
    if (*numEntries == 0) {
        return;
    }
    printf("Enter index of entry to delete (1-%d): ", *numEntries);
    int index;
    scanf("%d", &index);
    if (index < 1 || index > *numEntries) {
        printf("Invalid index!\n\n");
        return;
    }
    for (int i = index - 1; i < *numEntries - 1; i++) {
        strcpy(entries[i], entries[i + 1]);
    }
    (*numEntries)--;
    printf("Entry deleted successfully!\n\n");
}

int main() {
    char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH];
    int numEntries = 0;
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(entries, &numEntries);
                break;
            case 2:
                printEntries(entries, numEntries);
                break;
            case 3:
                deleteEntry(entries, &numEntries);
                break;
            case 4:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}