//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIARY_FILE "diary.txt"
#define MAX_ENTRY_LENGTH 256
#define MAX_ENTRIES 100

void add_entry();
void view_entries();
void delete_entry(int entry_number);
void clear_input_buffer();

int main() {
    int choice;
    do {
        printf("Simple Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_input_buffer(); // Clear the input buffer for further inputs

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3: {
                int entry_number;
                printf("Enter the entry number to delete: ");
                scanf("%d", &entry_number);
                clear_input_buffer();
                delete_entry(entry_number);
                break;
            }
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_entry() {
    FILE *file = fopen(DIARY_FILE, "a");
    char entry[MAX_ENTRY_LENGTH];
    if (file == NULL) {
        printf("Could not open diary file for appending.\n");
        return;
    }

    printf("Write your diary entry (max %d characters): ", MAX_ENTRY_LENGTH - 1);
    fgets(entry, MAX_ENTRY_LENGTH, stdin);
    fprintf(file, "%s\n", entry);
    fclose(file);
    printf("Entry added successfully!\n");
}

void view_entries() {
    FILE *file = fopen(DIARY_FILE, "r");
    char entry[MAX_ENTRY_LENGTH];
    int entry_number = 1;

    if (file == NULL) {
        printf("No entries found in the diary.\n");
        return;
    }

    printf("Diary Entries:\n");
    while (fgets(entry, MAX_ENTRY_LENGTH, file)) {
        printf("%d: %s", entry_number++, entry);
    }
    fclose(file);
}

void delete_entry(int entry_number) {
    FILE *file = fopen(DIARY_FILE, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    char entry[MAX_ENTRY_LENGTH];
    int current_entry = 1;

    if (file == NULL) {
        printf("Could not open diary file.\n");
        return;
    }
    if (temp_file == NULL) {
        printf("Could not open temporary file.\n");
        fclose(file);
        return;
    }

    while (fgets(entry, MAX_ENTRY_LENGTH, file)) {
        if (current_entry != entry_number) {
            fprintf(temp_file, "%s", entry);
        }
        current_entry++;
    }
    fclose(file);
    fclose(temp_file);
    
    remove(DIARY_FILE);
    rename("temp.txt", DIARY_FILE);

    printf("Entry number %d deleted successfully!\n", entry_number);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}