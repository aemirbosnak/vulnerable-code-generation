//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

void create_person(Person* person, char* name, int age) {
    strcpy(person->name, name);
    person->age = age;
}

void print_person(Person* person) {
    printf("Name: %s\nAge: %d\n", person->name, person->age);
}

int main() {
    // Create an array of people
    Person people[MAX_SIZE];

    // Initialize the array with some data
    int num_people = 0;
    create_person(&people[num_people++], "Alice", 25);
    create_person(&people[num_people++], "Bob", 30);
    create_person(&people[num_people++], "Charlie", 20);
    create_person(&people[num_people++], "Dave", 28);

    // Sort the array by age
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Search for a person by name
    char search_name[MAX_SIZE];
    printf("Enter a name to search for: ");
    scanf("%s", search_name);
    Person* found_person = NULL;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, search_name) == 0) {
            found_person = &people[i];
            break;
        }
    }

    // Print the results
    if (found_person!= NULL) {
        print_person(found_person);
    } else {
        printf("Person not found.\n");
    }

    return 0;
}