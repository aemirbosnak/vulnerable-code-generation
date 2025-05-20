//FormAI DATASET v1.0 Category: Password management ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Define maximum number of users
#define MAX_USERS 10

// Define maximum length of password
#define MAX_PASS_LEN 20

// Define structure for user data
typedef struct {
    char username[MAX_PASS_LEN];
    char password[MAX_PASS_LEN];
} User;

// Declare array to hold user data
User users[MAX_USERS];

// Declare function to add new user
void add_user() {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strlen(users[i].username) == 0) {
            printf("\nPlease enter username: ");
            scanf("%s", users[i].username);
            printf("Please enter password: ");
            scanf("%s", users[i].password);
            printf("User created successfully!\n");
            return;
        }
    }
    printf("Maximum number of users reached.\n");
}

// Declare function to check if username and password match
int check_user(char* username, char* password) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int choice;
    char username[MAX_PASS_LEN], password[MAX_PASS_LEN];
    while (1) {
        printf("Enter 1 to add new user\n");
        printf("Enter 2 to check login credentials\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                if (check_user(username, password)) {
                    printf("\nLogin successful!\n");
                } else {
                    printf("\nIncorrect username or password.\n");
                }
                break;
            case 0:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}