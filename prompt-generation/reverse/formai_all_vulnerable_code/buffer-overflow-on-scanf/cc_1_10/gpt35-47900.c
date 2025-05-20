//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 5 // Maximum number of users that can be tracked
#define MAX_WORKOUTS 3 // Maximum number of workouts that can be tracked

// Struct for workout
struct Workout {
    char name[50];
    int duration;
    int calories_burned;
};

// Struct for user
struct User {
    char name[50];
    int age;
    int weight;
    struct Workout workouts[MAX_WORKOUTS];
    int num_workouts;
};

struct User users[MAX_USERS];
int num_users = 0;

// Function to add a new user
void add_user() {
    if(num_users == MAX_USERS) {
        printf("\nError: Maximum number of users reached!\n");
        return;
    }

    struct User user;

    printf("\nEnter user name: ");
    fgets(user.name, 50, stdin);

    printf("\nEnter user age: ");
    scanf("%d", &user.age);

    printf("\nEnter user weight: ");
    scanf("%d", &user.weight);

    // Initialize workouts for user
    user.num_workouts = 0;

    users[num_users] = user;
    num_users++;

    printf("\nUser added successfully!\n");
}

// Function to add a workout for a user
void add_workout() {
    char user_name[50];
    int user_index = -1;

    printf("\nEnter user name: ");
    fgets(user_name, 50, stdin);

    // Find the index of the user with the given name
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].name, user_name) == 0) {
            user_index = i;
            break;
        }
    }

    if(user_index == -1) {
        printf("\nError: User not found!\n");
        return;
    }

    // Check if the user has reached the maximum number of workouts
    if(users[user_index].num_workouts == MAX_WORKOUTS) {
        printf("\nError: Maximum number of workouts reached for user!\n");
        return;
    }

    struct Workout workout;

    printf("\nEnter workout name: ");
    fgets(workout.name, 50, stdin);

    printf("\nEnter workout duration in minutes: ");
    scanf("%d", &workout.duration);

    srand(time(0));
    workout.calories_burned = rand() % 500; // Random value between 0 and 500 for calories burnt

    // Add workout to user
    users[user_index].workouts[users[user_index].num_workouts] = workout;
    users[user_index].num_workouts++;

    printf("\nWorkout added successfully!\n");
}

// Function to display a user's workouts
void display_workouts() {
    char user_name[50];
    int user_index = -1;

    printf("\nEnter user name: ");
    fgets(user_name, 50, stdin);

    // Find the index of the user with the given name
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].name, user_name) == 0) {
            user_index = i;
            break;
        }
    }

    if(user_index == -1) {
        printf("\nError: User not found!\n");
        return;
    }

    // Display the user's workouts
    printf("\n%s's workouts:\n", users[user_index].name);
    for(int i = 0; i < users[user_index].num_workouts; i++) {
        printf("\nWorkout %d\n", i+1);
        printf("Name: %s\n", users[user_index].workouts[i].name);
        printf("Duration: %d minutes\n", users[user_index].workouts[i].duration);
        printf("Calories burned: %d\n", users[user_index].workouts[i].calories_burned);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n\n*** C Fitness Tracker ***\n\n");
        printf("1. Add User\n");
        printf("2. Add Workout for User\n");
        printf("3. Display User's Workouts\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        getchar(); // Flush the newline character from the input buffer

        switch(choice) {
            case 1:
                add_user();
                break;

            case 2:
                add_workout();
                break;

            case 3:
                display_workouts();
                break;

            case 4:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nError: Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}