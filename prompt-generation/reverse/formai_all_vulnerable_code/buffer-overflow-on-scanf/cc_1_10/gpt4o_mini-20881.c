//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define FILENAME "diary.txt"

void write_entry();
void read_entries();
void list_entries();

int main() {
    int choice;

    do {
        printf("\n-------- Peaceful Diary --------\n");
        printf("1. Write an Entry\n");
        printf("2. Read Entries\n");
        printf("3. List All Entries\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                write_entry();
                break;
            case 2:
                read_entries();
                break;
            case 3:
                list_entries();
                break;
            case 4:
                printf("Thank you for using the Peaceful Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

void write_entry() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Could not open the diary file.\n");
        return;
    }

    char entry[ENTRY_SIZE];
    printf("Write your diary entry (max length %d characters): ", ENTRY_SIZE - 1);
    fgets(entry, ENTRY_SIZE, stdin);

    // Remove the newline character if present
    size_t len = strlen(entry);
    if (len > 0 && entry[len - 1] == '\n') {
        entry[len - 1] = '\0';
    }

    fprintf(file, "%s\n", entry);
    fclose(file);
    printf("Your entry has been saved peacefully.\n");
}

void read_entries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Could not open the diary file.\n");
        return;
    }

    char entry[ENTRY_SIZE];
    printf("\n--- Your Diary Entries ---\n");
    while (fgets(entry, ENTRY_SIZE, file)) {
        printf("- %s", entry);
    }
    fclose(file);
    printf("--- End of Entries ---\n");
}

void list_entries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Could not open the diary file.\n");
        return;
    }

    char entry[ENTRY_SIZE];
    int counter = 1;
    printf("\n--- All Diary Entries ---\n");
    while (fgets(entry, ENTRY_SIZE, file)) {
        printf("%d. %s", counter++, entry);
    }
    fclose(file);
    printf("--- End of All Entries ---\n");
}