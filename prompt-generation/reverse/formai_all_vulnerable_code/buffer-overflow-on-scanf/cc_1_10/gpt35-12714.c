//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of users that can be tracked
#define MAX_USERS 100

// Define the maximum length of user names
#define MAX_NAME_LENGTH 30

// Define the maximum length of the fitness routine titles
#define MAX_ROUTINE_TITLE_LENGTH 50

// Define a structure to store the user information
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float weight;
    float height;
} User;

// Define a structure to store the fitness routine information
typedef struct {
    int id;
    char title[MAX_ROUTINE_TITLE_LENGTH];
    float duration;
    float caloriesBurned;
} Routine;

// Define a structure to store the user's fitness data
typedef struct {
    int routineId;
    float duration;
} FitnessData;

// Define a function that will display the menu options
void displayMenu() {
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please select an option:\n");
    printf("1. Add a user\n");
    printf("2. Add a fitness routine\n");
    printf("3. Log fitness data for a user\n");
    printf("4. View user's fitness history\n");
    printf("5. Exit\n");
}

// Define a function that will add a new user to the system
void addUser(User *users, int *numUsers) {
    // Check if the maximum number of users has been reached
    if (*numUsers == MAX_USERS) {
        printf("Error: Maximum number of users reached\n");
        return;
    }
    
    // Get the user information from the user
    User user;
    printf("Enter user name: ");
    scanf("%s", user.name);
    printf("Enter user weight: ");
    scanf("%f", &user.weight);
    printf("Enter user height: ");
    scanf("%f", &user.height);
    
    // Assign a unique ID to the user and add the user to the array
    user.id = *numUsers + 1;
    users[*numUsers] = user;
    *numUsers = *numUsers + 1;
    
    printf("User added successfully!\n");
}

// Define a function that will add a new fitness routine to the system
void addRoutine(Routine *routines, int *numRoutines) {
    // Check if the maximum number of routines has been reached
    if (*numRoutines == MAX_USERS) {
        printf("Error: Maximum number of routines reached\n");
        return;
    }
    
    // Get the routine information from the user
    Routine routine;
    printf("Enter routine title: ");
    scanf("%s", routine.title);
    printf("Enter routine duration: ");
    scanf("%f", &routine.duration);
    printf("Enter calories burned: ");
    scanf("%f", &routine.caloriesBurned);
    
    // Assign a unique ID to the routine and add it to the array
    routine.id = *numRoutines + 1;
    routines[*numRoutines] = routine;
    *numRoutines = *numRoutines + 1;
    
    printf("Routine added successfully!\n");
}

// Define a function that will log fitness data for a user
void logFitnessData(User *users, int numUsers, Routine *routines, int numRoutines, FitnessData *fitnessData, int *numFitnessData) {
    // Get the user ID from the user
    int userId;
    printf("Enter user ID: ");
    scanf("%d", &userId);
    
    // Find the user in the array
    int userIndex = -1;
    for (int i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            userIndex = i;
            break;
        }
    }
    
    if (userIndex == -1) {
        printf("Error: User not found\n");
        return;
    }
    
    // Get the routine ID from the user
    int routineId;
    printf("Enter routine ID: ");
    scanf("%d", &routineId);
    
    // Find the routine in the array
    int routineIndex = -1;
    for (int i = 0; i < numRoutines; i++) {
        if (routines[i].id == routineId) {
            routineIndex = i;
            break;
        }
    }
    
    if (routineIndex == -1) {
        printf("Error: Routine not found\n");
        return;
    }
    
    // Get the fitness data from the user
    FitnessData data;
    data.routineId = routineId;
    printf("Enter duration: ");
    scanf("%f", &data.duration);
    
    // Add the fitness data to the array
    fitnessData[*numFitnessData] = data;
    *numFitnessData = *numFitnessData + 1;
    
    printf("Fitness data logged successfully for user '%s'!\n", users[userIndex].name);
}

// Define a function that will display a user's fitness history
void viewFitnessHistory(User *users, int numUsers, Routine *routines, int numRoutines, FitnessData *fitnessData, int numFitnessData) {
    // Get the user ID from the user
    int userId;
    printf("Enter user ID: ");
    scanf("%d", &userId);
    
    // Find the user in the array
    int userIndex = -1;
    for (int i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            userIndex = i;
            break;
        }
    }
    
    if (userIndex == -1) {
        printf("Error: User not found\n");
        return;
    }
    
    printf("Fitness history for user '%s':\n", users[userIndex].name);
    
    // Loop through the fitness data and display it for the user
    for (int i = 0; i < numFitnessData; i++) {
        if (fitnessData[i].routineId == routines[i].id) {
            printf("%s (%.2f minutes, %.2f calories burned)\n", routines[i].title, fitnessData[i].duration, routines[i].caloriesBurned);
        }
    }
}

// Define the main function
int main() {
    // Initialize the arrays and variables
    User users[MAX_USERS];
    int numUsers = 0;
    
    Routine routines[MAX_USERS];
    int numRoutines = 0;
    
    FitnessData fitnessData[MAX_USERS];
    int numFitnessData = 0;
    
    // Display the menu and get the user's input
    int choice = 0;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser(users, &numUsers);
                break;
                
            case 2:
                addRoutine(routines, &numRoutines);
                break;
                
            case 3:
                logFitnessData(users, numUsers, routines, numRoutines, fitnessData, &numFitnessData);
                break;
                
            case 4:
                viewFitnessHistory(users, numUsers, routines, numRoutines, fitnessData, numFitnessData);
                break;
                
            case 5:
                printf("Thank you for using the C Fitness Tracker!\n");
                break;
                
            default:
                printf("Error: Invalid input\n");
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}