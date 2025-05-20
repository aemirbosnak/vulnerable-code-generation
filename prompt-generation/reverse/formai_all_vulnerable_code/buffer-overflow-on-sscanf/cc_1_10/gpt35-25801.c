//FormAI DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 10
#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

User users[MAX_USERS];
int num_users = 0;

void add_user(char* username, char* password) {
    if (num_users < MAX_USERS) {
        strcpy(users[num_users].username, username);
        strcpy(users[num_users].password, password);
        num_users++;
        printf("User added successfully!\n");
    }
    else {
        printf("Maximum number of users reached!\n");
    }
}

int main() {
    char buffer[MAX_USERNAME_LEN + MAX_PASSWORD_LEN + 2]; // +2 for space and newline
    int choice = -1;
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];

    while (choice != 0) {
        printf("Choose an option:\n");
        printf("1) Add user\n");
        printf("2) Check password\n");
        printf("0) Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter username and password separated by a space: ");
                scanf("%s", buffer);
                sscanf(buffer, "%s %s", username, password);
                add_user(username, password);
                break;
            case 2:
                printf("Enter username and password separated by a space: ");
                scanf("%s", buffer);
                sscanf(buffer, "%s %s", username, password);
                int found = 0;
                for (int i = 0; i < num_users; i++) {
                    if (strcmp(users[i].username, username) == 0 &&
                        strcmp(users[i].password, password) == 0) {
                        printf("Password correct!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Password incorrect or user not found!\n");
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\n");
    }
    return 0;
}