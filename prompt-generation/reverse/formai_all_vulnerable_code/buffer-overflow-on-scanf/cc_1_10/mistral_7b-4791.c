//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define STEP_LENGTH 0.0282 // meters
#define CALORIES_PER_KM 8.1 // kilojoules

typedef struct {
    char name[30];
    int steps;
    float calories;
    float distance;
} User;

void get_user_input(User *user) {
    printf("What's your name? ");
    scanf("%s", user->name);
    printf("How many steps have you taken today? ");
    scanf("%d", &user->steps);
}

void display_user_data(User user) {
    printf("\nName: %s", user.name);
    printf("\nSteps: %d", user.steps);
    printf("\nCalories: %.2f kJ", user.calories);
    printf("\nDistance: %.2f km\n", user.distance);
}

void calculate_metrics(User *user) {
    user->calories = user->steps * CALORIES_PER_KM * STEP_LENGTH;
    user->distance = user->steps * STEP_LENGTH;
}

int main() {
    srand(time(NULL));
    User user;

    while (1) {
        get_user_input(&user);
        calculate_metrics(&user);
        display_user_data(user);
        printf("\nDo you want to enter another day's data? (y/n)\n");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}