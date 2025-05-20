//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;
}

void remove_entry(char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memset(&phonebook[i], 0, sizeof(entry_t));
            num_entries--;

            printf("Entry for %s removed.\n", name);
            return;
        }
    }

    printf("Entry not found.\n");
}

void search_entry(char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    char choice;

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", phonebook[num_entries].name);
                printf("Enter number: ");
                scanf("%s", phonebook[num_entries].number);
                break;
            case '2':
                printf("Enter name to remove: ");
                remove_entry(scanf("%s", phonebook[num_entries].name));
                break;
            case '3':
                printf("Enter name to search: ");
                search_entry(scanf("%s", phonebook[num_entries].name));
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}