//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int choice, num_calories = 0, num_steps = 0, num_workouts = 0;
    float distance = 0, time = 0;
    
    printf("Welcome to your Fitness Tracker!\n");
    
    while (1) {
        
        printf("\nWhat would you like to do?\n");
        printf("1. Track calories consumed\n");
        printf("2. Track steps taken\n");
        printf("3. Track distance traveled\n");
        printf("4. Track workout duration\n");
        printf("5. View stats\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            
            case 1:
                printf("Enter the number of calories consumed: ");
                scanf("%d", &num_calories);
                break;
                
            case 2:
                printf("Enter the number of steps taken: ");
                scanf("%d", &num_steps);
                break;
                
            case 3:
                printf("Enter the distance traveled (in km): ");
                scanf("%f", &distance);
                break;
                
            case 4:
                printf("Enter the workout duration (in minutes): ");
                scanf("%f", &time);
                num_workouts++;
                break;
                
            case 5:
                printf("\nStats:\n");
                printf("Calories consumed: %d\n", num_calories);
                printf("Steps taken: %d\n", num_steps);
                printf("Distance traveled: %.2f km\n", distance);
                printf("Number of workouts: %d\n", num_workouts);
                break;
                
            case 6:
                printf("Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
                
        }
        
    }
    
    return 0;
}