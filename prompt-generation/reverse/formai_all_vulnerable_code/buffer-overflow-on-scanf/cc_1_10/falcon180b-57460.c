//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

struct person {
    char name[50];
    int age;
    double weight;
    double height;
    int steps;
    int calories;
};

struct date {
    int day;
    int month;
    int year;
};

void get_steps(struct person *person) {
    printf("Enter the number of steps you took today: ");
    scanf("%d", &person->steps);
}

void get_calories(struct person *person) {
    printf("Enter the number of calories you burned today: ");
    scanf("%d", &person->calories);
}

int main() {
    struct person person;
    struct date date;

    time_t now = time(NULL);
    localtime_r(&now, &date);

    printf("Enter your name: ");
    scanf("%s", person.name);

    printf("Enter your age: ");
    scanf("%d", &person.age);

    printf("Enter your weight (in kg): ");
    scanf("%lf", &person.weight);

    printf("Enter your height (in cm): ");
    scanf("%lf", &person.height);

    get_steps(&person);
    get_calories(&person);

    double bmi = person.weight / (person.height * person.height);
    double steps_per_day = person.steps / (24 * 60 * 60);
    double calories_per_day = person.calories / (24 * 60 * 60);

    printf("\nName: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight: %lf kg\n", person.weight);
    printf("Height: %lf cm\n", person.height);
    printf("BMI: %lf\n", bmi);
    printf("Steps per day: %lf\n", steps_per_day);
    printf("Calories burned per day: %d\n", calories_per_day);

    printf("\nDate: %d-%02d-%02d\n", date.year, date.month, date.day);

    return 0;
}