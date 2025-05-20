//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_ENTRIES 100
#define FILENAME "data.txt"

typedef struct {
    int id;
    char name[50];
} Entry;

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s: %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}

void write_entries_to_file(Entry *entries, int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        handle_error("Failed to open file for writing");
    }

    for (int i = 0; i < count; i++) {
        if (fprintf(file, "%d: %s\n", entries[i].id, entries[i].name) < 0) {
            handle_error("Failed to write entry to file");
        }
    }
    
    if (fclose(file) != 0) {
        handle_error("Failed to close the file");
    }
}

void read_entries_from_file(Entry *entries, int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        handle_error("Failed to open file for reading");
    }

    *count = 0;
    while (*count < MAX_ENTRIES && fscanf(file, "%d: %[^\n]\n", &entries[*count].id, entries[*count].name) == 2) {
        (*count)++;
    }
    
    if (*count == MAX_ENTRIES && !feof(file)) {
        fprintf(stderr, "Warning: Maximum number of entries reached, some data may be lost.\n");
    }

    if (fclose(file) != 0) {
        handle_error("Failed to close the file");
    }
}

void display_entries(Entry *entries, int count) {
    printf("\n--- Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s\n", entries[i].id, entries[i].name);
    }
    printf("----------------\n");
}

void add_entry(Entry *entries, int *count) {
    if (*count >= MAX_ENTRIES) {
        fprintf(stderr, "Error: Cannot add more entries, limit reached.\n");
        return;
    }

    Entry new_entry;
    printf("Enter ID: ");
    scanf("%d", &new_entry.id);
    getchar();  // Clear newline character from the buffer
    printf("Enter Name: ");
    fgets(new_entry.name, sizeof(new_entry.name), stdin);
    new_entry.name[strcspn(new_entry.name, "\n")] = 0;  // Remove newline
    
    entries[*count] = new_entry;
    (*count)++;
    printf("Entry added successfully!\n");
}

void clear_entries(Entry *entries, int *count) {
    *count = 0;
    printf("All entries cleared.\n");
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    // Welcome Message
    printf("Welcome to the Artistic Entry Manager!\n");
    printf("Your entries will be sculpted into the file: %s\n", FILENAME);

    // Load existing entries
    read_entries_from_file(entries, &count);
    display_entries(entries, count);

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Clear Entries\n");
        printf("4. Save and Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from the buffer

        switch (choice) {
            case 1:
                add_entry(entries, &count);
                break;
            case 2:
                display_entries(entries, count);
                break;
            case 3:
                clear_entries(entries, &count);
                break;
            case 4:
                write_entries_to_file(entries, count);
                printf("Exiting, thank you for using Entry Manager!\n");
                return 0;
            default:
                fprintf(stderr, "Invalid choice. Please try again.\n");
        }
    }

    return 0;
}