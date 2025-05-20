//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIARY_FILE "diary.txt"
#define MAX_ENTRIES 100
#define MAX_LENGTH 256

void add_entry();
void view_entries();
void delete_entry();
void display_menu();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear the input buffer

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
                printf("Exiting the diary. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void display_menu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void add_entry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        perror("Error opening diary file");
        return;
    }

    char entry[MAX_LENGTH];
    printf("Enter your diary entry:\n");
    fgets(entry, MAX_LENGTH, stdin);
    fprintf(file, "%s", entry);
    fclose(file);
    printf("Entry added successfully!\n");
}

void view_entries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        perror("Error opening diary file");
        return;
    }

    char ch;
    printf("\n--- Diary Entries ---\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void delete_entry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        perror("Error opening diary file");
        return;
    }

    char entries[MAX_ENTRIES][MAX_LENGTH];
    int count = 0;
    
    while (fgets(entries[count], MAX_LENGTH, file) != NULL && count < MAX_ENTRIES) {
        count++;
    }
    fclose(file);

    printf("Current entries are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, entries[i]);
    }

    printf("Enter the entry number to delete (1 to %d): ", count);
    int entry_number;
    scanf("%d", &entry_number);
    clear_buffer();
    
    if (entry_number < 1 || entry_number > count) {
        printf("Invalid entry number!\n");
        return;
    }

    file = fopen(DIARY_FILE, "w");
    if (file == NULL) {
        perror("Error opening diary file");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != entry_number - 1) {
            fprintf(file, "%s", entries[i]);
        }
    }
    fclose(file);
    printf("Entry deleted successfully!\n");
}

void clear_buffer() {
    while (getchar() != '\n');
}