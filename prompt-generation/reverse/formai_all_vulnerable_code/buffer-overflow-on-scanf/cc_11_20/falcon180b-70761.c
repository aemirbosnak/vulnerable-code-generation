//Falcon-180B DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

int main() {
    int choice, i;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    User users[MAX_USERS];
    int num_users = 0;

    while(1) {
        printf("\nPassword Manager\n");
        printf("1. Create account\n");
        printf("2. Login\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                for(i=0; i<num_users; i++) {
                    if(strcmp(users[i].username, username) == 0) {
                        printf("Username already exists.\n");
                        break;
                    }
                }

                if(i == num_users) {
                    strcpy(users[num_users].username, username);
                    strcpy(users[num_users].password, password);
                    num_users++;
                    printf("Account created successfully.\n");
                }
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                for(i=0; i<num_users; i++) {
                    if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                        printf("Login successful.\n");
                        break;
                    }
                }

                if(i == num_users) {
                    printf("Login failed.\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}