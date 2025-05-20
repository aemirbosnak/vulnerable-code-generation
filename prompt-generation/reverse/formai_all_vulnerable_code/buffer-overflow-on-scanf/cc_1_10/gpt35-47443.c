//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a user record
typedef struct {
    int id;
    char name[50];
    int age;
} User;

// Declare global array of users
User database[100];
int num_users = 0;

// Function to add a user to the database
void add_user() {
    User user;
    printf("Enter user ID: ");
    scanf("%d", &user.id);
    printf("Enter user name: ");
    scanf("%s", user.name);
    printf("Enter user age: ");
    scanf("%d", &user.age);
    database[num_users++] = user;
    printf("User added to database.\n");
}

// Function to search for a user by ID
void search_user() {
    int id;
    printf("Enter user ID: ");
    scanf("%d", &id);
    for (int i=0; i<num_users; i++) {
        if (database[i].id == id) {
            printf("User found:\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            return;
        }
    }
    printf("User not found.\n");
}

// Function to print all user records
void print_users() {
    printf("ID\tName\tAge\n");
    for (int i=0; i<num_users; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add user\n");
        printf("2. Search for user\n");
        printf("3. Print all users\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                search_user();
                break;
            case 3:
                print_users();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}