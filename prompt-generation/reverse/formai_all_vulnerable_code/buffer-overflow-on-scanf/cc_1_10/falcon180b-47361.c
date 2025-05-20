//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, int age) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full.\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LENGTH);
    entries[num_entries].age = age;

    num_entries++;
}

void print_entries() {
    printf("Name\tAge\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\n", entries[i].name, entries[i].age);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    int age;

    while (1) {
        printf("Enter name (empty string to exit): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);

        add_entry(name, age);
    }

    print_entries();

    return 0;
}