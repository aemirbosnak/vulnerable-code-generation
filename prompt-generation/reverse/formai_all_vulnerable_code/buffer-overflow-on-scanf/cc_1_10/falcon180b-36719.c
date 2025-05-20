//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

void add_entry(entry_t* entries, int num_entries, char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Entry already exists.\n");
            return;
        }
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);

    num_entries++;
}

void delete_entry(entry_t* entries, int num_entries, char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            break;
        }
    }
}

void search_entry(entry_t* entries, int num_entries, char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char name[MAX_NAME_LEN];
            char number[MAX_NUMBER_LEN];

            printf("Enter name: ");
            scanf("%s", name);

            printf("Enter number: ");
            scanf("%s", number);

            add_entry(entries, num_entries, name, number);
        } else if (choice == 2) {
            char name[MAX_NAME_LEN];

            printf("Enter name to delete: ");
            scanf("%s", name);

            delete_entry(entries, num_entries, name);
        } else if (choice == 3) {
            char name[MAX_NAME_LEN];

            printf("Enter name to search: ");
            scanf("%s", name);

            search_entry(entries, num_entries, name);
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}