//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float weight;  // in kg
    float height;  // in m
    int steps_today;
    float calories_burned;
    float distance_walked; // in km
} User;

void displayWelcomeMessage() {
    printf("=====================================\n");
    printf("       Welcome to FitTrack 1.0      \n");
    printf("=====================================\n");
}

void inputUserDetails(User* user) {
    printf("Enter your name: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Remove newline character

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &user->weight);

    printf("Enter your height (in meters): ");
    scanf("%f", &user->height);
    
    // Initialize other tracking fields
    user->steps_today = 0;
    user->calories_burned = 0.0;
    user->distance_walked = 0.0;
}

float calculateBMI(User user) {
    return user.weight / (user.height * user.height);
}

void displayUserStats(User user) {
    printf("\nHealth Stats for %s:\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Height: %.2f m\n", user.height);
    printf("BMI: %.2f\n", calculateBMI(user));
    printf("Steps Today: %d\n", user.steps_today);
    printf("Calories Burned: %.2f kcal\n", user.calories_burned);
    printf("Distance Walked Today: %.2f km\n\n", user.distance_walked);
}

void updateDailyStats(User *user) {
    int steps;
    printf("Enter the number of steps taken today: ");
    scanf("%d", &steps);
    user->steps_today += steps;
    
    // Assuming average of 0.05 kcal burned per step
    user->calories_burned += steps * 0.05;
    // Assuming average stride length of 0.78 m (0.00078 km)
    user->distance_walked += steps * 0.00078;
}

void displayUsageGuide() {
    printf("\nUsage Guide:\n");
    printf("1. Input your details to get started.\n");
    printf("2. Update your daily stats at the end of each day.\n");
    printf("3. View your health statistics and track your progress.\n");
    printf("4. Use the program to motivate your fitness goals.\n");
}

int main() {
    User user;

    displayWelcomeMessage();
    inputUserDetails(&user);
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Update daily stats\n");
        printf("2. Display user statistics\n");
        printf("3. Display usage guide\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateDailyStats(&user);
                printf("Daily stats updated successfully!\n");
                break;
            case 2:
                displayUserStats(user);
                break;
            case 3:
                displayUsageGuide();
                break;
            case 4:
                printf("Exiting the program. Stay healthy!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}