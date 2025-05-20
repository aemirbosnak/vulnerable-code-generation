//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    float weight;
} Person;

void add_person(Person **people, int *num_people) {
    Person *new_person = malloc(sizeof(Person));
    printf("Enter name: ");
    scanf("%s", new_person->name);
    printf("Enter age: ");
    scanf("%d", &new_person->age);
    printf("Enter weight: ");
    scanf("%f", &new_person->weight);

    *people = realloc(*people, sizeof(Person) * (*num_people + 1));
    (*people)[*num_people] = *new_person;
    (*num_people)++;

    free(new_person);
}

void print_people(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Weight: %f\n", people[i].weight);
        printf("\n");
    }
}

void sort_people(Person *people, int num_people) {
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int main() {
    Person *people = NULL;
    int num_people = 0;

    add_person(&people, &num_people);
    add_person(&people, &num_people);
    add_person(&people, &num_people);

    print_people(people, num_people);

    sort_people(people, num_people);

    print_people(people, num_people);

    free(people);

    return 0;
}