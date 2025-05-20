//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a person
typedef struct {
    char name[50];
    int age;
    int gender;
} Person;

// Define a function to create a new person
Person* create_person(char* name, int age, int gender) {
    Person* person = malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    person->gender = gender;
    return person;
}

// Define a function to print a person's information
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: %d\n", person->gender);
}

// Define a function to compare two people based on their age
int compare_age(Person* a, Person* b) {
    return a->age - b->age;
}

// Define a function to sort an array of people based on their age
void sort_people(Person** people, int count) {
    qsort(people, count, sizeof(Person*), compare_age);
}

// Define a function to search for a person in an array based on their name
Person* search_person(Person** people, int count, char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i]->name, name) == 0) {
            return people[i];
        }
    }
    return NULL;
}

int main() {
    // Create some people
    Person* alice = create_person("Alice", 25, 1);
    Person* bob = create_person("Bob", 30, 0);
    Person* carol = create_person("Carol", 20, 1);
    Person* dave = create_person("Dave", 28, 0);

    // Sort the people by age
    sort_people(&alice, 4);

    // Print the people's information
    print_person(alice);
    print_person(bob);
    print_person(carol);
    print_person(dave);

    // Search for a person by name
    Person* found_person = search_person(&alice, 4, "Bob");
    if (found_person!= NULL) {
        print_person(found_person);
    } else {
        printf("Person not found.\n");
    }

    return 0;
}