//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[30];
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    time_t last_updated;
} User;

User user = {"John Doe", 25, 75, 180, 0, 0, 0};

void update_user_data(User *user) {
    printf("Enter your current weight (in kg): ");
    scanf("%d", &user->weight);
    printf("Enter your current height (in cm): ");
    scanf("%d", &user->height);
    user->steps = 0;
    user->calories = 0;
    user->last_updated = time(NULL);
}

void display_user_data(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %d kg\n", user.weight);
    printf("Height: %d cm\n", user.height);
    printf("Steps: %d\n", user.steps);
    printf("Calories burned: %d\n", user.calories);
    printf("Last updated: %s\n", ctime(&user.last_updated));
}

void track_steps(User *user) {
    int steps_taken;
    printf("Enter the number of steps you took: ");
    scanf("%d", &steps_taken);
    user->steps += steps_taken;
    user->calories += steps_taken * 5;
    user->last_updated = time(NULL);
}

int main() {
    int choice;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Update user data\n2. Display user data\n3. Track steps\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            update_user_data(&user);
            break;
        case 2:
            display_user_data(user);
            break;
        case 3:
            track_steps(&user);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (1);
    return 0;
}