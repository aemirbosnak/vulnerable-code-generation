//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_WORKOUTS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float weight;
    float height;
    int workout_count;
    float workouts[MAX_WORKOUTS]; // Distances run in kilometers
} User;

User users[MAX_USERS];
int user_count = 0;

void addUser() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached! Cannot add more users.\n");
        return;
    }

    User new_user;
    
    printf("Enter name: ");
    scanf("%s", new_user.name);
    printf("Enter age: ");
    scanf("%d", &new_user.age);
    printf("Enter weight (kg): ");
    scanf("%f", &new_user.weight);
    printf("Enter height (m): ");
    scanf("%f", &new_user.height);
    
    new_user.workout_count = 0;

    users[user_count++] = new_user;
    printf("User %s added successfully!\n", new_user.name);
}

void logWorkout() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the user: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            float distance;
            printf("Enter workout distance (km): ");
            scanf("%f", &distance);
            
            if (users[i].workout_count < MAX_WORKOUTS) {
                users[i].workouts[users[i].workout_count++] = distance;
                printf("Workout logged for %s: %.2f km\n", users[i].name, distance);
            } else {
                printf("Workout limit reached for %s!\n", users[i].name);
            }
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("User not found!\n");
    }
}

void viewWorkouts() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the user: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Workouts for %s:\n", users[i].name);
            for (int j = 0; j < users[i].workout_count; j++) {
                printf("- Workout %d: %.2f km\n", j + 1, users[i].workouts[j]);
            }
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("User not found!\n");
    }
}

void calculateStatistics() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the user: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            found = 1;
            if (users[i].workout_count == 0) {
                printf("No workouts logged for %s!\n", users[i].name);
            } else {
                float total_distance = 0;
                for (int j = 0; j < users[i].workout_count; j++) {
                    total_distance += users[i].workouts[j];
                }
                float average_distance = total_distance / users[i].workout_count;
                printf("Statistics for %s:\n", users[i].name);
                printf("Total Distance: %.2f km\n", total_distance);
                printf("Average Distance: %.2f km\n", average_distance);
            }
            break;
        }
    }
    
    if (!found) {
        printf("User not found!\n");
    }
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add User\n");
    printf("2. Log Workout\n");
    printf("3. View Workouts\n");
    printf("4. Calculate Statistics\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Please choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                logWorkout();
                break;
            case 3:
                viewWorkouts();
                break;
            case 4:
                calculateStatistics();
                break;
            case 5:
                printf("Exiting Fitness Tracker. Stay Fit!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}