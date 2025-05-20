//Falcon-180B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
    int length;
    time_t last_updated;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\n");
        printf("1. Create a new account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_passwords);

        switch (num_passwords) {
        case 1:
            printf("Enter your username: ");
            scanf("%s", username);

            if (num_passwords >= MAX_PASSWORDS) {
                printf("Sorry, the maximum number of accounts has been reached.\n");
            } else {
                generate_password(password, rand() % MAX_PASSWORD_LENGTH + 8);
                strcpy(passwords[num_passwords].password, password);
                strcpy(passwords[num_passwords].username, username);
                passwords[num_passwords].length = strlen(password);
                time(&passwords[num_passwords].last_updated);
                printf("Your password is: %s\n", password);
                num_passwords++;
            }

            break;

        case 2:
            printf("Enter your username: ");
            scanf("%s", username);

            int i;
            for (i = 0; i < num_passwords; i++) {
                if (strcmp(username, passwords[i].username) == 0) {
                    printf("Enter your password: ");
                    scanf("%s", password);

                    if (strcmp(password, passwords[i].password) == 0) {
                        printf("Login successful!\n");
                    } else {
                        printf("Incorrect password.\n");
                    }

                    break;
                }
            }

            if (i == num_passwords) {
                printf("User not found.\n");
            }

            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}