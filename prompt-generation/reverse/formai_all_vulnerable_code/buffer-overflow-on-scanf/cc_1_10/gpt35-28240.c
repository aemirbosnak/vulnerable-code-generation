//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int age;
    float weight;
} User;

int main() {

    srand(time(NULL));          // Seed for random number generator

    User user1;                 // Declare a User struct for user1
    printf("Enter name: ");
    scanf("%s", user1.name);
    printf("Enter age: ");
    scanf("%d", &user1.age);
    printf("Enter weight: ");
    scanf("%f", &user1.weight);

    float workout_time = 30.0;  // Initial workout time is 30 minutes
    float calories = 0.0;       // Initialize calorie counter
    float max_calories = 0.0;   // Initialize max calories burned
    int days = 1;               // Initialize the number of workout days to 1

    while (1) {
        printf("\nDay %d - Workout time: %.2f minutes\n", days, workout_time);
        printf("Enter 'c' to complete workout, 'q' to quit: ");

        char input;
        scanf(" %c", &input);   // Add space before %c to consume newline character

        if (input == 'c') {
            calories = ((rand() % 200) + 300) * (workout_time / 60.0); // Calculate calories burned
            printf("\nCalories burned: %.2f\n", calories);

            if (calories > max_calories) {
                max_calories = calories;    // Update max calories if necessary
            }

            printf("Max calories burned: %.2f\n", max_calories);

            days++;                 // Increment number of workout days

            if (days % 7 == 0) {    // Adjust workout time every 7 days
                workout_time += 5.0;
                printf("\nCongrats! Workout time increased to %.2f minutes.\n", workout_time);
            }

        } else if (input == 'q') {
            break;                  // Exit while loop
        } else {
            printf("\nInvalid input. Try again.\n");
        }
    }

    float avg_calories = (calories * 1.0) / days; // Calculate average calories burned per day

    printf("\n\n===== FITNESS SUMMARY =====\n");
    printf("User: %s, Age: %d, Weight: %.2f\n", user1.name, user1.age, user1.weight);
    printf("Total workout days: %d\n", days);
    printf("Average calories burned per day: %.2f\n", avg_calories);

    return 0;
}