//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORKOUTS 50
#define MAX_EXERCISES 20
#define MAX_NAME_LENGTH 50
#define MAX_ACTIVITY_LEVEL 5
#define MAX_DURATION 24

typedef struct {
    char name[MAX_NAME_LENGTH];
    int activity_level;
    int duration;
} workout;

typedef struct {
    int num_workouts;
    workout workouts[MAX_WORKOUTS];
} user;

int main() {
    user current_user = {0};
    int choice;
    char name[MAX_NAME_LENGTH];

    do {
        printf("Welcome to the fitness tracker!\n");
        printf("1. Create a new account\n");
        printf("2. Log in to an existing account\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter your name: ");
            scanf("%s", name);
            strcpy(current_user.workouts[0].name, name);
            current_user.num_workouts = 1;
        } else if (choice == 2) {
            printf("Enter your name: ");
            scanf("%s", name);
            for (int i = 0; i < current_user.num_workouts; i++) {
                if (strcmp(current_user.workouts[i].name, name) == 0) {
                    printf("Welcome back, %s!\n", name);
                    break;
                }
            }
        } else if (choice == 3) {
            printf("Thank you for using the fitness tracker!\n");
        } else {
            printf("Invalid choice.\n");
        }

    } while (choice!= 3);

    return 0;
}