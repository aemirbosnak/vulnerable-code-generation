//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// struct defining a person
struct Person {
    char name[20];
    int age;
};

// struct defining a database
struct DB {
    struct Person people[MAX_SIZE];
    int count;
};

// function to add a person to the database
void add_person(struct DB *db, char *name, int age) {
    if (db->count >= MAX_SIZE) {
        printf("Database is full!\n");
        return;
    }
    struct Person new_person;
    strcpy(new_person.name, name);
    new_person.age = age;
    db->people[db->count] = new_person;
    db->count++;
    printf("Added %s, age %d to database.\n", name, age);
}

// function to print all people in the database
void print_database(struct DB *db) {
    printf("Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Name: %s, Age: %d\n", db->people[i].name, db->people[i].age);
    }
}

int main() {
    struct DB database;
    database.count = 0;

    printf("Welcome to the database simulator!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a person\n");
        printf("2. Print database\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char name[20];
                int age;
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                add_person(&database, name, age);
                break;
            }
            case 2:
                print_database(&database);
                break;
            case 3:
                printf("Exiting simulator...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}