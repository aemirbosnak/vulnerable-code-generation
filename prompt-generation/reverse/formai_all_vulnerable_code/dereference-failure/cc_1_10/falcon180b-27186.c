//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
} person_t;

person_t *generate_person(int max_age) {
    person_t *person = malloc(sizeof(person_t));

    person->name = malloc(16 * sizeof(char));
    sprintf(person->name, "Mr. %d", rand() % max_age + 1);

    person->age = rand() % max_age + 1;

    person->occupation = malloc(32 * sizeof(char));
    sprintf(person->occupation, "CEO of %s", rand() % 2? "Microsoft" : "Apple");

    return person;
}

void print_person(person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
}

int main() {
    srand(time(NULL));

    int max_age = 70;
    int num_people = 5;

    person_t **people = malloc(num_people * sizeof(person_t *));

    for (int i = 0; i < num_people; i++) {
        people[i] = generate_person(max_age);
        print_person(people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        free(people[i]->name);
        free(people[i]->occupation);
        free(people[i]);
    }
    free(people);

    return 0;
}