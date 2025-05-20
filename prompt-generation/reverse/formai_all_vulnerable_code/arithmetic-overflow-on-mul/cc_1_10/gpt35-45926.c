//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>

typedef struct fitnessTracker{
    char name[50];
    int age;
    float height;
    float weight;
    int caloriesBurned;
    int stepsCount;
} FitnessTracker;

int main(){
    FitnessTracker user;

    // Getting User Details
    printf("Enter your Name: ");
    scanf("%[^\n]s", &user.name);

    printf("Enter your Age: ");
    scanf("%d", &user.age);

    printf("Enter your Height (in m): ");
    scanf("%f", &user.height);

    printf("Enter your Weight (in kg): ");
    scanf("%f", &user.weight);

    // Assumption: The average calories burned per step is 0.05 for an individual of the user's weight.
    float caloriesPerStep = 0.05 * user.weight;
    printf("Calories Burned per Step: %.2f\n", caloriesPerStep);

    // Begin Tracking
    int choice;
    do{
        printf("\n***** FITNESS TRACKER MENU *****");
        printf("\n1. Track Steps");
        printf("\n2. Track Calories Burned");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of steps you took: ");
                int steps;
                scanf("%d", &steps);
                user.stepsCount += steps;
                printf("Total Steps Tracked: %d\n", user.stepsCount);
                break;
            case 2:
                printf("Enter the duration of your workout (in minutes): ");
                int duration;
                scanf("%d", &duration);
                user.caloriesBurned += (duration * 10 * caloriesPerStep); // Assumption: An individual of average weight burns approximately 10 calories per minute of exercise.
                printf("Total Calories Burned: %d\n", user.caloriesBurned);
                break;
            case 3:
                printf("Thank you for using the fitness tracker.");
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}