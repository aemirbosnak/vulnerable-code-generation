//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
} Person;

float calculate_bmi(float weight, float height) {
    return weight / (height * height);
}

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight: %f\n", person.weight);
    printf("Height: %f\n", person.height);
    printf("BMI: %f\n", person.bmi);
}

int main() {
    Person user;
    float weight, height;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", user.name);

    printf("Please enter your age: ");
    scanf("%d", &user.age);

    printf("Please enter your weight in pounds: ");
    scanf("%f", &weight);

    printf("Please enter your height in inches: ");
    scanf("%f", &height);

    user.weight = weight;
    user.height = height;
    user.bmi = calculate_bmi(weight, height);

    printf("\nUser Profile:\n");
    print_person(user);

    return 0;
}