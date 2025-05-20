//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry;

int num_entries = 0;
entry phonebook[MAX_ENTRIES];

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;
}

void display_entry(int index) {
    if (index >= num_entries || index < 0) {
        printf("Invalid entry index!\n");
        return;
    }

    printf("Name: %s\n", phonebook[index].name);
    printf("Number: %s\n", phonebook[index].number);
}

void search_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            display_entry(i);
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LEN], number[MAX_NUMBER_LEN];

    do {
        printf("Phone Book\n");
        printf("1. Add Entry\n");
        printf("2. Display Entry\n");
        printf("3. Search Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(name, number);
                break;
            case 2:
                printf("Enter entry index: ");
                scanf("%d", &choice);
                display_entry(choice);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(name);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}