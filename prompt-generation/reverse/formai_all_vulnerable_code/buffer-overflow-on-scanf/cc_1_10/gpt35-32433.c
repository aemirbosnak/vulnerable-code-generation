//FormAI DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct to hold our data
typedef struct {
    int id;
    char name[50];
    int age;
    char email[50];
} person;

// Define a function to print a person's data
void print_person(person p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Email: %s\n", p.email);
}

// Define our database of people
person people[] = {
    {1, "John Doe", 25, "john.doe@gmail.com"},
    {2, "Jane Smith", 30, "jane.smith@yahoo.com"},
    {3, "Bob Johnson", 40, "bob.johnson@hotmail.com"}
};
const int num_people = sizeof(people) / sizeof(people[0]);

int main() {
    // Query the database for people over 30
    printf("People over 30:\n");
    for (int i = 0; i < num_people; i++) {
        if (people[i].age > 30) {
            print_person(people[i]);
        }
    }

    // Query the database for people with a certain email domain
    char domain[50];
    printf("Enter an email domain to search for: ");
    scanf("%s", domain);
    printf("People with email at %s:\n", domain);
    for (int i = 0; i < num_people; i++) {
        if (strstr(people[i].email, domain) != NULL) {
            print_person(people[i]);
        }
    }

    // Query the database for people with a certain name
    char name[50];
    printf("Enter a name to search for: ");
    scanf("%s", name);
    printf("People named %s:\n", name);
    bool found = false;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            print_person(people[i]);
            found = true;
        }
    }
    if (!found) {
        printf("No people found with name %s\n", name);
    }

    return 0;
}