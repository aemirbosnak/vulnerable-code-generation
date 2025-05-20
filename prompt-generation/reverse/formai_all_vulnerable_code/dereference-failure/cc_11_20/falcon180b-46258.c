//Falcon-180B DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_NUM 10
#define MAX_PASSWORD_LEN 20

typedef struct {
    char username[MAX_USER_NUM];
    char password[MAX_PASSWORD_LEN];
} User;

int main() {
    int num_users = 0;
    User users[MAX_USER_NUM];

    while(num_users < MAX_USER_NUM) {
        User new_user;
        printf("Enter a new username: ");
        scanf("%s", new_user.username);

        if(num_users == 0) {
            strcpy(users[0].username, new_user.username);
        } else {
            int i;
            for(i = 0; i < num_users; i++) {
                if(strcmp(users[i].username, new_user.username) == 0) {
                    printf("Error: Duplicate username\n");
                    break;
                }
            }
            if(i == num_users) {
                strcpy(users[num_users].username, new_user.username);
                num_users++;
            }
        }

        printf("Enter the password for %s: ", new_user.username);
        scanf("%s", new_user.password);
        strcpy(users[num_users-1].password, new_user.password);

        printf("\nUser added successfully!\n");
    }

    int choice;
    while(1) {
        printf("Enter your choice:\n1. Login\n2. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter your username: ");
            char username[MAX_USER_NUM];
            scanf("%s", username);

            int i;
            for(i = 0; i < num_users; i++) {
                if(strcmp(users[i].username, username) == 0) {
                    printf("Enter your password: ");
                    char password[MAX_PASSWORD_LEN];
                    scanf("%s", password);

                    if(strcmp(users[i].password, password) == 0) {
                        printf("\nLogin successful!\n");
                        break;
                    } else {
                        printf("\nIncorrect password!\n");
                    }
                }
            }
        } else if(choice == 2) {
            break;
        } else {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}