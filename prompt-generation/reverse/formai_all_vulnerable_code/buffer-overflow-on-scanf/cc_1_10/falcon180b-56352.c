//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        fprintf(stderr, "Error: Phone book is full.\n");
        exit(1);
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LENGTH);
    strncpy(entries[num_entries].number, number, MAX_NUMBER_LENGTH);

    num_entries++;
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("%s: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    while (1) {
        printf("Enter a name (or 'q' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        printf("Enter a phone number: ");
        scanf("%s", number);

        add_entry(name, number);
    }

    while (1) {
        printf("Enter a name to search for: ");
        scanf("%s", name);

        search_entry(name);
    }

    return 0;
}