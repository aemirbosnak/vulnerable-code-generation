//Falcon-180B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_NUM 100
#define MAX_PASSWORD_LEN 20

typedef struct {
    char username[MAX_USER_NUM];
    char password[MAX_PASSWORD_LEN];
} user_t;

int main() {
    user_t users[MAX_USER_NUM];
    int num_users = 0;
    int choice;
    char input[MAX_USER_NUM];

    printf("Welcome to the Password Management System!\n");
    printf("Please enter your username: ");
    scanf("%s", input);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, input) == 0) {
            printf("User already exists.\n");
            return 1;
        }
    }
    strcpy(users[num_users].username, input);
    printf("Please enter your password: ");
    scanf("%s", users[num_users].password);
    num_users++;

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Log in\n");
        printf("2. Create user\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please enter your username: ");
                scanf("%s", input);
                for (int i = 0; i < num_users; i++) {
                    if (strcmp(users[i].username, input) == 0) {
                        printf("Please enter your password: ");
                        scanf("%s", input);
                        if (strcmp(users[i].password, input) == 0) {
                            printf("Login successful.\n");
                        } else {
                            printf("Login failed.\n");
                        }
                    } else {
                        printf("User not found.\n");
                    }
                }
                break;
            case 2:
                printf("Please enter your username: ");
                scanf("%s", input);
                for (int i = 0; i < num_users; i++) {
                    if (strcmp(users[i].username, input) == 0) {
                        printf("User already exists.\n");
                    }
                }
                printf("Please enter your password: ");
                scanf("%s", input);
                strcpy(users[num_users].username, input);
                strcpy(users[num_users].password, input);
                num_users++;
                printf("User created.\n");
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}