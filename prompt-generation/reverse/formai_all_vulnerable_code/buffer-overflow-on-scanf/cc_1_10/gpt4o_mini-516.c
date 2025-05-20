//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    int calories;   // calories burned
} UserProfile;

void initializeUser(UserProfile *user, const char *name) {
    strcpy(user->name, name);
    user->steps = 0;
    user->distance = 0.0;
    user->calories = 0;
}

void updateSteps(UserProfile *user, int steps) {
    user->steps += steps;
    user->calories += steps * 0.04; // Assuming 0.04 calories burned per step
    user->distance += steps * 0.0008; // Assuming average step is 0.8 meters
}

void displayUserProfile(const UserProfile *user) {
    printf("User Profile for %s:\n", user->name);
    printf("Total Steps: %d\n", user->steps);
    printf("Total Distance: %.2f km\n", user->distance);
    printf("Total Calories Burned: %d kcal\n\n", user->calories);
}

void displayAllUsers(UserProfile users[], int userCount) {
    for (int i = 0; i < userCount; i++) {
        displayUserProfile(&users[i]);
    }
}

int main() {
    UserProfile users[MAX_USERS];
    int userCount = 0;
    char command[10];

    printf("Welcome to the C Fitness Tracker!\n");
    
    while (1) {
        printf("Enter a command (add, update, view, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (userCount >= MAX_USERS) {
                printf("User limit reached. Cannot add more users.\n");
                continue;
            }
            char name[NAME_LENGTH];
            printf("Enter user name: ");
            scanf("%s", name);
            initializeUser(&users[userCount], name);
            userCount++;
            printf("User %s added!\n", name);
        } else if (strcmp(command, "update") == 0) {
            if (userCount == 0) {
                printf("No users to update. Please add a user first.\n");
                continue;
            }
            char name[NAME_LENGTH];
            int steps;
            printf("Enter user name: ");
            scanf("%s", name);
            printf("Enter number of steps: ");
            scanf("%d", &steps);

            int found = 0;
            for (int i = 0; i < userCount; i++) {
                if (strcmp(users[i].name, name) == 0) {
                    updateSteps(&users[i], steps);
                    printf("Updated %d steps for user %s.\n", steps, name);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("User %s not found.\n", name);
            }
        } else if (strcmp(command, "view") == 0) {
            if (userCount == 0) {
                printf("No users to view. Please add a user first.\n");
                continue;
            }
            displayAllUsers(users, userCount);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the C Fitness Tracker. Have a great day!\n");
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}