//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    int age;
    char address[100];
} entry_t;

entry_t database[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", database[num_entries].name);
    printf("Enter age: ");
    scanf("%d", &database[num_entries].age);
    printf("Enter address: ");
    scanf("%s", database[num_entries].address);
    num_entries++;
}

void view_entry(int index) {
    printf("Name: %s\n", database[index].name);
    printf("Age: %d\n", database[index].age);
    printf("Address: %s\n", database[index].address);
}

void delete_entry(int index) {
    if (index >= 0 && index < num_entries) {
        num_entries--;
        for (int i = index; i < num_entries; i++) {
            strcpy(database[i].name, database[i+1].name);
            database[i].age = database[i+1].age;
            strcpy(database[i].address, database[i+1].address);
        }
    } else {
        printf("Invalid index.\n");
    }
}

void search_entry(char *name) {
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(database[i].name, name) == 0) {
            view_entry(i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    add_entry();
    add_entry();
    add_entry();
    add_entry();
    add_entry();

    view_entry(0);
    view_entry(1);
    view_entry(2);
    view_entry(3);
    view_entry(4);

    search_entry("John");
    search_entry("Jane");
    search_entry("Bob");
    search_entry("Alice");

    delete_entry(2);

    view_entry(0);
    view_entry(1);
    view_entry(2);
    view_entry(3);
    view_entry(4);

    return 0;
}