//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DAYS_PER_WEEK 7
#define MAX_NAME_LENGTH 20
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps[MAX_DAYS_PER_WEEK];
    int calories[MAX_DAYS_PER_WEEK];
    float distance[MAX_DAYS_PER_WEEK];
} UserData;

UserData current_user, previous_user;
int current_day = 0;
int previous_day = 0;

void init_users() {
    memset(&current_user, 0, sizeof(UserData));
    memset(&previous_user, 0, sizeof(UserData));
}

void get_user_data() {
    printf("Enter your name: ");
    scanf("%s", current_user.name);

    printf("Enter daily steps: ");
    for (int i = 0; i < MAX_DAYS_PER_WEEK; i++) {
        scanf("%d", &current_user.steps[i]);
    }

    printf("Enter daily calories burned: ");
    for (int i = 0; i < MAX_DAYS_PER_WEEK; i++) {
        scanf("%d", &current_user.calories[i]);
    }

    printf("Enter daily distance traveled (in km): ");
    for (int i = 0; i < MAX_DAYS_PER_WEEK; i++) {
        scanf("%f", &current_user.distance[i]);
    }
}

void display_user_data(UserData user) {
    printf("\nWeekly Stats for %s:\n", user.name);
    printf("----------------------\n");
    int total_steps = 0;
    int total_calories = 0;
    float total_distance = 0.0;

    for (int i = 0; i < MAX_DAYS_PER_WEEK; i++) {
        printf("Day %d:\n", i + 1);
        printf("Steps: %d\n", user.steps[i]);
        printf("Calories: %d\n", user.calories[i]);
        printf("Distance: %.2f km\n", user.distance[i]);

        total_steps += user.steps[i];
        total_calories += user.calories[i];
        total_distance += user.distance[i];
    }

    printf("\nTotal weekly stats:\n");
    printf("--------------------\n");
    printf("Steps: %d\n", total_steps);
    printf("Calories: %d\n", total_calories);
    printf("Distance: %.2f km\n", total_distance);
}

int main() {
    init_users();

    if (current_day == 0) {
        printf("First time using the Fitness Tracker. Please enter your data.\n");
        get_user_data();
    } else {
        printf("Welcome back, %s! Your current weekly stats are:\n", current_user.name);
        display_user_data(current_user);

        printf("\nYour previous weekly stats were:\n");
        previous_day += MAX_DAYS_PER_WEEK;
        if (previous_day > MAX_DAYS_PER_WEEK) {
            previous_day -= MAX_DAYS_PER_WEEK;
            printf("Last week's data is not available.\n");
        } else {
            get_user_data();
            display_user_data(previous_user);
        }
    }

    current_day++;

    return 0;
}