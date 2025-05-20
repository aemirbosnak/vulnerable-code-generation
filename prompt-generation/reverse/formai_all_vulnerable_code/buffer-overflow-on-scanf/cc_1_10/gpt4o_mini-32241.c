//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EXERCISES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float weight; // in kg
    float height; // in meters
    float exercise_data[MAX_EXERCISES];
    int exercise_count;
} User;

typedef struct {
    User users[MAX_USERS];
    int user_count;
} FitnessTracker;

void initialize_tracker(FitnessTracker* tracker) {
    tracker->user_count = 0;
}

void add_user(FitnessTracker* tracker) {
    if (tracker->user_count >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    
    User new_user;
    printf("Enter name: ");
    fgets(new_user.name, MAX_NAME_LENGTH, stdin);
    new_user.name[strcspn(new_user.name, "\n")] = 0;  // Remove newline

    printf("Enter age: ");
    scanf("%d", &new_user.age);
    printf("Enter weight (kg): ");
    scanf("%f", &new_user.weight);
    printf("Enter height (m): ");
    scanf("%f", &new_user.height);
    
    new_user.exercise_count = 0;
    tracker->users[tracker->user_count] = new_user;
    tracker->user_count++;

    printf("User added successfully!\n");
    while(getchar() != '\n'); // to clear input buffer
}

void log_exercise(FitnessTracker* tracker) {
    int user_index;
    printf("Select user index to log exercise (0 to %d): ", tracker->user_count - 1);
    scanf("%d", &user_index);
    
    if (user_index < 0 || user_index >= tracker->user_count) {
        printf("Invalid user index selected.\n");
        return;
    }
    
    User* user = &tracker->users[user_index];
    
    if (user->exercise_count >= MAX_EXERCISES) {
        printf("Exercise limit reached for this user.\n");
        return;
    }
    
    printf("Enter exercise duration (in minutes): ");
    float duration;
    scanf("%f", &duration);
    
    user->exercise_data[user->exercise_count] = duration;
    user->exercise_count++;
    
    printf("Exercise logged successfully for %s!\n", user->name);
    while(getchar() != '\n'); // to clear input buffer
}

void display_user_data(FitnessTracker* tracker) {
    int user_index;
    printf("Enter user index to display (0 to %d): ", tracker->user_count - 1);
    scanf("%d", &user_index);
    
    if (user_index < 0 || user_index >= tracker->user_count) {
        printf("Invalid user index selected.\n");
        return;
    }
    
    User* user = &tracker->users[user_index];
    printf("\nUser Details:\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Height: %.2f m\n", user->height);
    
    if (user->exercise_count > 0) {
        printf("Logged Exercises:\n");
        for (int i = 0; i < user->exercise_count; i++) {
            printf("Exercise %d: %.2f minutes\n", i + 1, user->exercise_data[i]);
        }
    } else {
        printf("No exercises logged yet.\n");
    }
}

void summary(FitnessTracker* tracker) {
    printf("\nSummary of all users:\n");
    for (int i = 0; i < tracker->user_count; i++) {
        User* user = &tracker->users[i];
        printf("User %d: %s, Age: %d, Weight: %.2f kg, Height: %.2f m, Exercises logged: %d\n",
               i, user->name, user->age, user->weight, user->height, user->exercise_count);
    }
}

int main() {
    FitnessTracker tracker;
    initialize_tracker(&tracker);

    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Log Exercise\n");
        printf("3. Display User Data\n");
        printf("4. Summary of All Users\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_user(&tracker);
                break;
            case 2:
                log_exercise(&tracker);
                break;
            case 3:
                display_user_data(&tracker);
                break;
            case 4:
                summary(&tracker);
                break;
            case 5:
                printf("Exiting the program. Stay fit!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
        
    } while (choice != 5);

    return 0;
}