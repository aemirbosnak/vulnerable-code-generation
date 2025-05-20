//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    char name_to_search[MAX_NAME_LENGTH];

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open phonebook file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s\n", entries[num_entries].name, entries[num_entries].number)!= EOF) {
        num_entries++;
        if (num_entries == MAX_ENTRIES) {
            printf("Error: Phonebook is full.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    while (1) {
        printf("Phonebook Menu:\n");
        printf("1. Add entry\n");
        printf("2. Search for entry\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf(" %s", name_to_search);
            printf("Enter number: ");
            scanf(" %s", entries[num_entries].number);
            strcpy(entries[num_entries].name, name_to_search);
            num_entries++;
            if (num_entries == MAX_ENTRIES) {
                printf("Error: Phonebook is full.\n");
            } else {
                printf("Entry added.\n");
            }
            break;

        case '2':
            printf("Enter name to search: ");
            scanf(" %s", name_to_search);
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].name, name_to_search) == 0) {
                    printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
                }
            }
            break;

        case '3':
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}