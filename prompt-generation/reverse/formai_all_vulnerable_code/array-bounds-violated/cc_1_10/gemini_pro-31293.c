//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// What the heck is this? A database simulator? In C? I can't believe my eyes!

// Here's a table definition. I've got columns for name, age, and address.
typedef struct {
    char name[256];
    int age;
    char address[256];
} person_t;

// And here's the database itself. It's just an array of people.
person_t database[] = {
    {"John Doe", 30, "123 Main Street"},
    {"Jane Doe", 25, "456 Elm Street"},
    {"John Smith", 40, "789 Oak Street"},
    {"Jane Smith", 35, "1011 Maple Street"},
};

// How many people are in the database?
#define NUM_PEOPLE (sizeof(database) / sizeof(person_t))

// Here's a function to print a person's information.
void print_person(person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);
}

// Here's a function to find a person by name.
person_t *find_person(char *name) {
    for (int i = 0; i < NUM_PEOPLE; i++) {
        if (strcmp(database[i].name, name) == 0) {
            return &database[i];
        }
    }

    return NULL;
}

// Here's a function to add a new person to the database.
void add_person(person_t *person) {
    database[NUM_PEOPLE] = *person;
}

// Here's a function to delete a person from the database.
void delete_person(char *name) {
    for (int i = 0; i < NUM_PEOPLE; i++) {
        if (strcmp(database[i].name, name) == 0) {
            database[i] = database[NUM_PEOPLE - 1];
            break;
        }
    }
}

// Now let's try it out!
int main() {
    // Let's find John Doe.
    person_t *john_doe = find_person("John Doe");

    // Wow, he exists! Let's print his information.
    if (john_doe != NULL) {
        print_person(john_doe);
    } else {
        printf("John Doe not found.\n");
    }

    // Let's add a new person named Jane Smith.
    person_t jane_smith = {"Jane Smith", 35, "1011 Maple Street"};
    add_person(&jane_smith);

    // Let's find Jane Smith and print her information.
    person_t *jane_smith_found = find_person("Jane Smith");
    if (jane_smith_found != NULL) {
        print_person(jane_smith_found);
    } else {
        printf("Jane Smith not found.\n");
    }

    // Let's delete John Doe.
    delete_person("John Doe");

    // Let's find John Doe again.
    john_doe = find_person("John Doe");
    if (john_doe != NULL) {
        print_person(john_doe);
    } else {
        printf("John Doe not found.\n");
    }

    return 0;
}