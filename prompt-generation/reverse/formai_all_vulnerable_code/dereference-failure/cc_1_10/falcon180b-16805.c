//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a person
typedef struct person {
    char name[50];
    int age;
    char occupation[50];
} Person;

// Define the structure of the database
typedef struct database {
    Person* people;
    int num_people;
} Database;

// Function to create a new person in the database
Person* create_person(char* name, int age, char* occupation) {
    Person* new_person = (Person*)malloc(sizeof(Person));
    strcpy(new_person->name, name);
    new_person->age = age;
    strcpy(new_person->occupation, occupation);
    return new_person;
}

// Function to add a person to the database
void add_person(Database* db, Person* new_person) {
    db->people = (Person*)realloc(db->people, sizeof(Person)*(db->num_people+1));
    db->people[db->num_people] = *new_person;
    db->num_people++;
}

// Function to search for a person in the database by name
Person* search_by_name(Database* db, char* name) {
    int i;
    for(i=0; i<db->num_people; i++) {
        if(strcmp(db->people[i].name, name) == 0) {
            return &db->people[i];
        }
    }
    return NULL;
}

// Function to print the details of a person
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
}

// Main function to simulate a database of people
int main() {
    Database db;
    db.people = NULL;
    db.num_people = 0;

    // Create some people
    Person* sherlock = create_person("Sherlock Holmes", 42, "Detective");
    Person* watson = create_person("Dr. John Watson", 38, "Doctor");

    // Add them to the database
    add_person(&db, sherlock);
    add_person(&db, watson);

    // Print all the people in the database
    printf("All people in the database:\n");
    int i;
    for(i=0; i<db.num_people; i++) {
        print_person(&db.people[i]);
    }

    // Search for a specific person
    Person* found_person = search_by_name(&db, "Sherlock Holmes");
    if(found_person!= NULL) {
        printf("\nFound person: %s\n", found_person->name);
        print_person(found_person);
    } else {
        printf("\nPerson not found.\n");
    }

    return 0;
}