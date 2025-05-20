//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_ENTRIES 100
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char name[MAX_ENTRY_LENGTH];
    int age;
    int phone_number;
} database_entry;

database_entry database[MAX_DATABASE_ENTRIES];
int num_entries = 0;

void add_entry(database_entry entry) {
    if (num_entries >= MAX_DATABASE_ENTRIES) {
        printf("Database is full!\n");
        return;
    }
    database[num_entries] = entry;
    num_entries++;
    printf("Entry added successfully!\n");
}

void search_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Phone Number: %d\n", database[i].phone_number);
        }
    }
}

void delete_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].name, name) == 0) {
            num_entries--;
            database[i] = database[num_entries];
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("Entry not found!\n");
}

void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Phone Number: %d\n", database[i].phone_number);
        printf("\n");
    }
}

int main() {
    char name[MAX_ENTRY_LENGTH];
    int age, phone_number;
    int choice;

    while (1) {
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Display Entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter age: ");
            scanf("%d", &age);
            printf("Enter phone number: ");
            scanf("%d", &phone_number);
            add_entry((database_entry) {.name = name,.age = age,.phone_number = phone_number});
            break;
        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            search_entry(name);
            break;
        case 3:
            printf("Enter name to delete: ");
            scanf("%s", name);
            delete_entry(name);
            break;
        case 4:
            display_entries();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}