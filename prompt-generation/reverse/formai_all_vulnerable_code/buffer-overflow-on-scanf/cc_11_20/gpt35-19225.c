//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct User {
    char name[50];
    int age;
    double height;
    double weight;
};

struct Exercise {
    char name[50];
    double calories_per_min;
};

struct Workout {
    char date[20];
    struct Exercise exercise;
    int duration;
};

int main() {
    struct User user;
    struct Exercise exercises[5];
    struct Workout workouts[7];
    int option;

    printf("Welcome to the C Fitness Tracker!\n\n");

    printf("Please enter your name: ");
    fgets(user.name, 50, stdin);
    strtok(user.name, "\n"); // removes newline character from input

    printf("\nHello %s! Please enter your age: ", user.name);
    scanf("%d", &user.age);

    printf("\nGreat! Now please enter your height (in meters): ");
    scanf("%lf", &user.height);

    printf("\nAnd finally, please enter your weight (in kg): ");
    scanf("%lf", &user.weight);

    // initialize exercises
    strcpy(exercises[0].name, "Running");
    exercises[0].calories_per_min = 8;
    strcpy(exercises[1].name, "Cycling");
    exercises[1].calories_per_min = 5.5;
    strcpy(exercises[2].name, "Swimming");
    exercises[2].calories_per_min = 7.5;
    strcpy(exercises[3].name, "Weightlifting");
    exercises[3].calories_per_min = 4.5;
    strcpy(exercises[4].name, "Yoga");
    exercises[4].calories_per_min = 3;

    printf("\nWhat would you like to do?\n");
    printf("1. Log a workout\n");
    printf("2. View workout history\n");
    printf("3. Exit\n\n");

    do {
        printf("Enter your choice (1-3): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                // log a workout
                if (workouts[6].duration != 0) { // checks if week is full (7 workouts logged)
                    printf("\nYou have already logged 7 workouts this week. Come back next week!\n\n");
                    break;
                }
                else {
                    printf("\nWhat exercise did you do?\n");
                    for (int i = 0; i < 5; i++) {
                        printf("%d. %s\n", i + 1, exercises[i].name);
                    }
                    printf("\nEnter your choice (1-5): ");
                    int exercise_choice;
                    scanf("%d", &exercise_choice);
                    struct Exercise exercise = exercises[exercise_choice - 1];

                    printf("\nHow many minutes did you exercise for?\n");
                    int duration;
                    scanf("%d", &duration);

                    printf("\n");
                    time_t current_time;
                    char timestamp[20];
                    time(&current_time);
                    strftime(timestamp, 20, "%Y-%m-%d", localtime(&current_time)); // gets current date in YYYY-MM-DD format
                    
                    for (int i = 0; i < 7; i++) {
                        if (strcmp(workouts[i].date, timestamp) == 0) { // checks if workout for current date already exists
                            printf("You have already logged a workout for today!\n\n");
                            break;
                        }
                        else if (workouts[i].duration == 0) { // adds workout to first empty slot in array
                            strcpy(workouts[i].date, timestamp);
                            workouts[i].exercise = exercise;
                            workouts[i].duration = duration;
                            printf("Workout logged successfully!\n\n");
                            break;
                        }
                    }
                }
                break;
            case 2:
                // view workout history
                printf("\nWorkout History\n");
                printf("----------------\n");
                for (int i = 0; i < 7; i++) {
                    if (workouts[i].duration != 0) {
                        printf("%s - %s (%d minutes)\n", workouts[i].date, workouts[i].exercise.name, workouts[i].duration);
                    }
                }
                printf("\n");
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please enter again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}