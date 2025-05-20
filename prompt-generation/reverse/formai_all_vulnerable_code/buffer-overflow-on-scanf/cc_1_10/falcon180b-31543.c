//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float weight;
    float height;
} Person;

void print_person(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Weight: %f\n", p.weight);
    printf("Height: %f\n", p.height);
}

int main() {
    Person person;
    char input[MAX_SIZE];
    int i = 0;

    printf("Enter your name: ");
    scanf("%s", person.name);

    while (1) {
        printf("Enter your age (or type 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        } else {
            person.age = atoi(input);
        }

        printf("Enter your weight: ");
        scanf("%f", &person.weight);

        printf("Enter your height: ");
        scanf("%f", &person.height);

        print_person(person);
        i++;
    }

    return 0;
}