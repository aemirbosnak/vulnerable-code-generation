//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Entry;

Entry database[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", database[num_entries].name);

    printf("Enter age: ");
    scanf("%d", &database[num_entries].age);

    printf("Enter occupation: ");
    scanf("%s", database[num_entries].occupation);

    num_entries++;
}

void search_entry() {
    printf("Enter name to search: ");
    char name[50];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Occupation: %s\n", database[i].occupation);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[50];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].name, name) == 0) {
            memmove(&database[i], &database[i+1], sizeof(Entry) * (num_entries - i - 1));
            num_entries--;
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the Medieval Database System!\n");

    while (1) {
        printf("\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Delete an entry\n");
        printf("4. Exit\n");
        printf("\n");

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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}