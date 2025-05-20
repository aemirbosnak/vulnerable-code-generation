//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int id;
} Person;

void create_person(Person *person, char *name, int age, int id) {
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    person->id = id;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("ID: %d\n", person->id);
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_persons(const void *a, const void *b) {
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
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[100];
        int age, id;

        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter ID: ");
        scanf("%d", &id);

        create_person(people[num_people], name, age, id);
        num_people++;
    }

    qsort(people, num_people, sizeof(Person), compare_persons);

    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
        delete_person(people[i]);
    }

    return 0;
}