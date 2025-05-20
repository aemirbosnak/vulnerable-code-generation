//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 20
#define MAX_VALUE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        exit(1);
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LENGTH);
    strncpy(entries[num_entries].value, value, MAX_VALUE_LENGTH);

    num_entries++;
}

void display_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Name\tValue\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].name, entries[i].value);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];

    printf("Enter name and value pairs, separated by a space:\n");

    while (scanf("%s %s", name, value) == 2) {
        add_entry(name, value);
    }

    display_entries();

    return 0;
}