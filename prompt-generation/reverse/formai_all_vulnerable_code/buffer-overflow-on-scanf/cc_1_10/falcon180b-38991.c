//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

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

void surrealist_database(Person *people, int num_people) {
    qsort(people, num_people, sizeof(Person), compare_names);
    printf("Surrealist Database:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Enter a name (or type 'done' to finish): ");
        char name[100];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter an age: ");
        int age;
        scanf("%d", &age);

        people[num_people].name = malloc(strlen(name) + 1);
        strcpy(people[num_people].name, name);
        people[num_people].age = age;
        num_people++;
    }

    surrealist_database(people, num_people);

    return 0;
}