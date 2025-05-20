//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ACTIVITIES 10
#define USERNAME_LEN 30
#define ACTIVITY_NAME_LEN 20

typedef struct {
    char name[ACTIVITY_NAME_LEN];
    int duration; // duration in minutes
} Activity;

typedef struct {
    char username[USERNAME_LEN];
    int num_activities;
    Activity activities[MAX_ACTIVITIES];
} User;

User users[MAX_USERS];
int user_count = 0;

void addUser() {
    if (user_count >= MAX_USERS) {
        printf("Max user limit reached!\n");
        return;
    }

    User new_user;
    printf("Enter your username: ");
    scanf("%s", new_user.username);
    new_user.num_activities = 0;

    users[user_count++] = new_user;
    printf("User %s added successfully!\n", new_user.username);
}

void addActivity() {
    char username[USERNAME_LEN];
    printf("Enter your username: ");
    scanf("%s", username);
    
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (users[i].num_activities >= MAX_ACTIVITIES) {
                printf("Max activities reached for user %s!\n", username);
                return;
            }
            Activity new_activity;
            printf("Enter activity name: ");
            scanf("%s", new_activity.name);
            printf("Enter activity duration (in minutes): ");
            scanf("%d", &new_activity.duration);

            users[i].activities[users[i].num_activities++] = new_activity;
            printf("Activity %s added for user %s!\n", new_activity.name, username);
            return;
        }
    }
    printf("User %s not found!\n", username);
}

void viewActivities() {
    char username[USERNAME_LEN];
    printf("Enter your username to view activities: ");
    scanf("%s", username);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Activities for user %s:\n", username);
            for (int j = 0; j < users[i].num_activities; j++) {
                printf("%d. %s: %d minutes\n", j + 1, users[i].activities[j].name, users[i].activities[j].duration);
            }
            return;
        }
    }
    printf("User %s not found!\n", username);
}

void calculateTotalDuration() {
    char username[USERNAME_LEN];
    printf("Enter your username to calculate total activity duration: ");
    scanf("%s", username);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            int total_duration = 0;
            for (int j = 0; j < users[i].num_activities; j++) {
                total_duration += users[i].activities[j].duration;
            }
            printf("Total activity duration for user %s is: %d minutes\n", username, total_duration);
            return;
        }
    }
    printf("User %s not found!\n", username);
}

void displayMenu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Add User\n");
    printf("2. Add Activity\n");
    printf("3. View Activities\n");
    printf("4. Calculate Total Duration\n");
    printf("5. Exit\n");
    printf("============================\n");
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
                addActivity();
                break;
            case 3:
                viewActivities();
                break;
            case 4:
                calculateTotalDuration();
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}