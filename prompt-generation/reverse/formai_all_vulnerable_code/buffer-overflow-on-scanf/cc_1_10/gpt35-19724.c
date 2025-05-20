//FormAI DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store data about a user
typedef struct {
    int id;
    char name[20];
    char email[50];
    char phone[15];
} User;

// Declare a function to get user input
void getUserInput(User *user) {
    printf("Enter user id: ");
    scanf("%d", &user->id);
    printf("Enter user name: ");
    scanf("%s", user->name);
    printf("Enter user email: ");
    scanf("%s", user->email);
    printf("Enter user phone: ");
    scanf("%s", user->phone);
}

int main() {
    // Declare variables for the database and user input
    User *users;
    int numUsers;
    int i;

    // Prompt user for number of users and allocate memory
    printf("How many users? ");
    scanf("%d", &numUsers);
    users = (User*) malloc(numUsers * sizeof(User));

    // Prompt user for data and store in memory
    for (i = 0; i < numUsers; i++) {
        printf("\nEnter data for user %d:\n", i+1);
        getUserInput(&users[i]);
    }

    // Print out all users in the database
    printf("\nAll users in the database:\n");
    printf("ID\tName\t\tEmail\t\t\tPhone\n");
    for (i = 0; i < numUsers; i++) {
        printf("%d\t%s\t%s\t%s\n", users[i].id, users[i].name, users[i].email, users[i].phone);
    }

    // Prompt user for a specific ID to search for and print out matching data
    int searchId;
    printf("\nPlease enter an ID to search for: ");
    scanf("%d", &searchId);
    for (i = 0; i < numUsers; i++) {
        if (users[i].id == searchId) {
            printf("\nFound:\n");
            printf("ID\tName\t\tEmail\t\t\tPhone\n");
            printf("%d\t%s\t%s\t%s\n", users[i].id, users[i].name, users[i].email, users[i].phone);
            break;
        }
    }

    // Free allocated memory
    free(users);
    return 0;
}