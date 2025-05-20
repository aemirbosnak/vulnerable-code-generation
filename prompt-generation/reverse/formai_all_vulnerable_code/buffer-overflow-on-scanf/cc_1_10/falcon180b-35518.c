//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct entry {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Entry;

Entry table[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Table is full!\n");
        return;
    }
    strcpy(table[num_entries].name, name);
    strcpy(table[num_entries].value, value);
    num_entries++;
}

void search_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Value for %s: %s\n", name, table[i].value);
            return;
        }
    }
    printf("Entry not found!\n");
}

int main() {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
    char choice;

    printf("Welcome to the C Database Indexing System!\n");
    printf("Please enter the name of the entry you wish to add/search:\n");
    scanf("%s", name);

    printf("Please enter the value of the entry:\n");
    scanf("%s", value);

    printf("Please choose an option:\n");
    printf("1. Add entry\n");
    printf("2. Search entry\n");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            add_entry(name, value);
            break;
        case '2':
            search_entry(name);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}