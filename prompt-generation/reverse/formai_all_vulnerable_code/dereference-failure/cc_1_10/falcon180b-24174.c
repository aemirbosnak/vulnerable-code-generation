//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a person
typedef struct {
    char *name;
    int age;
    float height;
    float weight;
} Person;

// Function to create a new person
Person *create_person(char *name, int age, float height, float weight) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = (char *) malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    person->height = height;
    person->weight = weight;
    return person;
}

// Function to print a person's information
void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
    printf("Weight: %.2f\n", person->weight);
}

// Function to delete a person and free their memory
void delete_person(Person *person) {
    free(person->name);
    free(person);
}

// Function to compare two people by age
int compare_age(const void *a, const void *b) {
    Person *person_a = *(Person **) a;
    Person *person_b = *(Person **) b;
    return (person_a->age - person_b->age);
}

// Function to sort an array of people by age
void sort_people(Person **people, int count) {
    qsort(people, count, sizeof(Person *), compare_age);
}

int main() {
    int count;
    scanf("%d", &count);
    Person **people = (Person **) malloc(count * sizeof(Person *));
    for (int i = 0; i < count; i++) {
        char name[100];
        scanf(" %[^\n]", name);
        int age;
        scanf("%d", &age);
        float height, weight;
        scanf(" %f %f", &height, &weight);
        people[i] = create_person(name, age, height, weight);
    }
    sort_people(people, count);
    for (int i = 0; i < count; i++) {
        print_person(people[i]);
        delete_person(people[i]);
    }
    free(people);
    return 0;
}