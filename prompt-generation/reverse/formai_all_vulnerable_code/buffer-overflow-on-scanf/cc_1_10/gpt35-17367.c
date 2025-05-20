//FormAI DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    char occupation[20];
}Person;

void print_person(Person person) {
    printf("ID: %d\nName: %s\nAge: %d\nOccupation: %s\n\n", person.id, person.name, person.age, person.occupation);
}

int main() {
    Person people[5];
    
    // Setting up some test data
    people[0].id = 123;
    strcpy(people[0].name, "Alice");
    people[0].age = 25;
    strcpy(people[0].occupation, "painter");
    
    people[1].id = 456;
    strcpy(people[1].name, "Bob");
    people[1].age = 30;
    strcpy(people[1].occupation, "programmer");
    
    people[2].id = 789;
    strcpy(people[2].name, "Charlie");
    people[2].age = 40;
    strcpy(people[2].occupation, "chef");
    
    people[3].id = 101;
    strcpy(people[3].name, "Dave");
    people[3].age = 50;
    strcpy(people[3].occupation, "musician");
    
    people[4].id = 202;
    strcpy(people[4].name, "Eve");
    people[4].age = 35;
    strcpy(people[4].occupation, "scientist");
    
    // Querying the database
    printf("Welcome to the surreal database querying program!\n");
    printf("Please enter an occupation to filter by: ");
    char occupation_filter[20];
    scanf("%s", occupation_filter);
    
    printf("\nSearching for people with occupation \"%s\"...\n\n", occupation_filter);
    
    int match_count = 0; // Keeping track of number of matches
    
    for(int i = 0; i < 5; i++) {
        if(strcmp(people[i].occupation, occupation_filter) == 0) { // If occupation matches filter
            print_person(people[i]); // Print the person's details
            match_count++; // Increment match count
        }
    }
    
    if(match_count == 0) {
        printf("There were no matches for occupation \"%s\".\n", occupation_filter);
    }
    else {
        printf("Found %d match%s for occupation \"%s\".\n", match_count, match_count > 1 ? "es" : "", occupation_filter);
    }
    
    return 0;
}