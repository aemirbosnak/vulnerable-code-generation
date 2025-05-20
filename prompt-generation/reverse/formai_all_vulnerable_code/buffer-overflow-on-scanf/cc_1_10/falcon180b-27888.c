//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float weight;
} person;

int main() {
    int choice;
    person user;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", user.name);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your weight: ");
    scanf("%f", &user.weight);

    do {
        printf("\nSelect an option:\n");
        printf("1. Track exercise\n");
        printf("2. Track diet\n");
        printf("3. View progress\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Track exercise
                printf("Enter the type of exercise: ");
                scanf("%s", user.name);
                printf("Enter the duration of exercise (in minutes): ");
                scanf("%d", &user.age);
                printf("Enter the intensity of exercise (1-10): ");
                scanf("%f", &user.weight);
                break;

            case 2: // Track diet
                printf("Enter the food item: ");
                scanf("%s", user.name);
                printf("Enter the quantity: ");
                scanf("%d", &user.age);
                printf("Enter the calorie count: ");
                scanf("%f", &user.weight);
                break;

            case 3: // View progress
                printf("Name: %s\n", user.name);
                printf("Age: %d\n", user.age);
                printf("Weight: %f\n", user.weight);
                break;

            case 4: // Exit
                printf("Exiting program...\n");
                break;

            default: // Invalid input
                printf("Invalid choice, please try again.\n");
        }
    } while(choice!= 4);

    return 0;
}