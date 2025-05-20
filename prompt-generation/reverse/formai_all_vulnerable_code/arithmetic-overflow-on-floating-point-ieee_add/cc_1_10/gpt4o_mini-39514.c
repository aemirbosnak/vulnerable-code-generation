//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold user's fitness data
typedef struct {
    char name[50];
    int age;
    float weight; // in kg
    float height; // in meters
    int workouts; // Number of workouts logged
    float total_calories; // Total calories burned
} User;

// Function Prototypes
void displayWelcome();
void addUser(User *user);
void logWorkout(User *user);
void displaySummary(User *user);
void calculateCalories(User *user, float calories_burned);
void displayNutritionTips();

int main() {
    User user = {"", 0, 0.0, 0.0, 0, 0.0};
    int choice;
    
    displayWelcome();
    addUser(&user);

    while (1) {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Log Workout\n");
        printf("2. Display Summary\n");
        printf("3. Nutrition Tips\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                logWorkout(&user);
                break;
            case 2:
                displaySummary(&user);
                break;
            case 3:
                displayNutritionTips();
                break;
            case 4:
                printf("Thank you for using the Fitness Tracker! Keep fit!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}

void displayWelcome() {
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Tracking your fitness journey starts here!\n");
}

void addUser(User *user) {
    printf("Please enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (kg): ");
    scanf("%f", &user->weight);
    printf("Enter your height (m): ");
    scanf("%f", &user->height);
    printf("User %s added successfully!\n", user->name);
}

void logWorkout(User *user) {
    float calories_burned;
    printf("Enter calories burned in this workout: ");
    scanf("%f", &calories_burned);
    
    calculateCalories(user, calories_burned);
    printf("Workout logged successfully!\n");
}

void calculateCalories(User *user, float calories_burned) {
    user->total_calories += calories_burned;
    user->workouts++;
}

void displaySummary(User *user) {
    printf("\n--- Fitness Summary for %s ---\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Height: %.2f m\n", user->height);
    printf("Total Workouts Logged: %d\n", user->workouts);
    printf("Total Calories Burned: %.2f kcal\n", user->total_calories);
    printf("----------------------------\n");
}

void displayNutritionTips() {
    printf("\n--- Nutrition Tips ---\n");
    printf("1. Stay Hydrated: Drink plenty of water throughout the day.\n");
    printf("2. Balanced Diet: Include protein, healthy fats, and carbs.\n");
    printf("3. Eat Fruits and Vegetables: Aim for a variety of colors!\n");
    printf("4. Watch Portion Sizes: Be mindful of your plate.\n");
    printf("5. Avoid Sugary Drinks: Opt for water or herbal teas.\n");
    printf("----------------------------\n");
}