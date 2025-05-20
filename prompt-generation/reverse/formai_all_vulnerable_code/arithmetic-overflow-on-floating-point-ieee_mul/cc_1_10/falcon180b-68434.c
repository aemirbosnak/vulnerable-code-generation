//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct User {
    char name[50];
    int age;
    float weight;
    float height;
};

void createUser() {
    struct User user;

    printf("Enter your name: ");
    scanf("%s", user.name);

    printf("Enter your age: ");
    scanf("%d", &user.age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &user.weight);

    printf("Enter your height (in cm): ");
    scanf("%f", &user.height);

    printf("\nUser created successfully!\n");
}

void displayUserInfo(struct User user) {
    printf("\nUser Information:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f kg\n", user.weight);
    printf("Height: %f cm\n", user.height);
}

void calculateBMI(struct User user) {
    float bmi;

    bmi = user.weight / (user.height * user.height);

    printf("\nBMI: %f", bmi);

    if (bmi < 18.5)
        printf(" (Underweight)\n");
    else if (bmi >= 18.5 && bmi < 25)
        printf(" (Normal weight)\n");
    else if (bmi >= 25 && bmi < 30)
        printf(" (Overweight)\n");
    else
        printf(" (Obese)\n");
}

void setFitnessGoal(struct User user) {
    char goal[50];

    printf("\nEnter your fitness goal: ");
    scanf("%s", goal);

    strcpy(user.name, goal);

    printf("\nFitness goal set successfully!\n");
}

int main() {
    int choice;
    struct User user;

    createUser();

    while (1) {
        printf("\n1. Display User Information\n2. Calculate BMI\n3. Set Fitness Goal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayUserInfo(user);
                break;

            case 2:
                calculateBMI(user);
                break;

            case 3:
                setFitnessGoal(user);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}