//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person;

person database[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, database is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[num_entries].name);

    printf("Enter age: ");
    scanf("%d", &database[num_entries].age);

    num_entries++;
}

void search_entry() {
    char name[MAX_NAME_LENGTH];
    int age = 0;

    printf("Enter name to search: ");
    scanf("%s", name);

    printf("Enter age to search (0 for any): ");
    scanf("%d", &age);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(database[i].name, name) == 0 && (age == 0 || database[i].age == age)) {
            printf("Found entry: %s, %d years old\n", database[i].name, database[i].age);
        }
    }
}

void delete_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(database[i].name, name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(database[j].name, database[j + 1].name);
                database[j].age = database[j + 1].age;
            }

            num_entries--;

            printf("Entry deleted: %s, %d years old\n", name, database[i].age);

            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            delete_entry();
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