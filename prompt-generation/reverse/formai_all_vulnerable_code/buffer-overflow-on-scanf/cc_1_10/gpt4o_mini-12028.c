//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>

// Structure to hold user fitness data
typedef struct {
    char name[100];
    int age;
    float height; // in cm
    float weight; // in kg
    int steps;
    float caloriesBurned;
} FitnessTracker;

// Function to initialize user's fitness data
void initializeTracker(FitnessTracker *tracker) {
    printf("Enter your name: ");
    fgets(tracker->name, sizeof(tracker->name), stdin);
    
    printf("Enter your age: ");
    scanf("%d", &tracker->age);
    
    printf("Enter your height (in cm): ");
    scanf("%f", &tracker->height);
    
    printf("Enter your weight (in kg): ");
    scanf("%f", &tracker->weight);

    // Initialize other data
    tracker->steps = 0;
    tracker->caloriesBurned = 0.0;
}

// Function to log steps and calculate calories burned
void logSteps(FitnessTracker *tracker, int steps) {
    tracker->steps += steps;
    tracker->caloriesBurned += steps * 0.04; // Assume 0.04 calories burned per step
    printf("%d steps logged!\n", steps);
}

// Function to display summary of the fitness tracking
void displaySummary(FitnessTracker *tracker) {
    printf("\n--- Fitness Summary ---\n");
    printf("Name: %s", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Height: %.2f cm\n", tracker->height);
    printf("Weight: %.2f kg\n", tracker->weight);
    printf("Steps taken today: %d\n", tracker->steps);
    printf("Calories burned: %.2f\n", tracker->caloriesBurned);
    printf("-----------------------\n");
}

int main() {
    FitnessTracker user;
    int steps;

    // Initialize the fitness tracker
    initializeTracker(&user);

    while (1) {
        printf("Enter the number of steps taken (or -1 to exit): ");
        scanf("%d", &steps);

        if (steps == -1) {
            break;
        } else if (steps < 0) {
            printf("Please enter a valid number of steps.\n");
        } else {
            logSteps(&user, steps);
        }
    }

    // Display the final summary
    displaySummary(&user);
    return 0;
}