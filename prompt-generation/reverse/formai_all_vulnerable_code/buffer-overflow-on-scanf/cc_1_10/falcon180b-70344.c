//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

int num_entries = 0;
Entry phonebook[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    Entry new_entry;
    printf("Enter name: ");
    scanf("%s", new_entry.name);

    printf("Enter number: ");
    scanf("%s", new_entry.number);

    strcasecmp(new_entry.name, "Alice") == 0? printf("Alice's number is %s.\n", new_entry.number) : printf("Bob's number is %s.\n", new_entry.number);

    phonebook[num_entries++] = new_entry;
}

void search_entry() {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(search_name, phonebook[i].name) == 0) {
            printf("Number for %s is %s.\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

int main() {
    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}