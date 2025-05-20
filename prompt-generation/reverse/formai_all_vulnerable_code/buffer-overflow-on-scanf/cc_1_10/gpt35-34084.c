//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the current date
void get_date(char date[])
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    strftime(date, 20, "%Y-%m-%d", tm);
}

// Struct to hold each workout
struct Workout {
    char name[20];
    int calories_burned;
    char date[20];
};

int main() {

    // Menu for user to select options
    int option;
    printf("Welcome to your Fitness Tracker!\n");
    printf("1. Log a workout\n");
    printf("2. View workout history\n");
    printf("3. Exit\n");
    printf("Enter an option number: ");
    scanf("%d", &option);

    // Array to hold all workouts
    struct Workout workouts[100];
    int num_workouts = 0;

    while(option != 3) {
        if(option == 1) {
            // User wants to log a workout
            printf("\nEnter the name of the workout: ");
            char name[20];
            scanf("%s", name);

            printf("Enter the number of calories burned: ");
            int calories;
            scanf("%d", &calories);

            char date[20];
            get_date(date);

            // Create new workout struct and add it to array
            struct Workout workout = {name, calories, date};
            workouts[num_workouts] = workout;
            num_workouts++;

            printf("\nWorkout logged!\n\n");
        } else if(option == 2) {
            // User wants to view workout history
            printf("\nWorkout History:\n");
            printf("| %-20s | %-10s | %-10s |\n", "Name", "Calories", "Date");
            printf("|----------------------|-----------|-----------|\n");
            for(int i = 0; i < num_workouts; i++) {
                struct Workout workout = workouts[i];
                printf("| %-20s | %-10d | %-10s |\n", workout.name, workout.calories_burned, workout.date);
            }
            printf("\n");
        } else {
            printf("\nInvalid option. Please try again.\n\n");
        }

        // Show menu again and get user's next option
        printf("1. Log a workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        printf("Enter an option number: ");
        scanf("%d", &option);
    }

    printf("\nThank you for using the Fitness Tracker!\n");

    return 0;
}