//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
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
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_age(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    if (person_a->age > person_b->age) {
        return 1;
    } else if (person_a->age < person_b->age) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[100];
        int age;

        printf("Enter name (or type 'exit' to finish): ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);

        create_person(people[num_people], name, age);
        num_people++;
    }

    qsort(people, num_people, sizeof(Person *), compare_age);

    printf("Sorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(people[i]);
    }

    return 0;
}