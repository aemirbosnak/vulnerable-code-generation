//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int compare_age(const void *a, const void *b) {
    const Person *person_a = a;
    const Person *person_b = b;

    return person_a->age - person_b->age;
}

int compare_name(const void *a, const void *b) {
    const Person *person_a = a;
    const Person *person_b = b;

    return strcmp(person_a->name, person_b->name);
}

void print_people(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("%s (%d)\n", people[i].name, people[i].age);
    }
}

int main() {
    srand(time(NULL));

    Person *people = malloc(MAX_SIZE * sizeof(Person));

    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[50];
        int age = rand() % 100;

        sprintf(name, "Person %d", num_people + 1);

        people[num_people] = (Person) {
           .name = strdup(name),
           .age = age
        };

        num_people++;
    }

    printf("Unsorted:\n");
    print_people(people, num_people);

    qsort(people, num_people, sizeof(Person), compare_age);

    printf("\nSorted by age:\n");
    print_people(people, num_people);

    qsort(people, num_people, sizeof(Person), compare_name);

    printf("\nSorted by name:\n");
    print_people(people, num_people);

    free(people);

    return 0;
}