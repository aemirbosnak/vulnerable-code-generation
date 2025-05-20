//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>

// Global Variables
int caloriesBurned = 0;
int totalSteps = 0;
float distanceWalked = 0;
float heartRate = 0;

// Function Declarations
void displayMenu();
void recordSteps(int steps);
void recordHeartRate(float rate);
void calculateCalories();
void displayStats();

// Main Function
int main()
{
    int choice;
    do
    {
        displayMenu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter number of steps: ");
                int steps;
                scanf("%d", &steps);
                recordSteps(steps);
                break;
            case 2:
                printf("Enter heart rate: ");
                float rate;
                scanf("%f", &rate);
                recordHeartRate(rate);
                break;
            case 3:
                calculateCalories();
                break;
            case 4:
                displayStats();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function Definitions
void displayMenu()
{
    printf("-------------------------\n");
    printf("C FITNESS TRACKER PROGRAM\n");
    printf("-------------------------\n");
    printf("1. Record steps taken\n");
    printf("2. Record heart rate\n");
    printf("3. Calculate calories burned\n");
    printf("4. Display statistics\n");
    printf("5. Exit program\n");
    printf("Enter your choice: ");
}

void recordSteps(int steps)
{
    totalSteps += steps;
    distanceWalked = totalSteps * 0.000762;
    printf("Steps recorded. Total steps: %d\n", totalSteps);
}

void recordHeartRate(float rate)
{
    heartRate = rate;
    printf("Heart rate recorded. Rate: %.2f\n", heartRate);
}

void calculateCalories()
{
    caloriesBurned = (int) (0.05 * totalSteps) + (int) (0.1 * heartRate);
    printf("Calories burned: %d\n", caloriesBurned);
}

void displayStats()
{
    printf("STATISTICS:\n");
    printf("Total steps taken: %d\n", totalSteps);
    printf("Distance walked: %.2f km\n", distanceWalked);
    printf("Heart rate: %.2f bpm\n", heartRate);
    printf("Calories burned: %d\n", caloriesBurned);
}