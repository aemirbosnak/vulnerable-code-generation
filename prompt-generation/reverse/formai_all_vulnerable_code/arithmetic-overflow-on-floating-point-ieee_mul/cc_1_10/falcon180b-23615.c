//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct {
    char name[MAX_STR_LEN];
    int age;
    float weight;
    float height;
} Person;

void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Weight: %f\n", person->weight);
    printf("Height: %f\n", person->height);
}

void read_person(Person* person) {
    printf("Enter name: ");
    scanf("%s", person->name);

    printf("Enter age: ");
    scanf("%d", &person->age);

    printf("Enter weight: ");
    scanf("%f", &person->weight);

    printf("Enter height: ");
    scanf("%f", &person->height);
}

void calculate_bmi(Person* person) {
    float bmi = person->weight / (person->height * person->height);
    printf("BMI: %f\n", bmi);
}

int main() {
    Person person;

    printf("Enter person details:\n");
    read_person(&person);

    printf("Details of the person:\n");
    print_person(&person);

    calculate_bmi(&person);

    return 0;
}