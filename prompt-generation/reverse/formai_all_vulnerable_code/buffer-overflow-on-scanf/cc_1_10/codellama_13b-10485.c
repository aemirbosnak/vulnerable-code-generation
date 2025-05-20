//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Structure to represent a person
struct person {
    char name[50];
    int age;
    char gender;
    char occupation[50];
    char hobbies[50];
};

// Function to read a person from the console
void read_person(struct person* p) {
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter gender (m/f): ");
    scanf(" %c", &p->gender);
    printf("Enter occupation: ");
    scanf("%s", p->occupation);
    printf("Enter hobbies: ");
    scanf("%s", p->hobbies);
}

// Function to print a person
void print_person(struct person* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Gender: %c\n", p->gender);
    printf("Occupation: %s\n", p->occupation);
    printf("Hobbies: %s\n", p->hobbies);
}

// Function to search for a person in the database
bool search_person(struct person* p, char* name) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(p[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    // Create an array of 10 people
    struct person people[10];

    // Read the people from the console
    for (int i = 0; i < 10; i++) {
        read_person(&people[i]);
    }

    // Search for a person by name
    char name[50];
    printf("Enter name to search for: ");
    scanf("%s", name);
    if (search_person(people, name)) {
        printf("Person found!\n");
    } else {
        printf("Person not found.\n");
    }

    // Print the person found
    print_person(&people[0]);

    return 0;
}