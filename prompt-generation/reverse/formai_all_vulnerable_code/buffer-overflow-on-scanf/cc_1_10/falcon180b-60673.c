//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100
#define MAX_NUM_PEOPLE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
} Person;

void init_person(Person* p) {
    strcpy(p->name, "");
    p->age = 0;
}

void free_person(Person* p) {
    free(p->name);
    memset(p, 0, sizeof(Person));
}

void print_person(Person* p) {
    printf("Name: %s\nAge: %d\n", p->name, p->age);
}

int main() {
    Person* people = (Person*)malloc(MAX_NUM_PEOPLE * sizeof(Person));
    if (!people) {
        printf("Error: Could not allocate memory for people.\n");
        return 1;
    }
    memset(people, 0, MAX_NUM_PEOPLE * sizeof(Person));

    int num_people = 0;
    char name[MAX_NAME_SIZE];
    int age;

    while (1) {
        printf("Enter name (leave blank to stop): ");
        scanf("%s", name);
        if (strcmp(name, "") == 0) {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);

        if (num_people >= MAX_NUM_PEOPLE) {
            printf("Error: Maximum number of people reached.\n");
            continue;
        }

        init_person(&people[num_people]);
        strncpy(people[num_people].name, name, MAX_NAME_SIZE);
        people[num_people].age = age;
        num_people++;
    }

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);
    return 0;
}