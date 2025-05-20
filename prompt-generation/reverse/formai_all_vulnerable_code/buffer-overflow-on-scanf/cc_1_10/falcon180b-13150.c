//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);
    num_entries++;
}

void delete_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memset(&entries[i], 0, sizeof(entry_t));
            num_entries--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void search_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    char choice;
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    while (1) {
        printf("Phone Book\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            add_entry(name, number);
            break;

        case '2':
            printf("Enter name to delete: ");
            scanf("%s", name);
            delete_entry(name);
            break;

        case '3':
            printf("Enter name to search: ");
            scanf("%s", name);
            search_entry(name);
            break;

        case '4':
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}