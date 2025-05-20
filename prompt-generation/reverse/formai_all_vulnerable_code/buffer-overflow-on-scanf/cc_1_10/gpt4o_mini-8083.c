//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries(int index);
void deleteEntry();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  // Consume newline character

    switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries(0);
            break;
        case 3:
            deleteEntry();
            break;
        case 4:
            printf("Exiting the diary. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            menu();  // Recursive call to show menu again
            break;
    }
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
    } else {
        printf("Enter your diary entry: ");
        fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
        diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0;  // Remove newline character
        entryCount++;
        printf("Entry added successfully!\n");
    }
    menu();  // Go back to menu
}

void viewEntries(int index) {
    if (index < entryCount) {
        printf("Entry %d: %s\n", index + 1, diary[index].entry);
        viewEntries(index + 1);  // Recursive call to view next entry
    } else {
        printf("No more entries to display.\n");
    }
    menu();  // Go back to menu after displaying the entries
}

void deleteEntry() {
    int index;
    printf("Enter the number of the entry you want to delete: ");
    scanf("%d", &index);
    getchar();  // Consume newline character

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
    } else {
        for (int i = index - 1; i < entryCount - 1; i++) {
            diary[i] = diary[i + 1];  // Shift entries to fill the gap
        }
        entryCount--;
        printf("Entry deleted successfully!\n");
    }
    menu();  // Go back to menu
}