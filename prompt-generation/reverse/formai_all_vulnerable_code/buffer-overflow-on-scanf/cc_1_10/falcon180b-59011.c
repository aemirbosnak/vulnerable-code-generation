//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    int steps;
    time_t last_updated;
} user_data;

void create_user(user_data *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &user->weight);
    printf("Enter your height (in cm): ");
    scanf("%f", &user->height);
    user->steps = 0;
    time(&user->last_updated);
}

void display_user(user_data user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f kg\n", user.weight);
    printf("Height: %f cm\n", user.height);
    printf("Steps taken: %d\n", user.steps);
    printf("Last updated: %s", ctime(&user.last_updated));
}

void update_steps(user_data *user) {
    printf("Enter the number of steps taken: ");
    scanf("%d", &user->steps);
    time(&user->last_updated);
}

void main() {
    user_data user;
    create_user(&user);
    int choice;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Display user information\n");
        printf("2. Update steps taken\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_user(user);
                break;
            case 2:
                update_steps(&user);
                display_user(user);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);
}