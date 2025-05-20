//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 512
#define FILENAME "diary.txt"

void add_entry();
void view_entries();
void edit_entry();
void delete_entry();

void display_menu() {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Edit Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("---------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            // Clear the input buffer on invalid input
            while (getchar() != '\n');
            continue; 
        }
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                edit_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Exiting diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void add_entry() {
    FILE *file = fopen(FILENAME, "a");
    char entry[ENTRY_LENGTH];

    if (!file) {
        printf("Could not open diary file for writing.\n");
        return;
    }

    printf("Enter your diary entry:\n");
    getchar(); // Clear the newline from previous input
    fgets(entry, ENTRY_LENGTH, stdin);
    fprintf(file, "%s\n", entry);
    fclose(file);

    printf("Entry added successfully!\n");
}

void view_entries() {
    FILE *file = fopen(FILENAME, "r");
    char entry[ENTRY_LENGTH];

    if (!file) {
        printf("Could not open diary file for reading. It may be empty.\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    while (fgets(entry, ENTRY_LENGTH, file)) {
        printf("%s", entry);
    }
    fclose(file);
}

void edit_entry() {
    FILE *file = fopen(FILENAME, "r+");
    char entry[ENTRY_LENGTH];
    int entry_num, line_num = 0;
    
    if (!file) {
        printf("Could not open diary file for editing.\n");
        return;
    }

    printf("Enter the entry number to edit: ");
    scanf("%d", &entry_num);

    while (fgets(entry, ENTRY_LENGTH, file)) {
        line_num++;
        if (line_num == entry_num) {
            printf("Current Entry: %s", entry);
            printf("Enter new text for this entry: ");
            getchar(); // Clear newline
            fgets(entry, ENTRY_LENGTH, stdin);
            fseek(file, -strlen(entry), SEEK_CUR);
            fprintf(file, "%s\n", entry);
            printf("Entry edited successfully!\n");
            break;
        }
    }

    if (line_num < entry_num) {
        printf("No such entry exists.\n");
    }

    fclose(file);
}

void delete_entry() {
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    char entry[ENTRY_LENGTH];
    int entry_num, line_num = 0;

    if (!file || !tempFile) {
        printf("Error opening files for deleting entry.\n");
        return;
    }

    printf("Enter the entry number to delete: ");
    scanf("%d", &entry_num);

    while (fgets(entry, ENTRY_LENGTH, file)) {
        line_num++;
        if (line_num != entry_num) {
            fprintf(tempFile, "%s", entry);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    printf("Entry deleted successfully!\n");
}