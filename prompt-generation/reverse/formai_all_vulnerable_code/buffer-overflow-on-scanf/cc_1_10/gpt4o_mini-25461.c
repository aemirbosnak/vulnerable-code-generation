//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE 100
#define MAX_CONTENT 500
#define FILE_NAME "diary_entries.txt"

// Structure for a diary entry
typedef struct {
    char title[MAX_TITLE];
    char content[MAX_CONTENT];
} DiaryEntry;

// Function to add a diary entry
void add_entry() {
    DiaryEntry entry;
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Could not open diary file");
        return;
    }
    
    printf("Enter title: ");
    fgets(entry.title, MAX_TITLE, stdin);
    entry.title[strcspn(entry.title, "\n")] = 0; // Remove newline character

    printf("Enter content: ");
    fgets(entry.content, MAX_CONTENT, stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // Remove newline character

    fprintf(file, "%s\n%s\n", entry.title, entry.content);
    fclose(file);
    printf("Entry added successfully!\n");
}

// Function to display all diary entries
void view_entries() {
    char line[1024];
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Could not open diary file");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to delete a diary entry
void delete_entry() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Could not open diary file");
        return;
    }

    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    // Reading all entries into memory
    while (fgets(entries[count].title, MAX_TITLE, file) && fgets(entries[count].content, MAX_CONTENT, file)) {
        entries[count].title[strcspn(entries[count].title, "\n")] = 0;
        entries[count].content[strcspn(entries[count].content, "\n")] = 0;
        count++;
    }
    fclose(file);

    // Displaying entries for selection
    printf("\n--- Select Entry to Delete ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, entries[i].title);
    }

    int choice;
    printf("Enter entry number to delete: ");
    scanf("%d", &choice);
    getchar(); // consume newline character

    if (choice < 1 || choice > count) {
        printf("Invalid choice.\n");
        return;
    }

    // Writing remaining entries to a new temporary file
    file = fopen(FILE_NAME, "w");
    for (int i = 0; i < count; i++) {
        if (i != choice - 1) { // skip the chosen entry
            fprintf(file, "%s\n%s\n", entries[i].title, entries[i].content);
        }
    }
    fclose(file);
    printf("Entry deleted successfully!\n");
}

// Main menu function
void menu() {
    int option;
    do {
        printf("\n--- Digital Diary Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // consume newline character

        switch (option) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);
}

// Main function
int main() {
    menu();
    return 0;
}