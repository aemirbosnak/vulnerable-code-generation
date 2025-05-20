//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store user data
typedef struct User {
    char name[50];
    int age;
    float height;
    float weight;
    int steps;
    int calories;
} User;

// Function to create a new user
User *create_user() {
    User *user = (User *)malloc(sizeof(User));
    printf("\nLet's get you started!\n");
    printf("What's your name? ");
    scanf("%s", user->name);
    printf("How old are you? ");
    scanf("%d", &user->age);
    printf("How tall are you in meters? ");
    scanf("%f", &user->height);
    printf("How much do you weigh in kilograms? ");
    scanf("%f", &user->weight);
    user->steps = 0;
    user->calories = 0;
    return user;
}

// Function to track steps
void track_steps(User *user) {
    int steps;
    printf("\nHow many steps did you take today? ");
    scanf("%d", &steps);
    user->steps += steps;
    printf("Great job! You've taken %d steps so far.\n", user->steps);
}

// Function to track calories
void track_calories(User *user) {
    int calories;
    printf("\nHow many calories did you burn today? ");
    scanf("%d", &calories);
    user->calories += calories;
    printf("Keep it up! You've burned %d calories so far.\n", user->calories);
}

// Function to display user data
void display_user_data(User *user) {
    printf("\n\nHere's your fitness tracker data:\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %.2fm\n", user->height);
    printf("Weight: %.2fkg\n", user->weight);
    printf("Steps: %d\n", user->steps);
    printf("Calories: %d\n", user->calories);
}

// Function to save user data to a file
void save_user_data(User *user) {
    FILE *file = fopen("user_data.txt", "w");
    fprintf(file, "%s\n", user->name);
    fprintf(file, "%d\n", user->age);
    fprintf(file, "%.2f\n", user->height);
    fprintf(file, "%.2f\n", user->weight);
    fprintf(file, "%d\n", user->steps);
    fprintf(file, "%d\n", user->calories);
    fclose(file);
    printf("\nYour data has been saved to user_data.txt.\n");
}

// Function to load user data from a file
User *load_user_data() {
    FILE *file = fopen("user_data.txt", "r");
    if (file == NULL) {
        printf("\nNo user data found. Please create a new user.\n");
        return NULL;
    }
    User *user = (User *)malloc(sizeof(User));
    fscanf(file, "%s", user->name);
    fscanf(file, "%d", &user->age);
    fscanf(file, "%f", &user->height);
    fscanf(file, "%f", &user->weight);
    fscanf(file, "%d", &user->steps);
    fscanf(file, "%d", &user->calories);
    fclose(file);
    printf("\nYour data has been loaded.\n");
    return user;
}

// Main function
int main() {
    int choice;
    User *user = NULL;

    // Welcome message
    printf("\n\t\t\tWelcome to the Fitness Tracker!\n\n");

    while (1) {
        // Display menu
        printf("\nWhat would you like to do?\n");
        printf("1. Create a new user\n");
        printf("2. Load existing user data\n");
        printf("3. Track steps\n");
        printf("4. Track calories\n");
        printf("5. Display user data\n");
        printf("6. Save user data\n");
        printf("7. Exit\n");

        // Get user choice
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                user = create_user();
                break;
            case 2:
                user = load_user_data();
                break;
            case 3:
                if (user == NULL) {
                    printf("\nPlease create a new user or load existing user data first.\n");
                } else {
                    track_steps(user);
                }
                break;
            case 4:
                if (user == NULL) {
                    printf("\nPlease create a new user or load existing user data first.\n");
                } else {
                    track_calories(user);
                }
                break;
            case 5:
                if (user == NULL) {
                    printf("\nPlease create a new user or load existing user data first.\n");
                } else {
                    display_user_data(user);
                }
                break;
            case 6:
                if (user == NULL) {
                    printf("\nPlease create a new user or load existing user data first.\n");
                } else {
                    save_user_data(user);
                }
                break;
            case 7:
                printf("\nThank you for using the Fitness Tracker! Have a great day!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}