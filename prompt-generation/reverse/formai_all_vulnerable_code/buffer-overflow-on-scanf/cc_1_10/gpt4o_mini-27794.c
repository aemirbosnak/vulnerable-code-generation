//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    float weight;  // in kilograms
    float height;  // in meters
    int steps;
    float caloriesBurned;
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot add more users.\n");
        return;
    }
    
    User newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    printf("Enter gender (M/F): ");
    scanf(" %c", &newUser.gender);
    printf("Enter weight (kg): ");
    scanf("%f", &newUser.weight);
    printf("Enter height (m): ");
    scanf("%f", &newUser.height);
    
    newUser.steps = 0;
    newUser.caloriesBurned = 0.0;
    
    users[userCount++] = newUser;
    printf("User %s added successfully!\n", newUser.name);
}

void logActivity() {
    char name[MAX_NAME_LENGTH];
    int steps;
    
    printf("Enter the user name: ");
    scanf("%s", name);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Enter steps taken: ");
            scanf("%d", &steps);
            users[i].steps += steps;
            users[i].caloriesBurned += steps * 0.04; // Assuming 0.04 calories per step
            printf("Logged %d steps for %s. Total Steps: %d, Total Calories Burned: %.2f\n", 
                   steps, users[i].name, users[i].steps, users[i].caloriesBurned);
            return;
        }
    }
    
    printf("User with name %s not found.\n", name);
}

void displayStats() {
    char name[MAX_NAME_LENGTH];
    
    printf("Enter the user name to display stats: ");
    scanf("%s", name);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("\nUser Statistics for %s:\n", users[i].name);
            printf("Age: %d\n", users[i].age);
            printf("Gender: %c\n", users[i].gender);
            printf("Weight: %.2f kg\n", users[i].weight);
            printf("Height: %.2f m\n", users[i].height);
            printf("Total Steps: %d\n", users[i].steps);
            printf("Total Calories Burned: %.2f\n", users[i].caloriesBurned);
            return;
        }
    }
    
    printf("User with name %s not found.\n", name);
}

void inputMissingData() {
    // Placeholder function for additional functionality
    printf("Missing data handling will be implemented in a later version!\n");
}

void displayMenu() {
    printf("\n====== Fitness Tracker Menu ======\n");
    printf("1. Add User\n");
    printf("2. Log Activity\n");
    printf("3. Display Statistics\n");
    printf("4. Input Missing Data\n");
    printf("5. Exit\n");
    printf("==================================\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                logActivity();
                break;
            case 3:
                displayStats();
                break;
            case 4:
                inputMissingData();
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    
    return 0;
}