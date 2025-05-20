//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    int steps;
    int calories;
} User;

void create_user(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &user->weight);
    printf("Enter your height (in cm): ");
    scanf("%f", &user->height);
}

void display_user(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f kg\n", user.weight);
    printf("Height: %f cm\n", user.height);
    printf("Steps: %d\n", user.steps);
    printf("Calories burned: %d\n", user.calories);
}

void update_steps(User *user) {
    printf("Enter the number of steps taken: ");
    scanf("%d", &user->steps);
}

void update_calories(User *user) {
    printf("Enter the number of calories burned: ");
    scanf("%d", &user->calories);
}

int main() {
    User user;
    create_user(&user);
    while(1) {
        system("clear");
        display_user(user);
        printf("\n1. Update steps\n2. Update calories burned\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                update_steps(&user);
                break;
            case 2:
                update_calories(&user);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}