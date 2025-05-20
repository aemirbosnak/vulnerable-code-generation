//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} person;

person *create_person(char *name, int age) {
    person *new_person = (person *)malloc(sizeof(person));
    new_person->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_person->name, name);
    new_person->age = age;
    return new_person;
}

void print_person(person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

int compare_names(const void *a, const void *b) {
    person *p1 = *(person **)a;
    person *p2 = *(person **)b;
    return strcmp(p1->name, p2->name);
}

int compare_ages(const void *a, const void *b) {
    person *p1 = *(person **)a;
    person *p2 = *(person **)b;
    return p1->age - p2->age;
}

void sort_people_by_name(person **people, int n) {
    qsort(people, n, sizeof(person *), compare_names);
}

void sort_people_by_age(person **people, int n) {
    qsort(people, n, sizeof(person *), compare_ages);
}

int main() {
    int n;
    scanf("%d", &n);

    person **people = (person **)malloc(n * sizeof(person *));

    for (int i = 0; i < n; i++) {
        char name[MAX_SIZE];
        scanf("%s", name);
        int age;
        scanf("%d", &age);

        people[i] = create_person(name, age);
    }

    sort_people_by_name(people, n);

    printf("Sorted by name:\n");
    for (int i = 0; i < n; i++) {
        print_person(people[i]);
    }

    sort_people_by_age(people, n);

    printf("\nSorted by age:\n");
    for (int i = 0; i < n; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < n; i++) {
        free(people[i]->name);
        free(people[i]);
    }
    free(people);

    return 0;
}