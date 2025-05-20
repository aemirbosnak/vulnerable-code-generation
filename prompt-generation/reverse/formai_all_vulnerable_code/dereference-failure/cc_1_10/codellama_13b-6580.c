//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: genius
// Genius Database Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_NAME_LENGTH 100
#define MAX_AGE 100
#define MAX_GENDER 2
#define MAX_ADDRESS 100
#define MAX_SALARY 100000

// Define data structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    char address[MAX_ADDRESS];
    float salary;
} Person;

typedef struct {
    Person *people;
    int num_people;
} Database;

// Function prototypes
void addPerson(Database *db, Person person);
void printDatabase(Database *db);

// Main function
int main() {
    Database db;
    db.people = NULL;
    db.num_people = 0;

    // Add some people to the database
    Person p1 = {"Alice", 25, 'F', "123 Main St", 50000};
    addPerson(&db, p1);

    Person p2 = {"Bob", 30, 'M', "456 Elm St", 60000};
    addPerson(&db, p2);

    Person p3 = {"Charlie", 35, 'M', "789 Oak St", 70000};
    addPerson(&db, p3);

    // Print the database
    printDatabase(&db);

    return 0;
}

// Function definitions
void addPerson(Database *db, Person person) {
    // Reallocate memory for the new person
    db->people = realloc(db->people, (db->num_people + 1) * sizeof(Person));

    // Copy the new person to the end of the array
    memcpy(&db->people[db->num_people], &person, sizeof(Person));

    // Increment the number of people in the database
    db->num_people++;
}

void printDatabase(Database *db) {
    // Print the database header
    printf("Name\tAge\tGender\tAddress\tSalary\n");

    // Print each person in the database
    for (int i = 0; i < db->num_people; i++) {
        printf("%s\t%d\t%c\t%s\t%.2f\n", db->people[i].name, db->people[i].age, db->people[i].gender, db->people[i].address, db->people[i].salary);
    }
}