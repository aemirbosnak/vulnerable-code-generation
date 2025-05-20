//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float height; // in meters
    float weight; // in kg
    int steps;
    float calories_burned;
} User;

User users[MAX_USERS];
int user_count = 0;

void addUser() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot add more users!\n");
        return;
    }

    User newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    printf("Enter height (in meters): ");
    scanf("%f", &newUser.height);
    printf("Enter weight (in kg): ");
    scanf("%f", &newUser.weight);
    newUser.steps = 0;
    newUser.calories_burned = 0.0f;

    users[user_count] = newUser;
    user_count++;
    
    printf("User %s added successfully!\n\n", newUser.name);
}

void logSteps(int userIndex) {
    int steps;
    printf("Enter the number of steps achieved today: ");
    scanf("%d", &steps);
    
    users[userIndex].steps += steps;
    users[userIndex].calories_burned += steps * 0.04; // Approx 0.04 calories per step
    
    printf("Steps logged! Total steps: %d, Total calories burned: %.2f\n\n", 
           users[userIndex].steps, users[userIndex].calories_burned);
}

void displayUserStats(int userIndex) {
    User user = users[userIndex];
    printf("User: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2fm\n", user.height);
    printf("Weight: %.2fkg\n", user.weight);
    printf("Total Steps: %d\n", user.steps);
    printf("Calories Burned: %.2f\n\n", user.calories_burned);
}

void viewAllUsers() {
    if (user_count == 0) {
        printf("No users available!\n\n");
        return;
    }

    printf("===== User List =====\n");
    for (int i = 0; i < user_count; i++) {
        printf("%d. %s\n", i + 1, users[i].name);
    }
    printf("======================\n\n");
}

void displayMenu() {
    printf("Welcome to the C Fitness Tracker!\n");
    printf("1. Add User\n");
    printf("2. Log Steps\n");
    printf("3. Display User Stats\n");
    printf("4. View All Users\n");
    printf("5. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice = 0;
    int selected_user = -1;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                viewAllUsers();
                if (user_count > 0) {
                    printf("Choose a user (1 to %d): ", user_count);
                    scanf("%d", &selected_user);
                    if (selected_user > 0 && selected_user <= user_count) {
                        logSteps(selected_user - 1);
                    } else {
                        printf("Invalid selection!\n\n");
                    }
                }
                break;
            case 3:
                viewAllUsers();
                if (user_count > 0) {
                    printf("Choose a user (1 to %d): ", user_count);
                    scanf("%d", &selected_user);
                    if (selected_user > 0 && selected_user <= user_count) {
                        displayUserStats(selected_user - 1);
                    } else {
                        printf("Invalid selection!\n\n");
                    }
                }
                break;
            case 4:
                viewAllUsers();
                break;
            case 5:
                printf("Thank you for using the C Fitness Tracker! Stay fit!\n");
                exit(0);
            default:
                printf("Invalid option, please try again!\n\n");
        }
    }
    
    return 0;
}