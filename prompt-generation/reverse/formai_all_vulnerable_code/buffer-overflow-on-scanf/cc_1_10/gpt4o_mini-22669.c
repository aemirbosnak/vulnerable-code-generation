//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define FILENAME "diary.txt"

void add_entry();
void view_entries();
void delete_entry();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear the newline character from buffer

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
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void add_entry() {
    FILE *file = fopen(FILENAME, "a");
    char entry[ENTRY_SIZE];

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter your diary entry (max %d characters): ", ENTRY_SIZE - 1);
    fgets(entry, ENTRY_SIZE, stdin);
    fprintf(file, "%s", entry);
    fclose(file);
    printf("Entry added!\n");
}

void view_entries() {
    FILE *file = fopen(FILENAME, "r");
    char entry[ENTRY_SIZE];
    int index = 1;

    if (file == NULL) {
        printf("No entries found or error opening file!\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    while (fgets(entry, ENTRY_SIZE, file) != NULL) {
        printf("%d: %s", index++, entry);
    }
    fclose(file);
    if (index == 1) {
        printf("No entries found.\n");
    }
}

void delete_entry() {
    FILE *file = fopen(FILENAME, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    char entry[ENTRY_SIZE];
    int index = 1, delete_index;

    if (file == NULL || temp_file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    view_entries(); // Display current entries
    printf("Enter the entry number to delete: ");
    scanf("%d", &delete_index);
    clear_buffer(); // Clear the newline character from buffer

    while (fgets(entry, ENTRY_SIZE, file) != NULL) {
        if (index != delete_index) {
            fprintf(temp_file, "%s", entry);
        }
        index++;
    }

    fclose(file);
    fclose(temp_file);
    remove(FILENAME); // Delete the old diary file
    rename("temp.txt", FILENAME); // Rename temp file to original file

    printf("Entry deleted! If the entry number was valid.\n");
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}