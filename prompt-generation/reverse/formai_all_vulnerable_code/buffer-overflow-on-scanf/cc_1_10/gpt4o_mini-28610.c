//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_ACTIVITIES 50

typedef struct {
    char name[50];
    int steps;
    float distance; // in kilometers
    int calories; // calories burned
} Activity;

typedef struct {
    char username[50];
    Activity activities[MAX_ACTIVITIES];
    int activity_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user() {
    if (user_count >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }
    User new_user;
    printf("Enter username: ");
    scanf("%s", new_user.username);
    new_user.activity_count = 0;

    users[user_count++] = new_user;
    printf("User '%s' added successfully!\n", new_user.username);
}

User* find_user(const char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

void add_activity(User* user) {
    if (user->activity_count >= MAX_ACTIVITIES) {
        printf("Maximum activity limit reached for user %s.\n", user->username);
        return;
    }
    Activity new_activity;
    printf("Enter steps: ");
    scanf("%d", &new_activity.steps);
    printf("Enter distance (km): ");
    scanf("%f", &new_activity.distance);
    printf("Enter calories burned: ");
    scanf("%d", &new_activity.calories);

    user->activities[user->activity_count++] = new_activity;
    printf("Activity added for user '%s'.\n", user->username);
}

void view_activities(User* user) {
    printf("Activities for user '%s':\n", user->username);
    for (int i = 0; i < user->activity_count; i++) {
        Activity act = user->activities[i];
        printf("Activity %d: Steps: %d, Distance: %.2f km, Calories: %d\n", 
               i + 1, act.steps, act.distance, act.calories);
    }
}

void reset_user_data(User* user) {
    user->activity_count = 0;
    printf("All activities for user '%s' have been reset.\n", user->username);
}

void display_menu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add User\n");
    printf("2. Add Activity\n");
    printf("3. View Activities\n");
    printf("4. Reset User Data\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char username[50];

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                User* user = find_user(username);
                if (user) {
                    add_activity(user);
                } else {
                    printf("User '%s' not found.\n", username);
                }
                break;
            case 3:
                printf("Enter username: ");
                scanf("%s", username);
                user = find_user(username);
                if (user) {
                    view_activities(user);
                } else {
                    printf("User '%s' not found.\n", username);
                }
                break;
            case 4:
                printf("Enter username: ");
                scanf("%s", username);
                user = find_user(username);
                if (user) {
                    reset_user_data(user);
                } else {
                    printf("User '%s' not found.\n", username);
                }
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}