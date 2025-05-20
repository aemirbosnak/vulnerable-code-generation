//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
typedef struct {
    char *name;
    int age;
} person;

// Define database array
person database[10];

// Define functions
void addPerson(person *p);
void displayPerson(person *p);
void updatePerson(person *p);
void deletePerson(person *p);

// Initialize database
void initDB() {
    int i;
    for (i = 0; i < 10; i++) {
        database[i].name = "Person";
        database[i].age = 25;
    }
}

// Add person to database
void addPerson(person *p) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, p->name) == 0) {
            printf("Person already exists in the database\n");
            return;
        }
    }
    database[i].name = p->name;
    database[i].age = p->age;
    printf("Person added to the database\n");
}

// Display all persons in the database
void displayPerson(person *p) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%s %d\n", database[i].name, database[i].age);
    }
}

// Update person in the database
void updatePerson(person *p) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, p->name) == 0) {
            database[i].age = p->age;
            printf("Person updated in the database\n");
            return;
        }
    }
    printf("Person not found in the database\n");
}

// Delete person from the database
void deletePerson(person *p) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, p->name) == 0) {
            printf("Person deleted from the database\n");
            memmove(database + i, database + i + 1, sizeof(person) * (9 - i));
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    initDB();

    person p1;
    p1.name = "John";
    p1.age = rand() % 100 + 18;
    addPerson(&p1);

    person p2;
    p2.name = "Jane";
    p2.age = rand() % 100 + 18;
    addPerson(&p2);

    displayPerson(&p1);

    updatePerson(&p1);

    displayPerson(&p1);

    deletePerson(&p1);

    displayPerson(&p1);

    return 0;
}