//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store fitness data
struct fitness_tracker {
    char name[20];
    int age;
    float height;
    float weight;
    int steps_taken;
    float distance_traveled;
    int calories_burned;
};

int main() {
    // Declare and initialize a fitness tracker object
    struct fitness_tracker user = {"John", 25, 1.75, 70.0, 0, 0.0, 0};
    int choice;
    
    // Display menu options
    while (1) {
        printf("Fitness Tracker Menu\n\n");
        printf("1. Log Steps\n");
        printf("2. Log Distance\n");
        printf("3. Log Calories\n");
        printf("4. Display Current Stats\n");
        printf("0. Quit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform selected action based on user choice
        switch (choice) {
            case 1:
                printf("Enter number of steps taken: ");
                scanf("%d", &(user.steps_taken));
                printf("Steps logged successfully!\n\n");
                break;
            
            case 2:
                printf("Enter distance traveled (in km): ");
                scanf("%f", &(user.distance_traveled));
                printf("Distance logged successfully!\n\n");
                break;
            
            case 3:
                printf("Enter number of calories burned: ");
                scanf("%d", &(user.calories_burned));
                printf("Calories logged successfully!\n\n");
                break;
            
            case 4:
                printf("\nCurrent stats for %s:\n", user.name);
                printf("Age: %d\n", user.age);
                printf("Height: %.2f m\n", user.height);
                printf("Weight: %.2f kg\n", user.weight);
                printf("Steps Taken: %d\n", user.steps_taken);
                printf("Distance Traveled: %.2f km\n", user.distance_traveled);
                printf("Calories Burned: %d\n\n", user.calories_burned);
                break;
            
            case 0:
                printf("Exiting program...");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    
    return 0;
}