//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of user entries
#define MAX_ENTRIES 10

// Define a user struct to store user information
typedef struct user {
    char name[50];
    int age;
} User;

// Define the users array to store user entries
User users[MAX_ENTRIES];
int num_users = 0;

// Function to add a user entry to the database
void add_user(char *name, int age) {
    if (num_users >= MAX_ENTRIES) {
        printf("Database is full.\n");
        return;
    }

    strcpy(users[num_users].name, name);
    users[num_users].age = age;
    num_users++;
}

// Function to remove a user entry from the database
void remove_user(char *name) {
    int i;

    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            for (int j = i; j < num_users - 1; j++) {
                strcpy(users[j].name, users[j + 1].name);
            }

            num_users--;
            return;
        }
    }

    printf("User not found.\n");
}

// Function to view all user entries in the database
void view_users() {
    int i;

    printf("User Name   Age\n");
    printf("------------------------------\n");
    for (i = 0; i < num_users; i++) {
        printf("%s  %d\n", users[i].name, users[i].age);
    }
}

int main() {
    int choice;
    char name[50];
    int age;

    printf("Welcome to the User Database!\n");
    printf("1. Add User\n");
    printf("2. Remove User\n");
    printf("3. View Users\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                add_user(name, age);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                remove_user(name);
                break;
            case 3:
                view_users();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}