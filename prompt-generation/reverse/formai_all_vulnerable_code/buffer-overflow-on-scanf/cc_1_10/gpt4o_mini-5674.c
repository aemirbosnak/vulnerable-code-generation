//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Entry;

void addEntry(FILE *file) {
    Entry entry;
    
    printf("Enter name: ");
    getchar(); // Consume the newline character
    fgets(entry.name, MAX_NAME_LENGTH, stdin);
    entry.name[strcspn(entry.name, "\n")] = 0; // Remove the trailing newline

    printf("Enter address: ");
    fgets(entry.address, MAX_ADDRESS_LENGTH, stdin);
    entry.address[strcspn(entry.address, "\n")] = 0; // Remove the trailing newline

    fwrite(&entry, sizeof(Entry), 1, file);
    printf("Entry added successfully.\n");
}

void viewEntries(FILE *file) {
    Entry entry;
    rewind(file); // Move to the beginning of the file
    printf("\n--- Address Book Entries ---\n");
    
    while (fread(&entry, sizeof(Entry), 1, file)) {
        printf("Name: %s\n", entry.name);
        printf("Address: %s\n", entry.address);
        printf("------------------------\n");
    }
}

void deleteEntry(FILE *file) {
    Entry entries[MAX_ENTRIES];
    Entry entry;
    int count = 0, indexToRemove;

    rewind(file); // Move to the beginning of the file

    while (fread(&entry, sizeof(Entry), 1, file)) {
        entries[count++] = entry; // Store current entries
    }

    printf("Enter the number of the entry to delete (1 to %d): ", count);
    scanf("%d", &indexToRemove);

    if (indexToRemove < 1 || indexToRemove > count) {
        printf("Invalid entry number.\n");
        return;
    }

    // Shift entries to remove the selected one
    for (int i = indexToRemove - 1; i < count - 1; i++) {
        entries[i] = entries[i + 1];
    }

    // Write back the modified entries to the file
    freopen(NULL, "wb", file); // Clear the file
    fwrite(entries, sizeof(Entry), count - 1, file);
    printf("Entry deleted successfully.\n");
}

void displayMenu() {
    printf("\n--- Address Book Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
    printf("------------------------\n");
}

int main() {
    FILE *file;
    int choice;

    // Open the file for reading and writing (binary mode)
    file = fopen("address_book.dat", "ab+");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(file);
                break;
            case 2:
                viewEntries(file);
                break;
            case 3:
                deleteEntry(file);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    fclose(file);
    return EXIT_SUCCESS;
}