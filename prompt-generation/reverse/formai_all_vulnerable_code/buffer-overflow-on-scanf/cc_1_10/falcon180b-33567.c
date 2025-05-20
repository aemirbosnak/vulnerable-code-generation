//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int index;
} entry;

entry entries[MAX_ENTRIES];
int num_entries;

void add_entry(char* key, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Index table is full.\n");
        return;
    }

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            strcpy(entries[i].value, value);
            return;
        }
    }

    strcpy(entries[num_entries].key, key);
    strcpy(entries[num_entries].value, value);
    entries[num_entries].index = num_entries;
    num_entries++;
}

void search_entry(char* key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            printf("%s\n", entries[i].value);
            return;
        }
    }

    printf("Not found.\n");
}

void delete_entry(char* key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            strcpy(entries[i].key, "");
            strcpy(entries[i].value, "");
            entries[i].index = -1;
            num_entries--;
            return;
        }
    }

    printf("Not found.\n");
}

void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (entries[i].index!= -1) {
            printf("%s -> %s\n", entries[i].key, entries[i].value);
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the database indexing system!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Display entries\n");
        printf("5. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char key[MAX_KEY_LENGTH];
                char value[MAX_VALUE_LENGTH];

                printf("Enter key: ");
                scanf("%s", key);

                printf("Enter value: ");
                scanf("%s", value);

                add_entry(key, value);

                break;
            }

            case 2: {
                char key[MAX_KEY_LENGTH];

                printf("Enter key: ");
                scanf("%s", key);

                search_entry(key);

                break;
            }

            case 3: {
                char key[MAX_KEY_LENGTH];

                printf("Enter key: ");
                scanf("%s", key);

                delete_entry(key);

                break;
            }

            case 4: {
                display_entries();

                break;
            }

            case 5: {
                printf("Exiting...\n");
                return 0;
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}