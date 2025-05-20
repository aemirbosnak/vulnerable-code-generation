//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void display_entries() {
    printf("\n");
    printf("+------------------------------+\n");
    printf("| Name                         | Number\n");
    printf("+------------------------------+\n");

    for (int i = 0; i < num_entries; i++) {
        printf("| %-15s | %-20s |\n", phonebook[i].name, phonebook[i].number);
    }

    printf("+------------------------------+\n");
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("\n");
            printf("+------------------------------+\n");
            printf("| %s                          | %s\n", phonebook[i].name, phonebook[i].number);
            printf("+------------------------------+\n");
        }
    }
}

int main() {
    printf("\n");
    printf("+------------------------------+\n");
    printf("| WELCOME TO THE PHONEBOOK APP |\n");
    printf("+------------------------------+\n");
    printf("\n");

    int choice;

    do {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            display_entries();
            break;
        case 3:
            search_entry();
            break;
        case 4:
            printf("\n");
            printf("+------------------------------+\n");
            printf("| EXITING THE PHONEBOOK APP... |\n");
            printf("+------------------------------+\n");
            printf("\n");
            break;
        default:
            printf("\n");
            printf("Invalid choice! Try again...\n");
            printf("\n");
        }
    } while (choice!= 4);

    return 0;
}