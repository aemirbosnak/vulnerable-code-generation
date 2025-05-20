//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 64
#define MAX_NUMBER_LENGTH 16
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: phone book is full\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LENGTH);
    strncpy(entries[num_entries].number, number, MAX_NUMBER_LENGTH);

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

    printf("Entry not found\n");
}

int main() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    while (true) {
        printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", name);

        printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LENGTH - 1);
        scanf("%s", number);

        add_entry(name, number);
    }

    return 0;
}