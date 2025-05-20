//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            printf("Invalid name\n");
            return;
        }
    }

    printf("Enter number: ");
    scanf("%s", number);
    for (int i = 0; i < strlen(number); i++) {
        if (!isdigit(number[i])) {
            printf("Invalid number\n");
            return;
        }
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;
}

void search_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Entry not found\n");
}

void remove_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to remove: ");
    scanf("%s", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memset(phonebook[i].name, 0, MAX_NAME_LENGTH);
            memset(phonebook[i].number, 0, MAX_NUMBER_LENGTH);
            num_entries--;
            return;
        }
    }
    printf("Entry not found\n");
}

int main() {
    while (1) {
        printf("\n1. Add entry\n2. Search entry\n3. Remove entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                remove_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}