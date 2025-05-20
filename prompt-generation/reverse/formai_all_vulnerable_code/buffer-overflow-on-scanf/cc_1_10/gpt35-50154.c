//FormAI DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store user details
typedef struct {
    char name[50];
    int age;
    char email[100];
} User;

// Function to add user to database
void add_user(User *db, int *num_users) {
    // Get user details
    User new_user;
    printf("Enter name: ");
    scanf("%s", new_user.name);
    printf("Enter age: ");
    scanf("%d", &new_user.age);
    printf("Enter email: ");
    scanf("%s", new_user.email);

    // Add user to database
    db[*num_users] = new_user;
    (*num_users)++;

    printf("User added successfully!\n");
}

// Function to print all users in database
void print_users(User *db, int num_users) {
    for (int i = 0; i < num_users; i++) {
        printf("User %d\n", i+1);
        printf("Name: %s\n", db[i].name);
        printf("Age: %d\n", db[i].age);
        printf("Email: %s\n\n", db[i].email);
    }
}

int main() {
    // Initialize database with array of size 10
    User db[10];
    int num_users = 0;

    // Display menu to user
    int option = 0;
    while (option != 3) {
        printf("DATABASE SIMULATION\n");
        printf("1. Add user\n");
        printf("2. Print users\n");
        printf("3. Quit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        printf("\n");

        // Call appropriate function based on user's option
        switch (option) {
            case 1:
                add_user(db, &num_users);
                break;
            case 2:
                print_users(db, num_users);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n\n");
        }
    }

    return 0;
}