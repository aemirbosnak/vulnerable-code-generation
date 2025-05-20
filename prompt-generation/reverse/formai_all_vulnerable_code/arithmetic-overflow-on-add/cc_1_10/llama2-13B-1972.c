//LLAMA2-13B DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 100

typedef struct {
    char *name;
    int age;
} person_t;

typedef struct {
    person_t *people;
    int num_people;
} party_t;

void add_person(party_t *party, char *name, int age) {
    person_t *new_person = (person_t *)malloc(sizeof(person_t));
    new_person->name = name;
    new_person->age = age;
    party->people = realloc(party->people, (party->num_people + 1) * sizeof(person_t));
    party->people[party->num_people] = *new_person;
    party->num_people++;
}

void print_party(party_t *party) {
    for (int i = 0; i < party->num_people; i++) {
        printf("%s is %d years old.\n", party->people[i].name, party->people[i].age);
    }
}

int main() {
    party_t party;

    // Initialize party with some people
    add_person(&party, "Alice", 25);
    add_person(&party, "Bob", 30);
    add_person(&party, "Charlie", 35);

    // Add more people to the party
    add_person(&party, "David", 20);
    add_person(&party, "Eve", 25);
    add_person(&party, "Frank", 30);

    // Print the party
    print_party(&party);

    return 0;
}