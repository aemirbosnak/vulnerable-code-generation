//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

Person *create_person(char *name, int age) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    return person;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int compare_age(const void *a, const void *b) {
    Person *p1 = *(Person **)a;
    Person *p2 = *(Person **)b;

    if (p1->age < p2->age) {
        return -1;
    } else if (p1->age > p2->age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[50];
        int age;
        printf("Enter name and age of a person (or 'done' to finish):\n");
        scanf("%s %d", name, &age);
        if (strcmp(name, "done")!= 0) {
            people[num_people] = create_person(name, age);
            num_people++;
        }
    }

    qsort(people, num_people, sizeof(Person *), compare_age);

    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    return 0;
}