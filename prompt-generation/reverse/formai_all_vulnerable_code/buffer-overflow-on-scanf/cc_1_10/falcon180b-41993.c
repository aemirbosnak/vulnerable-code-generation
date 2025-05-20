//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[30];
    int age;
    int weight;
    int height;
    int bmi;
    time_t last_updated;
} User;

void create_user(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (in kg): ");
    scanf("%d", &user->weight);
    printf("Enter your height (in cm): ");
    scanf("%d", &user->height);
    user->bmi = (user->weight / (user->height * user->height)) * 100;
    user->last_updated = time(NULL);
    printf("User created successfully!\n");
}

void update_user(User* user) {
    printf("Enter your current weight (in kg): ");
    scanf("%d", &user->weight);
    user->bmi = (user->weight / (user->height * user->height)) * 100;
    user->last_updated = time(NULL);
    printf("User updated successfully!\n");
}

void display_user(User* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %d kg\n", user->weight);
    printf("Height: %d cm\n", user->height);
    printf("BMI: %d\n", user->bmi);
    printf("Last updated: %s\n", ctime(&user->last_updated));
}

void main() {
    User user;
    int choice;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Create user\n");
        printf("2. Update user\n");
        printf("3. Display user\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_user(&user);
                break;
            case 2:
                update_user(&user);
                break;
            case 3:
                display_user(&user);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);
}