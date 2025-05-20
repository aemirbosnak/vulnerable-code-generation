//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24
#define DAYS_PER_WEEK 7
#define STEPS_PER_MILE 2000
#define CALORIES_PER_STEP 0.04
#define MINUTES_PER_MILE 30
#define MAX_STEPS 10000
#define MAX_CALORIES 5000
#define MAX_DISTANCE 26.2

struct user {
    char name[50];
    int steps;
    double calories;
    double distance;
};

void initialize_user(struct user *user) {
    strcpy(user->name, "Unknown");
    user->steps = 0;
    user->calories = 0;
    user->distance = 0;
}

void update_user(struct user *user, int steps, double calories, double distance) {
    user->steps += steps;
    user->calories += calories;
    user->distance += distance;
}

void display_user(struct user user) {
    printf("Name: %s\n", user.name);
    printf("Steps: %d\n", user.steps);
    printf("Calories burned: %.2f\n", user.calories);
    printf("Distance traveled: %.2f miles\n", user.distance);
}

int main(void) {
    time_t now;
    struct tm *t;
    int steps, calories, distance;
    struct user user;

    initialize_user(&user);

    time(&now);
    t = localtime(&now);

    while (1) {
        printf("\n");
        printf("Current date and time: %s", asctime(t));
        printf("\n");

        printf("Enter number of steps taken today: ");
        scanf("%d", &steps);

        printf("Enter number of calories burned today: ");
        scanf("%lf", &calories);

        printf("Enter distance traveled today (in miles): ");
        scanf("%lf", &distance);

        update_user(&user, steps, calories, distance);

        display_user(user);

        if (user.steps >= MAX_STEPS || user.calories >= MAX_CALORIES || user.distance >= MAX_DISTANCE) {
            printf("\nCongratulations! You have reached your fitness goal!\n");
            break;
        }

        printf("\nPress any key to continue...");
        getchar();
    }

    return 0;
}