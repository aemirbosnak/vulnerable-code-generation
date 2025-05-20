//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: surprised
// Surprised C Database Querying Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to hold data
struct person {
    char name[50];
    int age;
    char gender;
    char email[50];
};

struct database {
    struct person *people;
    int num_people;
};

// Function to create a new database
struct database *create_database(int num_people) {
    struct database *db = malloc(sizeof(struct database));
    db->people = malloc(num_people * sizeof(struct person));
    db->num_people = num_people;
    return db;
}

// Function to add a new person to the database
void add_person(struct database *db, char *name, int age, char gender, char *email) {
    strcpy(db->people[db->num_people].name, name);
    db->people[db->num_people].age = age;
    db->people[db->num_people].gender = gender;
    strcpy(db->people[db->num_people].email, email);
    db->num_people++;
}

// Function to print the database
void print_database(struct database *db) {
    for (int i = 0; i < db->num_people; i++) {
        printf("Person %d: %s, %d, %c, %s\n", i, db->people[i].name, db->people[i].age, db->people[i].gender, db->people[i].email);
    }
}

int main() {
    // Create a new database with 5 people
    struct database *db = create_database(5);

    // Add some people to the database
    add_person(db, "Alice", 25, 'F', "alice@example.com");
    add_person(db, "Bob", 30, 'M', "bob@example.com");
    add_person(db, "Charlie", 35, 'M', "charlie@example.com");
    add_person(db, "Dave", 40, 'M', "dave@example.com");
    add_person(db, "Eve", 45, 'F', "eve@example.com");

    // Print the database
    print_database(db);

    return 0;
}