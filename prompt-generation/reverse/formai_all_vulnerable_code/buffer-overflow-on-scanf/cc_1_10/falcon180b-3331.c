//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 10
#define MAX_STEPS 1000

// User data structure
typedef struct {
    char name[20];
    int age;
    int gender;
    int steps[MAX_STEPS];
    int num_steps;
} User;

// Function prototypes
void createUser(User *user);
void displayUser(User user);
void addSteps(User *user, int steps);
void displaySteps(User user);

int main() {
    User users[MAX_USERS];
    int choice, num_users;

    // Initialize variables
    num_users = 0;

    // Main menu
    do {
        printf("\n*** Fitness Tracker ***\n");
        printf("1. Create user\n");
        printf("2. Display user\n");
        printf("3. Add steps\n");
        printf("4. Display steps\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_users >= MAX_USERS) {
                    printf("Maximum number of users reached.\n");
                } else {
                    createUser(&users[num_users]);
                    num_users++;
                }
                break;
            case 2:
                printf("Enter user number: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_users) {
                    displayUser(users[choice]);
                } else {
                    printf("Invalid user number.\n");
                }
                break;
            case 3:
                printf("Enter user number: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_users) {
                    printf("Enter number of steps: ");
                    scanf("%d", &users[choice].steps[users[choice].num_steps]);
                    users[choice].num_steps++;
                } else {
                    printf("Invalid user number.\n");
                }
                break;
            case 4:
                printf("Enter user number: ");
                scanf("%d", &choice);
                if(choice >= 0 && choice < num_users) {
                    displaySteps(users[choice]);
                } else {
                    printf("Invalid user number.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);

    return 0;
}

// Function to create a new user
void createUser(User *user) {
    printf("Enter name: ");
    scanf("%s", user->name);
    printf("Enter age: ");
    scanf("%d", &user->age);
    printf("Enter gender (1 for male, 2 for female): ");
    scanf("%d", &user->gender);
    user->num_steps = 0;
}

// Function to display user data
void displayUser(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Gender: %d\n", user.gender);
    printf("Total steps: %d\n", user.num_steps);
}

// Function to add steps for a user
void addSteps(User *user, int steps) {
    if(user->num_steps >= MAX_STEPS) {
        printf("Maximum number of steps reached.\n");
    } else {
        user->steps[user->num_steps] = steps;
        user->num_steps++;
    }
}

// Function to display steps for a user
void displaySteps(User user) {
    printf("Steps:\n");
    for(int i=0; i<user.num_steps; i++) {
        printf("%d\n", user.steps[i]);
    }
}