//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

// The fitness goals
#define CALORIE_GOAL 2000
#define STEP_GOAL 10000

// The user's current fitness stats
int calories_consumed = 0;
int steps_taken = 0;

// The time of day (in seconds) that the user last checked in
unsigned int last_checkin_time = 0;

// The device's battery life percentage
float battery_life = 100.0;

// The device's current charging status
bool is_charging = false;

// The user's username for the app
char * username = "example_user123";

// The device's unique ID number
int device_id = 12345;

// The function that will run when the user checks in
void check_in() {
    printf("Checking in...\n");
    
    // Update the check-in time
    last_checkin_time = (unsigned)time(NULL);
    
    // Update calories consumed and steps taken
    printf("Enter number of calories consumed today: ");
    scanf("%d", &calories_consumed);
    printf("Enter number of steps taken today: ");
    scanf("%d", &steps_taken);
    
    // Display a motivational message to the user
    printf("Awesome job, %s! Keep up the great work!\n", username);
}

// The function that will run when the user wants to see their progress
void view_progress() {
    // Calculate the percentage of calories burned towards the goal
    float calorie_progress = 100 * ((float)calories_consumed / (float)CALORIE_GOAL);
    
    // Calculate the percentage of steps taken towards the goal
    float step_progress = 100 * ((float)steps_taken / (float)STEP_GOAL);
    
    printf("Calories consumed: %d/%d (%.2f%%)\n", calories_consumed, CALORIE_GOAL, calorie_progress);
    printf("Steps taken: %d/%d (%.2f%%)\n", steps_taken, STEP_GOAL, step_progress);
}

// The function that will run when the user checks the device's battery status
void check_battery() {
    printf("Battery life: %.2f%%\n", battery_life);
    
    if (is_charging) {
        printf("Device is currently charging.\n");
    } else {
        printf("Device is not currently charging.\n");
    }
}

int main() {
    printf("***Welcome to the C Fitness Tracker!***\n\n");
    
    printf("Username: %s\n", username);
    printf("Device ID: %d\n\n", device_id);
    
    bool is_running = true;
    
    while (is_running) {
        printf("What would you like to do?\n");
        printf("1. Check in\n");
        printf("2. View progress\n");
        printf("3. Check battery\n");
        printf("4. Quit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                check_in();
                break;
            case 2:
                view_progress();
                break;
            case 3:
                check_battery();
                break;
            case 4:
                printf("Thank you for using the C Fitness Tracker!\n");
                is_running = false;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}