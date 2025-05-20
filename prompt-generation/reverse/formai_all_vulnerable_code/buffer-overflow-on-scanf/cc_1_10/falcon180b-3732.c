//Falcon-180B DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER 100
#define MAX_PASS 100

struct user {
    char name[MAX_USER];
    char pass[MAX_PASS];
};

void add_user(struct user *user) {
    printf("Enter username: ");
    scanf("%s", user->name);
    printf("Enter password: ");
    scanf("%s", user->pass);
}

void login(struct user *user) {
    printf("Enter username: ");
    char input_name[MAX_USER];
    scanf("%s", input_name);
    printf("Enter password: ");
    char input_pass[MAX_PASS];
    scanf("%s", input_pass);

    if (strcmp(user->name, input_name) == 0 && strcmp(user->pass, input_pass) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Incorrect login information.\n");
    }
}

void main() {
    struct user user[MAX_USER];
    int num_users = 0;

    while (num_users < MAX_USER) {
        add_user(&user[num_users]);
        num_users++;
    }

    int choice;
    while (1) {
        printf("\n1. Login\n2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter username: ");
            char input_name[MAX_USER];
            scanf("%s", input_name);
            int user_index = -1;

            for (int i = 0; i < num_users; i++) {
                if (strcmp(user[i].name, input_name) == 0) {
                    user_index = i;
                    break;
                }
            }

            if (user_index == -1) {
                printf("User not found.\n");
            } else {
                login(&user[user_index]);
            }
        } else if (choice == 2) {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }
}