//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char title[MAX_LENGTH];
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries!\n");
        return;
    }
    
    getchar(); // Clear the buffer
    printf("Enter the title of your entry: ");
    fgets(diary[entry_count].title, MAX_LENGTH, stdin);
    strtok(diary[entry_count].title, "\n"); // Remove newline

    printf("Write your diary entry:\n");
    fgets(diary[entry_count].content, MAX_LENGTH, stdin);
    strtok(diary[entry_count].content, "\n"); // Remove newline

    entry_count++;
    printf("Diary entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("Your diary is empty! Time to write something!\n");
        return;
    }

    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n\n", diary[i].content);
    }
}

void delete_entry() {
    if (entry_count == 0) {
        printf("Your diary is empty! No entries to delete.\n");
        return;
    }

    int index;
    printf("Which entry number do you want to delete? (1 to %d): ", entry_count);
    scanf("%d", &index);
    
    if (index < 1 || index > entry_count) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Diary entry deleted successfully!\n");
}

void display_menu() {
    printf("\n--- Welcome to the Digital Diary ---\n");
    printf("1. Add Diary Entry\n");
    printf("2. View All Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Thank you for using the Digital Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while (choice != 4);

    return 0;
}