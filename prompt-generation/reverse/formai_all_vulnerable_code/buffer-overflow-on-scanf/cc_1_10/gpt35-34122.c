//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100

int num_users = 0;
char usernames[MAX_USERS][50];
char passwords[MAX_PASSWORDS][50];

void print_menu() {
    printf("\nWelcome to Password Manager!\n");
    printf("1. Add a user and password.\n");
    printf("2. View saved passwords.\n");
    printf("3. Exit.\n");
}

void add_password() {
    char username[50];
    char password[50];

    printf("\nAdding a new user and password!\n");

    printf("Enter a username: ");
    scanf("%s", username);
    printf("Enter a password: ");
    scanf("%s", password);

    strcpy(usernames[num_users], username);
    strcpy(passwords[num_users], password);

    num_users++;
}

void view_passwords() {
    printf("\nViewing saved passwords!\n");

    for (int i = 0; i < num_users; i++) {
        printf("%s - %s\n", usernames[i], passwords[i]);
    }
}

int main() {
    int choice;

    printf("Starting Password Manager...\n");

    while (1) {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                printf("\nThank you for using Password Manager!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again!\n");
                break;
        }
    }

    return 0;
}