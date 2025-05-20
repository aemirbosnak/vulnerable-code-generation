//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure to store the data
typedef struct {
    char name[50];
    int age;
} person;

// Define the database
person database[10] = {
    {"Alice", 25},
    {"Bob", 30},
    {"Charlie", 35},
    {"David", 20},
    {"Eve", 25},
    {"Frank", 40},
    {"Grace", 30},
    {"Helen", 20},
    {"Ivy", 35}
};

// Function to add a new person to the database
void add_person(person *new_person) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, new_person->name) == 0) {
            printf("Sorry, someone with the same name already exists!\n");
            return;
        }
    }
    printf("Welcome to the happy family, %s! You're the %dth member.\n", new_person->name, i + 1);
    database[i] = *new_person;
}

// Function to print all the people in the database
void print_all() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d. %s (%d years old)\n", i + 1, database[i].name, database[i].age);
    }
}

int main() {
    srand(time(NULL));

    // Add some people to the database
    person new_person = {"Oliver", 28};
    add_person(&new_person);

    // Print all the people in the database
    print_all();

    // Add another person to the database
    person new_person2 = {"Lily", 32};
    add_person(&new_person2);

    // Print all the people in the database again
    print_all();

    return 0;
}