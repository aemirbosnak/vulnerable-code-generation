//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

typedef struct {
    char *name;
    int age;
    float height;
    float weight;
} Person;

void create_person(Person *person, char *name, int age, float height, float weight) {
    person->name = strdup(name);
    person->age = age;
    person->height = height;
    person->weight = weight;
}

void delete_person(Person *person) {
    free(person->name);
    person->name = NULL;
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    char input[100];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *name = strtok(input, ",");
        int age = atoi(strtok(NULL, ","));
        float height = atof(strtok(NULL, ","));
        float weight = atof(strtok(NULL, ","));

        if (num_people >= MAX_SIZE) {
            printf("Error: Maximum number of people exceeded.\n");
            break;
        }

        create_person(&people[num_people], name, age, height, weight);
        num_people++;
    }

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        Person *person = &people[i];
        printf("Name: %s\n", person->name);
        printf("Age: %d\n", person->age);
        printf("Height: %.2f\n", person->height);
        printf("Weight: %.2f\n", person->weight);
        printf("BMI: %.2f\n", person->weight / (person->height * person->height) * 703);
        printf("\n");
    }

    free(people);
    return 0;
}