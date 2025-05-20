//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LEN 50
#define MAX_ENTRY_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float weight; // in kg
    float height; // in meters
    int steps_today;
    int steps_goal;
    float calories_burned;
} User;

User users[MAX_USERS];
int user_count = 0;

void addUser() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", users[user_count].name);
    printf("Enter age: ");
    scanf("%d", &users[user_count].age);
    printf("Enter weight (kg): ");
    scanf("%f", &users[user_count].weight);
    printf("Enter height (m): ");
    scanf("%f", &users[user_count].height);
    users[user_count].steps_today = 0;
    users[user_count].steps_goal = 10000; // default goal
    users[user_count].calories_burned = 0.0;
    user_count++;
    printf("User %s added successfully!\n", users[user_count - 1].name);
}

void viewUsers() {
    if (user_count == 0) {
        printf("No users to display.\n");
        return;
    }
    printf("List of Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("User %d: %s, Age: %d, Weight: %.2f kg, Height: %.2f m, Steps Today: %d, Goal: %d, Calories Burned: %.2f\n",
               i + 1, users[i].name, users[i].age, users[i].weight,
               users[i].height, users[i].steps_today, 
               users[i].steps_goal, users[i].calories_burned);
    }
}

void recordSteps() {
    if (user_count == 0) {
        printf("No users available. Please add a user first.\n");
        return;
    }

    int userIndex;
    printf("Select user index (1-%d): ", user_count);
    scanf("%d", &userIndex);
    userIndex--; // adjust for zero-index

    if (userIndex < 0 || userIndex >= user_count) {
        printf("Invalid user index.\n");
        return;
    }

    int steps;
    printf("Enter number of steps: ");
    scanf("%d", &steps);
    
    users[userIndex].steps_today += steps;
    users[userIndex].calories_burned += steps * 0.04; // assume 0.04 calories/step
    printf("Recorded %d steps for %s. Total Steps Today: %d\n", 
           steps, users[userIndex].name, users[userIndex].steps_today);
}

void checkGoal() {
    if (user_count == 0) {
        printf("No users available. Please add a user first.\n");
        return;
    }

    int userIndex;
    printf("Select user index (1-%d): ", user_count);
    scanf("%d", &userIndex);
    userIndex--; // adjust for zero-index

    if (userIndex < 0 || userIndex >= user_count) {
        printf("Invalid user index.\n");
        return;
    }

    if (users[userIndex].steps_today >= users[userIndex].steps_goal) {
        printf("Congratulations %s! You've reached your daily goal of %d steps!\n", 
               users[userIndex].name, users[userIndex].steps_goal);
    } else {
        printf("Keep going %s! You have %d steps to reach your goal of %d steps.\n", 
               users[userIndex].name, 
               users[userIndex].steps_goal - users[userIndex].steps_today,
               users[userIndex].steps_goal);
    }
}

void displayMenu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add User\n");
    printf("2. View Users\n");
    printf("3. Record Steps\n");
    printf("4. Check Step Goal\n");
    printf("5. Exit\n");
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
                viewUsers();
                break;
            case 3:
                recordSteps();
                break;
            case 4:
                checkGoal();
                break;
            case 5:
                printf("Exiting program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}