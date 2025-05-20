//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define futuristic UI elements
#define UI_SEPARATOR "----------------------------------------"
#define UI_TITLE "%s"
#define UI_MENU_ITEM "%-2d. %s"
#define UI_PROMPT "Please enter your selection (1-%d): "
#define UI_ERROR "Invalid selection. Please try again."

// Define fitness tracker data structures
typedef struct {
    int steps;
    int distance;
    int calories;
    int heart_rate;
} FitnessData;

typedef struct {
    char name[20];
    int age;
    int height;
    int weight;
    FitnessData data;
} UserProfile;

// Define function prototypes
void display_ui_title(char *title);
void display_ui_menu();
UserProfile *create_user_profile();
void update_fitness_data(UserProfile *profile);
void display_fitness_data(UserProfile *profile);
void delete_user_profile(UserProfile *profile);

// Main program
int main() {
    // Initialize user profiles
    UserProfile *profiles[5] = {NULL};

    // Main UI loop
    while (1) {
        // Display UI title
        display_ui_title("Quantum Fitness Tracker");

        // Display UI menu
        display_ui_menu();

        // Get user selection
        int selection;
        printf(UI_PROMPT, 5);
        scanf("%d", &selection);

        // Handle user selection
        switch (selection) {
            case 1:
                profiles[0] = create_user_profile();
                break;
            case 2:
                update_fitness_data(profiles[0]);
                break;
            case 3:
                display_fitness_data(profiles[0]);
                break;
            case 4:
                delete_user_profile(profiles[0]);
                break;
            case 5:
                exit(0);
            default:
                printf(UI_ERROR);
                break;
        }

        // Display UI separator
        printf("%s\n", UI_SEPARATOR);
    }

    return 0;
}

// Function definitions

// Display UI title
void display_ui_title(char *title) {
    printf("\n%s\n", title);
}

// Display UI menu
void display_ui_menu() {
    printf(UI_MENU_ITEM, 1, "Create User Profile");
    printf(UI_MENU_ITEM, 2, "Update Fitness Data");
    printf(UI_MENU_ITEM, 3, "Display Fitness Data");
    printf(UI_MENU_ITEM, 4, "Delete User Profile");
    printf(UI_MENU_ITEM, 5, "Exit");
}

// Create user profile
UserProfile *create_user_profile() {
    // Allocate memory for user profile
    UserProfile *profile = malloc(sizeof(UserProfile));

    // Get user input
    printf("Enter your name: ");
    scanf("%s", profile->name);
    printf("Enter your age: ");
    scanf("%d", &profile->age);
    printf("Enter your height (in inches): ");
    scanf("%d", &profile->height);
    printf("Enter your weight (in pounds): ");
    scanf("%d", &profile->weight);

    // Return user profile
    return profile;
}

// Update fitness data
void update_fitness_data(UserProfile *profile) {
    // Get user input
    printf("Enter your steps: ");
    scanf("%d", &profile->data.steps);
    printf("Enter your distance (in miles): ");
    scanf("%d", &profile->data.distance);
    printf("Enter your calories burned: ");
    scanf("%d", &profile->data.calories);
    printf("Enter your heart rate (in bpm): ");
    scanf("%d", &profile->data.heart_rate);
}

// Display fitness data
void display_fitness_data(UserProfile *profile) {
    // Display fitness data
    printf("Name: %s\n", profile->name);
    printf("Age: %d years\n", profile->age);
    printf("Height: %d inches\n", profile->height);
    printf("Weight: %d pounds\n", profile->weight);
    printf("Steps: %d\n", profile->data.steps);
    printf("Distance: %d miles\n", profile->data.distance);
    printf("Calories: %d\n", profile->data.calories);
    printf("Heart rate: %d bpm\n", profile->data.heart_rate);
}

// Delete user profile
void delete_user_profile(UserProfile *profile) {
    // Free memory allocated for user profile
    free(profile);
}