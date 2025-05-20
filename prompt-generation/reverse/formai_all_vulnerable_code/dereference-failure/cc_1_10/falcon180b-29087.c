//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *create_person(char *name, int age) {
    Person *person = (Person*) malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    return person;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_name(const void *a, const void *b) {
    Person *p1 = *(Person**)a;
    Person *p2 = *(Person**)b;
    return strcmp(p1->name, p2->name);
}

int compare_age(const void *a, const void *b) {
    Person *p1 = *(Person**)a;
    Person *p2 = *(Person**)b;
    return p1->age - p2->age;
}

void sort_people(Person **people, int count, bool (*comparator)(const void *, const void *)) {
    qsort(people, count, sizeof(Person*), comparator);
}

int main() {
    Person *people[MAX_SIZE];
    int count = 0;

    while (count < MAX_SIZE) {
        char name[50];
        int age;

        printf("Enter name (or leave blank to stop): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);

        people[count] = create_person(name, age);
        count++;
    }

    printf("Sorted by name:\n");
    sort_people(people, count, compare_name);
    for (int i = 0; i < count; i++) {
        print_person(people[i]);
    }

    printf("\nSorted by age:\n");
    sort_people(people, count, compare_age);
    for (int i = 0; i < count; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < count; i++) {
        delete_person(people[i]);
    }

    return 0;
}