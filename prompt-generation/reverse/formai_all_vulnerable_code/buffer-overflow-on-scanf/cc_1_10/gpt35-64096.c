//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

typedef struct user{
    char username[50];
    char password[50];
    char role[50];
} User;

User users[MAX_USERS];
int numUsers = 0;

void addUser() {
    printf("Enter username: ");
    scanf("%s", users[numUsers].username);
    printf("Enter password: ");
    scanf("%s", users[numUsers].password);
    printf("Enter role: ");
    scanf("%s", users[numUsers].role);
    numUsers++;
    printf("User added successfully!\n");
}

void deleteUser() {
    char username[50];
    printf("Enter username to delete: ");
    scanf("%s", username);
    for(int i=0; i<numUsers; i++) {
        if(strcmp(username, users[i].username) == 0) {
            for(int j=i; j<numUsers-1; j++) {
                strcpy(users[j].username, users[j+1].username);
                strcpy(users[j].password, users[j+1].password);
                strcpy(users[j].role, users[j+1].role);
            }
            numUsers--;
            printf("User deleted successfully!\n");
            return;
        }
    }
    printf("User not found!\n");
}

void listUsers() {
    if(numUsers == 0) {
        printf("No users found!\n");
        return;
    }
    printf("Username\tPassword\tRole\n");
    for(int i=0; i<numUsers; i++) {
        printf("%s\t\t%s\t\t%s\n", users[i].username, users[i].password, users[i].role);
    }
}

int main() {
    int option;
    do {
        printf("\n1. Add User\n");
        printf("2. Delete User\n");
        printf("3. List Users\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                listUsers();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while(option != 4);
    return 0;
}