//FormAI DATASET v1.0 Category: Database querying ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    char email[50];
    int age;
} User;

void printUser(User user) {
    printf("ID: %d\nName: %s\nEmail: %s\nAge: %d\n\n", user.id, user.name, user.email, user.age);
}

void searchById(User *users, int id, int numUsers) {
    int i;
    printf("Searching for user with ID %d...\n", id);
    for(i=0;i<numUsers;i++) {
        if(users[i].id == id) {
            printUser(users[i]);
            return;
        }
    }
    printf("User not found.\n");
}

void searchByName(User *users, char *name, int numUsers) {
    int i;
    printf("Searching for users with name %s...\n", name);
    for(i=0;i<numUsers;i++) {
        if(strcmp(users[i].name, name) == 0) {
            printUser(users[i]);
        }
    }
}

int main() {
    User users[5] = {{1, "John Doe", "johndoe@gmail.com", 30},
                     {2, "Jane Smith", "janesmith@yahoo.com", 25},
                     {3, "Bob Johnson", "bjohnson@hotmail.com", 40},
                     {4, "Sarah Lee", "sarahlee@gmail.com", 20},
                     {5, "Mike Brown", "mbrown@gmail.com", 35}};

    int numUsers = 5;

    printf("Welcome to the User Querying System!\n");
    printf("Here are the available users:\n");
    int i;
    for(i=0;i<numUsers;i++) {
        printUser(users[i]);
    }

    int choice;
    do {
        printf("What would you like to search by?\n");
        printf("1. ID\n");
        printf("2. Name\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int id;
                printf("Enter the ID to search for: ");
                scanf("%d", &id);
                searchById(users, id, numUsers);
                break;
            }
            case 2: {
                char name[20];
                printf("Enter the name to search for: ");
                scanf("%s", name);
                searchByName(users, name, numUsers);
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    } while(choice != 3);

    return 0;
}