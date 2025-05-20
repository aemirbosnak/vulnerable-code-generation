//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold user data
typedef struct {
    char name[50];
    int age;
    int weight; // in kg
    int height; // in cm
    int steps; // steps taken in a day
    int calories; // calories burned in a day
} User;

// Function prototypes
void displayMenu();
void addUser(User *user);
void logSteps(User *user);
void logCalories(User *user);
void displayUserSummary(User user);
void saveUserData(User user);
void loadUserData(User *user);

// Main Function
int main() {
    User user;
    loadUserData(&user);
    
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addUser(&user);
                break;
            case 2:
                logSteps(&user);
                break;
            case 3:
                logCalories(&user);
                break;
            case 4:
                displayUserSummary(user);
                break;
            case 5:
                saveUserData(user);
                printf("Data saved successfully!\n");
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }
    } while(choice != 6);
    
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add User\n");
    printf("2. Log Steps\n");
    printf("3. Log Calories\n");
    printf("4. Display User Summary\n");
    printf("5. Save User Data\n");
    printf("6. Exit\n");
}

// Function to add user details
void addUser(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (kg): ");
    scanf("%d", &user->weight);
    printf("Enter your height (cm): ");
    scanf("%d", &user->height);
    
    user->steps = 0;
    user->calories = 0;
    
    printf("User added successfully!\n");
}

// Function to log steps taken
void logSteps(User *user) {
    int steps;
    printf("Enter number of steps taken today: ");
    scanf("%d", &steps);
    
    user->steps += steps;
    printf("%d steps logged successfully!\n", steps);
}

// Function to log calories burned
void logCalories(User *user) {
    int calories;
    printf("Enter number of calories burned today: ");
    scanf("%d", &calories);
    
    user->calories += calories;
    printf("%d calories logged successfully!\n", calories);
}

// Function to display user summary
void displayUserSummary(User user) {
    printf("\n--- User Summary ---\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %d kg\n", user.weight);
    printf("Height: %d cm\n", user.height);
    printf("Total Steps Today: %d\n", user.steps);
    printf("Total Calories Burned Today: %d\n", user.calories);
}

// Function to save user data to a file
void saveUserData(User user) {
    FILE *file = fopen("user_data.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }
    fwrite(&user, sizeof(User), 1, file);
    fclose(file);
}

// Function to load user data from a file
void loadUserData(User *user) {
    FILE *file = fopen("user_data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "No previous user data found. Starting fresh!\n");
        return;
    }
    fread(user, sizeof(User), 1, file);
    fclose(file);
}