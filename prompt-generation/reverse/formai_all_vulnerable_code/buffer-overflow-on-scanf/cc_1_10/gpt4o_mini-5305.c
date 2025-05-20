//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATA_POINTS 100

typedef struct {
    int steps;
    float distance; // in kilometers
    float calories; // calories burned
} FitnessData;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float height; // in centimeters
    float weight; // in kilograms
    FitnessData data[MAX_DATA_POINTS];
    int dataCount;
} User;

User users[MAX_USERS];
int totalUsers = 0;

void addUser();
void recordFitnessData(int userIndex);
void displayUserInfo(int userIndex);
void displayAllUsers();
int findUser(char* name);

int main() {
    int choice;

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Record Fitness Data\n");
        printf("3. Display User Info\n");
        printf("4. Display All Users\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                {
                    char name[MAX_NAME_LENGTH];
                    printf("Enter user name: ");
                    scanf("%s", name);
                    int index = findUser(name);
                    if (index != -1) {
                        recordFitnessData(index);
                    } else {
                        printf("User not found!\n");
                    }
                }
                break;
            case 3:
                {
                    char name[MAX_NAME_LENGTH];
                    printf("Enter user name: ");
                    scanf("%s", name);
                    int index = findUser(name);
                    if (index != -1) {
                        displayUserInfo(index);
                    } else {
                        printf("User not found!\n");
                    }
                }
                break;
            case 4:
                displayAllUsers();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addUser() {
    if (totalUsers >= MAX_USERS) {
        printf("Maximum user limit reached!\n");
        return;
    }

    User newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    printf("Enter height (cm): ");
    scanf("%f", &newUser.height);
    printf("Enter weight (kg): ");
    scanf("%f", &newUser.weight);
    
    newUser.dataCount = 0; // Initialize data count
    users[totalUsers] = newUser;
    totalUsers++;
    printf("User %s added successfully!\n", newUser.name);
}

void recordFitnessData(int userIndex) {
    if (users[userIndex].dataCount >= MAX_DATA_POINTS) {
        printf("Maximum data points reached for user %s!\n", users[userIndex].name);
        return;
    }

    FitnessData newData;
    printf("Enter the number of steps: ");
    scanf("%d", &newData.steps);
    printf("Enter the distance (km): ");
    scanf("%f", &newData.distance);
    printf("Enter the calories burned: ");
    scanf("%f", &newData.calories);

    users[userIndex].data[users[userIndex].dataCount] = newData;
    users[userIndex].dataCount++;
    printf("Fitness data recorded successfully for %s!\n", users[userIndex].name);
}

void displayUserInfo(int userIndex) {
    User user = users[userIndex];
    printf("\nUser Info:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f cm\n", user.height);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Recorded Fitness Data:\n");
    
    for (int i = 0; i < user.dataCount; i++) {
        printf("  Entry %d: Steps: %d, Distance: %.2f km, Calories: %.2f\n", 
               i + 1, user.data[i].steps, user.data[i].distance, user.data[i].calories);
    }
}

void displayAllUsers() {
    printf("\nAll Users:\n");
    for (int i = 0; i < totalUsers; i++) {
        printf("User %d: %s\n", i + 1, users[i].name);
    }
}

int findUser(char* name) {
    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i; // Return the index of the found user
        }
    }
    return -1; // User not found
}