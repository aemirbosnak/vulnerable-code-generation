//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define FILE_NAME "entries.txt"

typedef struct {
    char name[NAME_LENGTH];
    int age;
} Entry;

void write_entries_to_file(Entry entries[], int num_entries) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s %d\n", entries[i].name, entries[i].age);
    }
    
    fclose(file);
}

int read_entries_from_file(Entry entries[]) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Failed to open file for reading");
        return 0; // Return 0 if file does not exist or cannot be opened.
    }

    int count = 0;
    while (fscanf(file, "%s %d", entries[count].name, &entries[count].age) == 2) {
        count++;
        if (count >= MAX_ENTRIES) {
            break; // Limit to MAX_ENTRIES to prevent overflow.
        }
    }
    
    fclose(file);
    return count;
}

void display_entries(Entry entries[], int num_entries) {
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s, Age: %d\n", entries[i].name, entries[i].age);
    }
}

void add_entry(Entry entries[], int *num_entries) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Cannot add more entries. Maximum limit reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", entries[*num_entries].name);
    
    printf("Enter age: ");
    scanf("%d", &entries[*num_entries].age);
    
    (*num_entries)++;
    write_entries_to_file(entries, *num_entries);
}

void delete_entry(Entry entries[], int *num_entries) {
    if (*num_entries == 0) {
        printf("No entries to delete.\n");
        return;
    }
    
    char name[NAME_LENGTH];
    printf("Enter name of entry to delete: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *num_entries - 1; j++) {
                entries[j] = entries[j + 1]; // Shift entries left
            }
            (*num_entries)--;
            printf("Entry deleted.\n");
            break;
        }
    }

    if (found) {
        write_entries_to_file(entries, *num_entries);
    } else {
        printf("Entry not found.\n");
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = read_entries_from_file(entries);
    
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Entries\n");
        printf("2. Add Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_entries(entries, num_entries);
                break;
            case 2:
                add_entry(entries, &num_entries);
                break;
            case 3:
                delete_entry(entries, &num_entries);
                break;
            case 4:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}