//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
    int steps;
    int calories;
} user;

void create_user(user* u) {
    printf("Enter your name: ");
    scanf("%s", u->name);
    printf("Enter your age: ");
    scanf("%d", &u->age);
    printf("Enter your height in meters: ");
    scanf("%f", &u->height);
    printf("Enter your weight in kilograms: ");
    scanf("%f", &u->weight);
    u->bmi = u->weight / (u->height * u->height);
    u->steps = 0;
    u->calories = 0;
}

void display_user(user u) {
    printf("Name: %s\n", u.name);
    printf("Age: %d\n", u.age);
    printf("Height: %f meters\n", u.height);
    printf("Weight: %f kilograms\n", u.weight);
    printf("BMI: %f\n", u.bmi);
    printf("Steps taken: %d\n", u.steps);
    printf("Calories burned: %d\n", u.calories);
}

void update_steps(user* u) {
    printf("Enter the number of steps taken: ");
    scanf("%d", &u->steps);
    u->calories += (u->steps * 0.03) * u->weight;
}

void main() {
    user u;
    create_user(&u);

    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Display user information\n");
        printf("2. Update steps\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_user(u);
                break;
            case 2:
                update_steps(&u);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);
}