//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_SIZE 1024

typedef struct DiaryEntry {
    char text[MAX_ENTRY_SIZE];
    struct DiaryEntry* next;
} DiaryEntry;

DiaryEntry* head = NULL;

// Function to create a new diary entry
DiaryEntry* createEntry(const char* text) {
    DiaryEntry* newEntry = (DiaryEntry*)malloc(sizeof(DiaryEntry));
    if (newEntry == NULL) {
        printf("Failed to allocate memory for a new diary entry.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newEntry->text, text, MAX_ENTRY_SIZE);
    newEntry->text[MAX_ENTRY_SIZE - 1] = '\0'; // Ensure NULL termination
    newEntry->next = NULL;
    return newEntry;
}

// Function to add an entry to the diary
void addEntry() {
    char buffer[MAX_ENTRY_SIZE];
    printf("Enter your diary entry (max %d characters):\n", MAX_ENTRY_SIZE - 1);
    getchar(); // Consume newline character after previous input
    fgets(buffer, MAX_ENTRY_SIZE, stdin);
    // Remove newline character from buffer
    buffer[strcspn(buffer, "\n")] = 0;

    DiaryEntry* newEntry = createEntry(buffer);
    newEntry->next = head; // Insert at the beginning
    head = newEntry;
    printf("Diary entry added successfully!\n");
}

// Function to view diary entries
void viewEntries() {
    if (head == NULL) {
        printf("No diary entries found.\n");
        return;
    }
    DiaryEntry* current = head;
    int count = 1;
    printf("Your Diary Entries:\n");
    while (current != NULL) {
        printf("Entry %d: %s\n", count++, current->text);
        current = current->next;
    }
}

// Function to free all diary entries
void freeEntries() {
    DiaryEntry* current = head;
    DiaryEntry* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n");
    printf("**** Digital Diary Menu ****\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Exit\n");
    printf("****************************\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                freeEntries();
                printf("Exiting the Diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please select again.\n");
                break;
        }
    }
    return 0;
}