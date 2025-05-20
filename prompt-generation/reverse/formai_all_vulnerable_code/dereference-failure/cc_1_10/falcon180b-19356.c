//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_age(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    if (person_a->age < person_b->age) {
        return -1;
    } else if (person_a->age > person_b->age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Person *people[MAX_SIZE];
    int count = 0;

    create_person(people[count++], "Alice", 25);
    create_person(people[count++], "Bob", 30);
    create_person(people[count++], "Charlie", 20);
    create_person(people[count++], "David", 35);

    qsort(people, count, sizeof(Person *), compare_age);

    printf("Sorted by age:\n");
    for (int i = 0; i < count; i++) {
        print_person(people[i]);
    }

    return 0;
}