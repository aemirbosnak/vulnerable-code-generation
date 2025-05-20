//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void create_account(char username[20], char password[20]);
void login(char username[20], char password[20]);
void register_workout(int calories_burned);
void view_history(char username[20]);

int main() {
    char username[20], password[20];
    int choice, calories_burned;

    // Initialize random seed
    srand(time(NULL));

    // Main menu
    do {
        printf("Fitness Tracker\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Register Workout\n");
        printf("4. View History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                create_account(username, password);
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                login(username, password);
                break;

            case 3:
                printf("Enter calories burned: ");
                scanf("%d", &calories_burned);
                register_workout(calories_burned);
                break;

            case 4:
                printf("Enter username: ");
                scanf("%s", username);
                view_history(username);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= 5);

    return 0;
}

// Function to create a new account
void create_account(char username[20], char password[20]) {
    printf("Account created successfully!\n");
}

// Function to login into an existing account
void login(char username[20], char password[20]) {
    printf("Login successful!\n");
}

// Function to register a new workout
void register_workout(int calories_burned) {
    printf("Workout registered successfully!\n");
}

// Function to view workout history
void view_history(char username[20]) {
    int i, j;
    char workout_type[20];
    int calories_burned;

    printf("Workout History for %s:\n", username);

    for(i=0; i<3; i++) {
        printf("Workout %d:\n", i+1);
        printf("Type: ");
        scanf("%s", workout_type);
        printf("Calories Burned: ");
        scanf("%d", &calories_burned);
        printf("\n");
    }
}