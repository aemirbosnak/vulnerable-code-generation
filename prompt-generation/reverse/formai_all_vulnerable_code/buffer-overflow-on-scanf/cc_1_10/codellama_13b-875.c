//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_DAYS 365
#define MAX_EXERCISES 10

struct User {
    char name[256];
    int age;
    int height;
    int weight;
    int daily_steps;
    int daily_calories;
    int exercise_time;
    int exercise_type;
};

struct User users[MAX_USERS];

int main() {
    int n_users, n_days, n_exercises;
    char user_input[256];

    // Get user input for number of users, days, and exercises
    printf("Enter number of users: ");
    scanf("%d", &n_users);
    printf("Enter number of days: ");
    scanf("%d", &n_days);
    printf("Enter number of exercises: ");
    scanf("%d", &n_exercises);

    // Initialize users
    for (int i = 0; i < n_users; i++) {
        struct User user = {0};
        users[i] = user;
    }

    // Get user input for each user's name, age, height, weight, daily steps, and daily calories
    for (int i = 0; i < n_users; i++) {
        printf("Enter name: ");
        scanf("%s", users[i].name);
        printf("Enter age: ");
        scanf("%d", &users[i].age);
        printf("Enter height: ");
        scanf("%d", &users[i].height);
        printf("Enter weight: ");
        scanf("%d", &users[i].weight);
        printf("Enter daily steps: ");
        scanf("%d", &users[i].daily_steps);
        printf("Enter daily calories: ");
        scanf("%d", &users[i].daily_calories);
    }

    // Get user input for each exercise
    for (int i = 0; i < n_exercises; i++) {
        printf("Enter exercise name: ");
        scanf("%s", user_input);
        printf("Enter exercise type (1-3): ");
        scanf("%d", &users[i].exercise_type);
        printf("Enter exercise time: ");
        scanf("%d", &users[i].exercise_time);
    }

    // Calculate total calories burned per day
    for (int i = 0; i < n_users; i++) {
        int total_calories_burned = 0;
        for (int j = 0; j < n_days; j++) {
            int calories_burned = 0;
            for (int k = 0; k < n_exercises; k++) {
                if (users[i].exercise_type == k + 1) {
                    calories_burned += users[i].exercise_time * users[i].daily_calories;
                }
            }
            total_calories_burned += calories_burned;
        }
        printf("User %d burned %d calories per day.\n", i, total_calories_burned);
    }

    return 0;
}