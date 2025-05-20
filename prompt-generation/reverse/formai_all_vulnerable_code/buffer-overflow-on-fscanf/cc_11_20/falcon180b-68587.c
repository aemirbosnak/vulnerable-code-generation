//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Entry;

int main() {
    FILE *db_file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    db_file = fopen("database.txt", "r");
    if (db_file == NULL) {
        printf("Error: Could not open database file.\n");
        return 1;
    }

    while (fscanf(db_file, "%s %s\n", entries[num_entries].name, entries[num_entries].value)!= EOF) {
        num_entries++;
    }

    fclose(db_file);

    do {
        printf("Database:\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%s: %s\n", entries[i].name, entries[i].value);
        }

        printf("\nWhat would you like to do?\n");
        printf("A - Add an entry\n");
        printf("S - Search for an entry\n");
        printf("E - Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter the name of the new entry:\n");
                scanf(" %s", entries[num_entries].name);
                printf("Enter the value of the new entry:\n");
                scanf(" %s", entries[num_entries].value);
                num_entries++;
                break;
            case 'S':
                printf("Enter the name of the entry to search for:\n");
                scanf(" %s", entries[num_entries].name);
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(entries[i].name, entries[num_entries].name) == 0) {
                        printf("Value: %s\n", entries[i].value);
                    }
                }
                break;
            case 'E':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 'E');

    db_file = fopen("database.txt", "w");
    if (db_file == NULL) {
        printf("Error: Could not open database file.\n");
        return 1;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(db_file, "%s %s\n", entries[i].name, entries[i].value);
    }

    fclose(db_file);

    return 0;
}