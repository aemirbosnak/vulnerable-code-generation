//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    char* name;
    int age;
    float height;
    int weight;
} Person;

Person* create_person(char* name, int age, float height, int weight) {
    Person* person = (Person*)malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->height = height;
    person->weight = weight;
    return person;
}

void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
    printf("Weight: %d\n", person->weight);
}

void destroy_person(Person* person) {
    free(person->name);
    free(person);
}

int main() {
    char input[MAX_SIZE];
    Person* people[MAX_SIZE];
    int count = 0;

    printf("Enter person details (name age height weight):\n");
    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        char* name = strtok(input, " ");
        int age = atoi(strtok(NULL, " "));
        float height = atof(strtok(NULL, " "));
        int weight = atoi(strtok(NULL, " "));

        if (count >= MAX_SIZE) {
            printf("Maximum number of people reached.\n");
            break;
        }

        people[count] = create_person(name, age, height, weight);
        count++;
    }

    printf("\nPeople:\n");
    for (int i = 0; i < count; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < count; i++) {
        destroy_person(people[i]);
    }

    return 0;
}