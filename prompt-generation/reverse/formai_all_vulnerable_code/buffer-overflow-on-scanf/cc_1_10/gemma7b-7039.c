//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the functions to track fitness data
void track_heart_rate(int heart_rate);
void track_steps_taken(int steps_taken);
void track_calories_burned(int calories_burned);

// Main function
int main()
{
    // Initialize the fitness data
    int heart_rate = 0;
    int steps_taken = 0;
    int calories_burned = 0;

    // Start the fitness tracking loop
    while (1)
    {
        // Get the user's heart rate, steps taken, and calories burned
        printf("Enter your heart rate: ");
        scanf("%d", &heart_rate);

        printf("Enter the number of steps you took: ");
        scanf("%d", &steps_taken);

        printf("Enter the number of calories you burned: ");
        scanf("%d", &calories_burned);

        // Track the fitness data
        track_heart_rate(heart_rate);
        track_steps_taken(steps_taken);
        track_calories_burned(calories_burned);

        // Display the fitness data
        printf("Your heart rate is: %d\n", heart_rate);
        printf("You took %d steps.\n", steps_taken);
        printf("You burned %d calories.\n", calories_burned);

        // Ask the user if they want to continue tracking
        printf("Do you want to continue tracking? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        // If the user does not want to continue tracking, break out of the loop
        if (answer == 'N')
        {
            break;
        }
    }

    // Print a goodbye message
    printf("Thank you for using the fitness tracker!\n");

    return 0;
}

// Function to track heart rate
void track_heart_rate(int heart_rate)
{
    // Store the heart rate in a file
    FILE *file = fopen("heart_rate.txt", "a");
    fprintf(file, "%d\n", heart_rate);
    fclose(file);
}

// Function to track steps taken
void track_steps_taken(int steps_taken)
{
    // Store the number of steps taken in a file
    FILE *file = fopen("steps_taken.txt", "a");
    fprintf(file, "%d\n", steps_taken);
    fclose(file);
}

// Function to track calories burned
void track_calories_burned(int calories_burned)
{
    // Store the number of calories burned in a file
    FILE *file = fopen("calories_burned.txt", "a");
    fprintf(file, "%d\n", calories_burned);
    fclose(file);
}