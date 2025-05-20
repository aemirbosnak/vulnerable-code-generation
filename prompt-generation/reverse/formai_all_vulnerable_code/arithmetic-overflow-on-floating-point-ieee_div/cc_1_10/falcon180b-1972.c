//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    int steps;
} person;

void create_person(person *p) {
    printf("Enter your name: ");
    scanf("%s", p->name);
    printf("Enter your age: ");
    scanf("%d", &p->age);
    printf("Enter your weight in kg: ");
    scanf("%f", &p->weight);
    printf("Enter your height in cm: ");
    scanf("%f", &p->height);
    p->steps = 0;
}

void display_person(person p) {
    printf("\nName: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Weight: %.2f kg\n", p.weight);
    printf("Height: %.2f cm\n", p.height);
    printf("Steps: %d\n\n", p.steps);
}

void step_counter(person *p) {
    p->steps++;
}

float calculate_bmi(person p) {
    return p.weight / (p.height * p.height);
}

float calculate_calories_burned(person p, int steps) {
    float bmi = calculate_bmi(p);
    float calories_burned = (0.0175 * bmi) * steps;
    return calories_burned;
}

int main() {
    person user;
    create_person(&user);

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. View your profile\n");
        printf("2. Count your steps\n");
        printf("3. Calculate your BMI\n");
        printf("4. Calculate calories burned\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_person(user);
                break;
            case 2:
                step_counter(&user);
                printf("\nYou took %d steps today.\n", user.steps);
                break;
            case 3:
                printf("\nYour BMI is %.2f.\n", calculate_bmi(user));
                break;
            case 4:
                printf("\nYou burned %.2f calories today.\n", calculate_calories_burned(user, user.steps));
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice!= 5);

    return 0;
}