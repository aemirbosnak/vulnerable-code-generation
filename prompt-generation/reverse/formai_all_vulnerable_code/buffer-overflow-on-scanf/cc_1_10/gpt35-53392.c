//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FitnessTracker {
    int steps;
    int calories;
    float distance;
    int heart_rate;
};

int main(void) {
    struct FitnessTracker my_tracker;
    my_tracker.steps = 0;
    my_tracker.calories = 0;
    my_tracker.distance = 0;
    my_tracker.heart_rate = 0;
    
    printf("Initializing Fitness Tracker...\n");
    printf("Welcome, Cyberpunk!\n");
    printf("Your Fitness Tracker is now ready for use.\n");
    printf("Press enter to continue.\n");
    getchar();
    
    while (1) {
        printf("What would you like to do? (Enter a number)\n");
        printf("1. Record steps\n");
        printf("2. Record calories burned\n");
        printf("3. Record distance traveled\n");
        printf("4. Record heart rate\n");
        printf("5. Display statistics\n");
        printf("6. Quit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("How many steps did you take?\n");
                int steps_taken;
                scanf("%d", &steps_taken);
                my_tracker.steps += steps_taken;
                break;
            
            case 2:
                printf("How many calories did you burn?\n");
                int calories_burned;
                scanf("%d", &calories_burned);
                my_tracker.calories += calories_burned;
                break;
            
            case 3:
                printf("How far did you travel (in miles)?\n");
                float distance_traveled;
                scanf("%f", &distance_traveled);
                my_tracker.distance += distance_traveled;
                break;
            
            case 4:
                printf("What was your heart rate?\n");
                int heart_rate_recorded;
                scanf("%d", &heart_rate_recorded);
                my_tracker.heart_rate = heart_rate_recorded;
                break;
            
            case 5:
                printf("Statistics:\n");
                printf("Steps taken: %d\n", my_tracker.steps);
                printf("Calories burned: %d\n", my_tracker.calories);
                printf("Distance traveled: %.2f miles\n", my_tracker.distance);
                printf("Heart rate: %d bpm\n", my_tracker.heart_rate);
                break;
            
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}