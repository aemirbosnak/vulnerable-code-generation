//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_ages(const void *a, const void *b) {
    Person *person_a = *(Person **)a;
    Person *person_b = *(Person **)b;

    if (person_a->age < person_b->age) {
        return -1;
    } else if (person_a->age > person_b->age) {
        return 1;
    } else {
        return 0;
    }
}

void surrealist_search(Person *people, int num_people, char *name, int (*comparator)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), comparator);

    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Surrealist search found %s, age %d\n", people[i].name, people[i].age);
            return;
        }
    }

    printf("Surrealist search did not find %s\n", name);
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE && scanf("%s %d", people[num_people].name, &people[num_people].age)!= EOF) {
        num_people++;
    }

    surrealist_search(people, num_people, "Alice", compare_names);
    surrealist_search(people, num_people, "25", compare_ages);

    return 0;
}