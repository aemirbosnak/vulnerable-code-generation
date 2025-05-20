//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEP_PER_KM 1000
#define CALORIES_PER_KG_PER_KM 0.05
#define USER_COUNT 5

typedef struct {
    int id;
    int steps;
    int calorie_goal;
    float calories;
    float distance;
} User;

User users[USER_COUNT];

void initialize_users() {
    for (int i = 0; i < USER_COUNT; ++i) {
        users[i].id = i + 1;
        users[i].calorie_goal = 5000;
    }
}

void display_menu() {
    printf("\n-------------------Fitness Tracker-------------------\n");
    printf("1. Track steps\n");
    printf("2. View statistics\n");
    printf("3. Set daily step goal\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    int steps;
    int user_id;

    initialize_users();

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter user ID: ");
                scanf("%d", &user_id);
                printf("Enter number of steps: ");
                scanf("%d", &steps);

                for (int i = 0; i < USER_COUNT; ++i) {
                    if (users[i].id == user_id) {
                        users[i].steps += steps;
                        users[i].calories += users[i].steps * CALORIES_PER_KG_PER_KM;
                        users[i].distance += steps * (1.0 / STEP_PER_KM);
                        break;
                    }
                }
                break;

            case 2:
                for (int i = 0; i < USER_COUNT; ++i) {
                    printf("\nUser %d:\n", users[i].id);
                    printf("Steps: %d\n", users[i].steps);
                    printf("Calories: %d\n", (int)users[i].calories);
                    printf("Distance: %.2f km\n", users[i].distance);
                }
                break;

            case 3:
                printf("Enter user ID: ");
                int goal_id;
                scanf("%d", &goal_id);
                printf("Enter daily step goal: ");
                int goal;
                scanf("%d", &goal);

                for (int i = 0; i < USER_COUNT; ++i) {
                    if (users[i].id == goal_id) {
                        users[i].calorie_goal = goal;
                        break;
                    }
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}