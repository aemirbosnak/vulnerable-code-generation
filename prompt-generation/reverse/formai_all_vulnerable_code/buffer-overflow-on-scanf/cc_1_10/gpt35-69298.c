//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DATABASE_SIZE 100

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

Person database[MAX_DATABASE_SIZE];

int num_people = 0;

void add_person(int id, char* name, int age) {
    if(num_people == MAX_DATABASE_SIZE) {
        printf("Database is full! Cannot add more people.");
        return;
    }

    // Allocate memory for new person
    Person* new_person = (Person*) malloc(sizeof(Person));

    // Set new person's values
    new_person->id = id;
    strcpy(new_person->name, name);
    new_person->age = age;

    // Add new person to database
    database[num_people] = *new_person;
    num_people++;

    printf("Added person with ID %d to database!\n", id);
}

void search_person(int id) {
    int index = -1;

    // Search for person with given ID
    for(int i = 0; i < num_people; i++) {
        if(database[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Person with ID %d not found in database.\n", id);
        return;
    }

    // Print person's information
    printf("ID: %d\n", database[index].id);
    printf("Name: %s\n", database[index].name);
    printf("Age: %d\n", database[index].age);
}

int main() {
    printf("Welcome to the Database Simulation Program!\n");
    printf("Please choose an option:\n");
    printf("1. Add a person to the database\n");
    printf("2. Search for a person in the database\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            // Add a person to the database
            printf("Please enter the person's ID, name and age:\n");

            int id, age;
            char name[50];
            scanf("%d %s %d", &id, name, &age);

            add_person(id, name, age);
            break;

        case 2:
            // Search for a person in the database
            printf("Please enter the person's ID to search for:\n");

            int search_id;
            scanf("%d", &search_id);

            search_person(search_id);
            break;

        default:
            printf("Invalid option chosen. Exiting program.");
            exit(0);
            break;

    }

    return 0;
}