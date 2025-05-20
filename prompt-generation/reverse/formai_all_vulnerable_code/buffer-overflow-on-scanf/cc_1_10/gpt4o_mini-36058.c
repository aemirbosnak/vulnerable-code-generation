//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_USERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_NAME_LENGTH];
} User;

void addUser(User* users, int* count) {
    if (*count >= MAX_USERS) {
        printf("User limit reached. Unable to add more users.\n");
        return;
    }

    User* newUser = &users[*count];
    printf("Enter name: ");
    fgets(newUser->name, MAX_NAME_LENGTH, stdin);
    strtok(newUser->name, "\n");  // Remove newline character

    printf("Enter age: ");
    scanf("%d", &newUser->age);
    getchar(); // Clear the input buffer

    printf("Enter email: ");
    fgets(newUser->email, MAX_NAME_LENGTH, stdin);
    strtok(newUser->email, "\n"); // Remove newline character

    (*count)++;
    printf("User added successfully!\n");
}

void viewUsers(User* users, int count) {
    if (count == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("\nList of Users:\n");
    for (int i = 0; i < count; i++) {
        printf("User %d: \n", i + 1);
        printf("Name: %s\n", users[i].name);
        printf("Age: %d\n", users[i].age);
        printf("Email: %s\n\n", users[i].email);
    }
}

void freeMemory(User* users) {
    // In this case, no dynamic allocation was done, 
    // but this function can be used to manage memory if it were implemented
    // appropriately in a more complex scenario. 
}

int main() {
    User* users = (User*)malloc(MAX_USERS * sizeof(User));
    if (users == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int userCount = 0;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Add User\n");
        printf("2. View Users\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the input buffer

        switch (choice) {
            case 1:
                addUser(users, &userCount);
                break;
            case 2:
                viewUsers(users, userCount);
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    free(users);
    return 0;
}