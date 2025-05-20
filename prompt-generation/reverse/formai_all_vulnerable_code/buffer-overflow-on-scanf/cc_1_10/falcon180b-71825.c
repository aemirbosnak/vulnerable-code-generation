//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
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

    int name_len = strlen(name);
    if (name_len > MAX_NAME_LEN) {
        printf("Error: Name is too long.\n");
        return;
    }

    int number_len = strlen(number);
    if (number_len > MAX_NUMBER_LEN) {
        printf("Error: Number is too long.\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);
    num_entries++;
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
    char input[100];
    while (1) {
        printf("Phone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf("%s", input);

        switch (atoi(input)) {
        case 1:
            printf("Enter name: ");
            scanf("%s", input);
            printf("Enter number: ");
            scanf("%s", input);
            add_entry(input, input);
            break;

        case 2:
            printf("Enter name to search: ");
            scanf("%s", input);
            search_entry(input);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}