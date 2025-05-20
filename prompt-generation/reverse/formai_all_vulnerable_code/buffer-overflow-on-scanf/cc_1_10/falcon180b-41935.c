//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    int age;
} Person;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_ages(const void *a, const void *b) {
    Person *p1 = *(Person **)a;
    Person *p2 = *(Person **)b;
    return p1->age - p2->age;
}

void print_person(Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    Person *people[MAX_ENTRIES];
    int num_people = 0;

    printf("Enter the number of people: ");
    scanf("%d", &num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Enter the name and age of person %d: ", i + 1);
        scanf("%s %d", people[i]->name, &people[i]->age);
    }

    qsort(people, num_people, sizeof(Person), compare_names);
    printf("Sorted by name:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    qsort(people, num_people, sizeof(Person), compare_ages);
    printf("\nSorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    return 0;
}