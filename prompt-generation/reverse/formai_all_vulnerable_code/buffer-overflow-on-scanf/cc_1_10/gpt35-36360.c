//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the User Struct
typedef struct User {
    char username[50];
    int age;
    float weight;
    float height;
    float goal_weight;
    float goal_calories;
} User;

// Define the Exercise Struct
typedef struct Exercise {
    char name[50];
    int calories;
} Exercise;

// Define the Tracker Struct
typedef struct Tracker {
    int date;
    int month;
    int year;
    float calories_consumed;
    float calories_burned;
} Tracker;

// Define the main function
int main() {
    // Initialize the user
    User user;
    printf("Please enter your username: \n");
    scanf("%s", &user.username);
    printf("Please enter your age: \n");
    scanf("%d", &user.age);
    printf("Please enter your weight in kg: \n");
    scanf("%f", &user.weight);
    printf("Please enter your height in m: \n");
    scanf("%f", &user.height);
    printf("Please enter your goal weight in kg: \n");
    scanf("%f", &user.goal_weight);
    printf("Please enter your goal calories per day: \n");
    scanf("%f", &user.goal_calories);

    // Initialize the exercises
    Exercise exercises[5];
    strcpy(exercises[0].name, "Running");
    exercises[0].calories = 700;
    strcpy(exercises[1].name, "Cycling");
    exercises[1].calories = 500;
    strcpy(exercises[2].name, "Swimming");
    exercises[2].calories = 600;
    strcpy(exercises[3].name, "Weightlifting");
    exercises[3].calories = 400;
    strcpy(exercises[4].name, "Yoga");
    exercises[4].calories = 200;

    // Initialize the tracker array for 1 week
    Tracker tracker[7];

    // Loop through each day and track the user's information
    for(int i=0; i<7; i++) {
        printf("Please enter the date for day %d (DD MM YYYY): \n", i+1);
        scanf("%d %d %d", &tracker[i].date, &tracker[i].month, &tracker[i].year);
        printf("Please enter the number of calories consumed for day %d: \n", i+1);
        scanf("%f", &tracker[i].calories_consumed);
        printf("Please enter the type of exercise done for day %d (0 for none, 1 for running, 2 for cycling, 3 for swimming, 4 for weightlifting, 5 for yoga): \n", i+1);

        int exerciseChoice;
        scanf("%d", &exerciseChoice);

        if(exerciseChoice != 0) {
            float minutes;
            printf("Please enter the number of minutes spent on %s: \n", exercises[exerciseChoice-1].name);
            scanf("%f", &minutes);
            tracker[i].calories_burned = exercises[exerciseChoice-1].calories * (minutes / 60);
        } else {
            tracker[i].calories_burned = 0;
        }
    }

    // Calculate the total calories consumed and burned for the week
    float total_calories_consumed = 0;
    float total_calories_burned = 0;

    for(int i=0; i<7; i++) {
        total_calories_consumed += tracker[i].calories_consumed;
        total_calories_burned += tracker[i].calories_burned;
    }

    // Calculate the user's weight loss progress
    float weight_loss = user.weight - user.goal_weight;
    float calories_per_kg_lost = weight_loss * 7700;
    float days_to_goal = calories_per_kg_lost / user.goal_calories;

    // Print the user's daily and weekly progress
    printf("Daily Progress:\n");
    for(int i=0; i<7; i++) {
        printf("%d/%d/%d - Consumed: %.2f calories, Burned: %.2f calories\n", tracker[i].date, tracker[i].month, tracker[i].year, tracker[i].calories_consumed, tracker[i].calories_burned);
    }

    printf("\nWeekly Progress:\n");
    printf("Calories Consumed: %.2f\n", total_calories_consumed);
    printf("Calories Burned: %.2f\n", total_calories_burned);
    printf("Net Calories: %.2f\n", total_calories_consumed - total_calories_burned);
    printf("Goal Calories: %.2f\n", user.goal_calories);
    printf("Days to Goal: %.2f\n", days_to_goal);

    printf("\nThank you for using the fitness tracker!\n");

    return 0;
}