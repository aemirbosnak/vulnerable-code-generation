//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *p, char *name, int age) {
    p->name = (char *)malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->age = age;
}

void print_person(Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

void delete_person(Person *p) {
    free(p->name);
    free(p);
}

int compare_persons(Person *a, Person *b) {
    if (a->age > b->age) {
        return 1;
    } else if (a->age < b->age) {
        return -1;
    } else {
        return 0;
    }
}

void search_person(Person *people, int size, char *name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found person with name %s\n", name);
            print_person(&people[i]);
            return;
        }
    }
    printf("Person not found\n");
}

int main() {
    Person *people = (Person *)malloc(MAX_SIZE * sizeof(Person));
    int size = 0;

    create_person(&people[size], "Romeo", 25);
    create_person(&people[size], "Juliet", 23);
    create_person(&people[size], "Tybalt", 30);
    create_person(&people[size], "Mercutio", 28);
    create_person(&people[size], "Benvolio", 22);

    size++;

    printf("Sorted by age:\n");
    qsort(people, size, sizeof(Person), compare_persons);
    for (int i = 0; i < size; i++) {
        print_person(&people[i]);
    }

    char name[20];
    printf("\nEnter name to search: ");
    scanf("%s", name);

    search_person(people, size, name);

    for (int i = 0; i < size; i++) {
        delete_person(&people[i]);
    }
    free(people);

    return 0;
}