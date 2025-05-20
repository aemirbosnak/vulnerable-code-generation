//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
/*
 * Unique C Fitness Tracker Example Program
 *
 * This program tracks the user's daily fitness activities and provides
 * a summary of their progress.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ACTIVITIES 10
#define MAX_DAYS 30

struct Activity {
    char name[20];
    int duration;
};

struct User {
    char name[20];
    struct Activity activities[MAX_ACTIVITIES];
    int num_activities;
};

struct Progress {
    int total_duration;
    int total_calories;
    int total_steps;
};

void print_welcome_message() {
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter your name: ");
}

void print_menu() {
    printf("Main Menu\n");
    printf("1. Add activity\n");
    printf("2. View progress\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void add_activity(struct User *user) {
    printf("Enter activity name: ");
    scanf("%s", user->activities[user->num_activities].name);
    printf("Enter activity duration (in minutes): ");
    scanf("%d", &user->activities[user->num_activities].duration);
    user->num_activities++;
}

void view_progress(struct User *user) {
    struct Progress progress = { 0 };
    for (int i = 0; i < user->num_activities; i++) {
        progress.total_duration += user->activities[i].duration;
        progress.total_calories += calculate_calories(user->activities[i].duration);
        progress.total_steps += calculate_steps(user->activities[i].duration);
    }
    printf("Total duration: %d minutes\n", progress.total_duration);
    printf("Total calories burned: %d\n", progress.total_calories);
    printf("Total steps taken: %d\n", progress.total_steps);
}

int calculate_calories(int duration) {
    // This function calculates the number of calories burned based on the duration of the activity
    return duration * 5;
}

int calculate_steps(int duration) {
    // This function calculates the number of steps taken based on the duration of the activity
    return duration * 10;
}

int main() {
    struct User user;
    user.num_activities = 0;
    print_welcome_message();
    scanf("%s", user.name);
    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_activity(&user);
                break;
            case 2:
                view_progress(&user);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}