//Falcon-180B DATASET v1.0 Category: Error handling ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

void add_person(Person** people, int* num_people) {
    Person* new_person = malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    printf("Enter the name of the person: ");
    scanf("%s", new_person->name);

    printf("Enter the age of the person: ");
    scanf("%d", &new_person->age);

    (*num_people)++;
    (*people) = realloc(*people, (*num_people) * sizeof(Person));
    if (*people == NULL) {
        printf("Error: Memory reallocation failed\n");
        exit(1);
    }

    (*people)[*num_people - 1] = *new_person;
}

void print_people(Person* people, int num_people) {
    printf("Name\tAge\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\n", people[i].name, people[i].age);
    }
}

int main() {
    Person* people = NULL;
    int num_people = 0;

    add_person(&people, &num_people);
    add_person(&people, &num_people);
    add_person(&people, &num_people);

    print_people(people, num_people);

    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}