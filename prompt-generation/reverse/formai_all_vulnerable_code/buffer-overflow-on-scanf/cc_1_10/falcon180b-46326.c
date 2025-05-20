//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: funny
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
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    fgets(phonebook[num_entries].name, MAX_NAME_LEN, stdin);
    phonebook[num_entries].name[strcspn(phonebook[num_entries].name, "\n")] = '\0';

    printf("Enter number: ");
    fgets(phonebook[num_entries].number, MAX_NUMBER_LEN, stdin);
    phonebook[num_entries].number[strcspn(phonebook[num_entries].number, "\n")] = '\0';

    num_entries++;
}

void search_entry() {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    fgets(search_name, MAX_NAME_LEN, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}