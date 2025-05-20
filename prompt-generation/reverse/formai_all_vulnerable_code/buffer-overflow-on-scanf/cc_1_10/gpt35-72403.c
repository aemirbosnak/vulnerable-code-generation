//FormAI DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    char address[100];
    int age;
} Person;

typedef struct {
    Person people[MAX_SIZE];
    int size;
} Database;

void addPerson(Database *db, Person p) {
    if (db->size >= MAX_SIZE) {
        printf("Database is full!");
        return;
    } else {
        db->people[db->size] = p;
        db->size++;
        printf("Person added successfully.\n");
    }
}

void showDatabase(Database db) {
    printf("\nPeople in database: \n");
    for (int i = 0; i < db.size; i++) {
        printf("ID: %d\n", db.people[i].id);
        printf("Name: %s\n", db.people[i].name);
        printf("Address: %s\n", db.people[i].address);
        printf("Age: %d\n", db.people[i].age);
        printf("----------------------\n");
    }
}

int main() {
    Database myDatabase;
    myDatabase.size = 0;

    printf("*****************\n");
    printf("Database Program!\n");
    printf("*****************\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1 - Add a person to the database\n");
        printf("2 - Show database\n");
        printf("3 - Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Person p;
                printf("\nEnter person details: \n");
                printf("ID: ");
                scanf("%d", &p.id);
                printf("Name: ");
                scanf("%s", &p.name);
                printf("Address: ");
                scanf("%s", &p.address);
                printf("Age: ");
                scanf("%d", &p.age);

                addPerson(&myDatabase, p);
                break;
            }
            case 2: {
                showDatabase(myDatabase);
                break;
            }
            case 3: {
                printf("Exiting...");
                exit(0);
            }
            default: {
                printf("Invalid option! Please try again.\n");
                break;
            }
        }
    }

    return 0;
}