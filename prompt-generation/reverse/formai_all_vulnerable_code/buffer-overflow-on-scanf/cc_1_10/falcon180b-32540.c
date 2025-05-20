//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float weight;
} Person;

void add_person(Person *people, int *num_people) {
    printf("Enter name: ");
    scanf("%s", people[*num_people].name);

    printf("Enter age: ");
    scanf("%d", &people[*num_people].age);

    printf("Enter weight: ");
    scanf("%f", &people[*num_people].weight);

    (*num_people)++;
}

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight: %f\n\n", person.weight);
}

void sort_people(Person *people, int num_people, int (*compare)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b) {
    return ((Person*)a)->age - ((Person*)b)->age;
}

int compare_weight(const void *a, const void *b) {
    return ((Person*)a)->weight - ((Person*)b)->weight;
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    add_person(people, &num_people);
    add_person(people, &num_people);
    add_person(people, &num_people);

    printf("Unsorted:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    sort_people(people, num_people, compare_age);
    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    sort_people(people, num_people, compare_weight);
    printf("Sorted by weight:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    return 0;
}