//Falcon-180B DATASET v1.0 Category: Password management ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USER 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USER];
    char password[MAX_PASSWORD_LENGTH];
} user;

void create_user(user *new_user) {
    printf("Enter username: ");
    scanf("%s", new_user->username);

    printf("Enter password: ");
    scanf("%s", new_user->password);
}

void display_users(user *users, int num_users) {
    printf("\nUser List:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%d. %s - %s\n", i+1, users[i].username, users[i].password);
    }
}

void login(user *users, int num_users) {
    printf("\nEnter username: ");
    char username[MAX_USER];
    scanf("%s", username);

    int user_index = -1;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            user_index = i;
            break;
        }
    }

    if (user_index == -1) {
        printf("Invalid username!\n");
        return;
    }

    printf("\nEnter password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    if (strcmp(users[user_index].password, password) == 0) {
        printf("\nLogin successful!\n");
    } else {
        printf("\nIncorrect password!\n");
    }
}

int main() {
    user users[MAX_USER];
    int num_users = 0;

    while (1) {
        printf("\n\n1. Create user\n2. Login\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_users == MAX_USER) {
                    printf("\nMaximum number of users reached!\n");
                } else {
                    user new_user;
                    create_user(&new_user);
                    strcpy(users[num_users].username, new_user.username);
                    strcpy(users[num_users].password, new_user.password);
                    num_users++;
                    printf("\nUser created successfully!\n");
                }
                break;

            case 2:
                login(users, num_users);
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}