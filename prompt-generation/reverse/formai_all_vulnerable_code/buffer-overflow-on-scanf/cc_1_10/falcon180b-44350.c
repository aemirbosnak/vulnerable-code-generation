//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: genious
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
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);
    num_entries++;
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

int main() {
    char input[100];
    int choice;

    printf("Welcome to the Phone Book!\n");
    printf("Enter 1 to add an entry.\n");
    printf("Enter 2 to search for an entry.\n");
    printf("Enter 0 to quit.\n");

    while (1) {
        scanf("%s", input);
        choice = atoi(input);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            printf("Enter name: ");
            scanf("%s", input);
            printf("Enter number: ");
            scanf("%s", input);
            add_entry(input, input);
        } else if (choice == 2) {
            printf("Enter name to search: ");
            scanf("%s", input);
            search_entry(input);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}