//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    float weight;           // Weight of user in kg
    int steps;             // Number of steps taken
    float distance;        // Distance covered in km
    float caloriesBurned;  // Calories burned
} FitnessData;

typedef struct {
    char name[MAX_NAME_LENGTH];  // Name of user
    int age;                     // Age of user
    FitnessData data;           // User's fitness data
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached! Cannot add more.\n");
        return;
    }
    
    User newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    newUser.data.steps = 0;
    newUser.data.distance = 0.0;
    newUser.data.caloriesBurned = 0.0;
    
    printf("Enter weight (in kg): ");
    scanf("%f", &newUser.data.weight);
    
    users[userCount++] = newUser;
    printf("User %s added successfully!\n", newUser.name);
}

void inputData() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the user's name to log data: ");
    scanf("%s", name);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Enter steps taken: ");
            scanf("%d", &users[i].data.steps);
            printf("Enter distance covered (in km): ");
            scanf("%f", &users[i].data.distance);
            printf("Enter calories burned: ");
            scanf("%f", &users[i].data.caloriesBurned);
            printf("Data logged successfully for %s!\n", users[i].name);
            return;
        }
    }
    
    printf("User %s not found!\n", name);
}

void displayData() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the user's name to display data: ");
    scanf("%s", name);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("------ Fitness Data for %s ------\n", users[i].name);
            printf("Age: %d\n", users[i].age);
            printf("Weight: %.2f kg\n", users[i].data.weight);
            printf("Steps: %d\n", users[i].data.steps);
            printf("Distance: %.2f km\n", users[i].data.distance);
            printf("Calories Burned: %.2f\n", users[i].data.caloriesBurned);
            printf("-----------------------------------\n");
            return;
        }
    }
    
    printf("User %s not found!\n", name);
}

void viewAllUsers() {
    if (userCount == 0) {
        printf("No users found.\n");
        return;
    }
    
    printf("------ List of Users ------\n");
    for (int i = 0; i < userCount; i++) {
        printf("User %d: %s, Age: %d\n", i + 1, users[i].name, users[i].age);
    }
    printf("---------------------------\n");
}

void menu() {
    int choice;
    while (1) {
        printf("----- Fitness Tracker Menu -----\n");
        printf("1. Add User\n");
        printf("2. Log User Fitness Data\n");
        printf("3. Display User Fitness Data\n");
        printf("4. View All Users\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                inputData();
                break;
            case 3:
                displayData();
                break;
            case 4:
                viewAllUsers();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}