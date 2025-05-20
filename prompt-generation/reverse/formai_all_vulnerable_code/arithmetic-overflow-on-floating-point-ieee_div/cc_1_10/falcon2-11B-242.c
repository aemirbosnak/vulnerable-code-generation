//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    float height;
    float weight;
    float bmi;
} person;

int main() {
    srand(time(0));
    person p1, p2, p3;

    // Create three persons
    printf("Enter name for Person 1: ");
    scanf("%s", p1.name);

    printf("Enter height for Person 1: ");
    scanf("%f", &p1.height);

    printf("Enter weight for Person 1: ");
    scanf("%f", &p1.weight);

    printf("Enter name for Person 2: ");
    scanf("%s", p2.name);

    printf("Enter height for Person 2: ");
    scanf("%f", &p2.height);

    printf("Enter weight for Person 2: ");
    scanf("%f", &p2.weight);

    printf("Enter name for Person 3: ");
    scanf("%s", p3.name);

    printf("Enter height for Person 3: ");
    scanf("%f", &p3.height);

    printf("Enter weight for Person 3: ");
    scanf("%f", &p3.weight);

    // Calculate BMI
    p1.bmi = (p1.weight / (p1.height * p1.height)) * 703;
    p2.bmi = (p2.weight / (p2.height * p2.height)) * 703;
    p3.bmi = (p3.weight / (p3.height * p3.height)) * 703;

    // Print results
    printf("Person 1: %s\n", p1.name);
    printf("Height: %f\n", p1.height);
    printf("Weight: %f\n", p1.weight);
    printf("BMI: %.2f\n", p1.bmi);

    printf("Person 2: %s\n", p2.name);
    printf("Height: %f\n", p2.height);
    printf("Weight: %f\n", p2.weight);
    printf("BMI: %.2f\n", p2.bmi);

    printf("Person 3: %s\n", p3.name);
    printf("Height: %f\n", p3.height);
    printf("Weight: %f\n", p3.weight);
    printf("BMI: %.2f\n", p3.bmi);

    return 0;
}