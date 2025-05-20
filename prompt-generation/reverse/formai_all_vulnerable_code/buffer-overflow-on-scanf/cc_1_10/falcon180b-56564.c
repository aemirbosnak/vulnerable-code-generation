//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

int num_entries = 0;
entry phonebook[MAX_ENTRIES];

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void display_entries() {
    printf("Phonebook:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].number);
    }
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("%s - %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
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
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}