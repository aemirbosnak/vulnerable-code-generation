//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ENTRIES 1000
#define MAX_NAME_LENGTH 30
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

entry phonebook[MAX_NUM_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void display_entry(int index) {
    printf("%s: %s\n", phonebook[index].name, phonebook[index].number);
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            display_entry(i);
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    printf("Welcome to the Romantic Phonebook!\n");
    printf("Press 1 to add an entry.\n");
    printf("Press 2 to search for an entry.\n");
    printf("Press 3 to exit.\n");

    int choice;
    while (1) {
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