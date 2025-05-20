//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
    float heart_rate;
    float calories_burned;
} person_t;

void calculate_bmi(person_t *person) {
    person->bmi = person->weight / (person->height * person->height);
}

void calculate_heart_rate(person_t *person) {
    person->heart_rate = 220 - person->age;
}

void calculate_calories_burned(person_t *person) {
    float mets = 3.5; // METs (metabolic equivalent) is a measure of the energy cost of physical activity
    person->calories_burned = mets * person->weight * (30 / 60);
}

void print_person_info(person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %f\n", person->height);
    printf("Weight: %f\n", person->weight);
    printf("BMI: %f\n", person->bmi);
    printf("Heart Rate: %f\n", person->heart_rate);
    printf("Calories Burned: %f\n", person->calories_burned);
}

int main() {
    person_t person;

    printf("Enter your name: ");
    scanf("%s", person.name);

    printf("Enter your age: ");
    scanf("%d", &person.age);

    printf("Enter your height in meters: ");
    scanf("%f", &person.height);

    printf("Enter your weight in kilograms: ");
    scanf("%f", &person.weight);

    calculate_bmi(&person);
    calculate_heart_rate(&person);
    calculate_calories_burned(&person);

    printf("\nYour Fitness Tracker:\n");
    print_person_info(&person);

    return 0;
}