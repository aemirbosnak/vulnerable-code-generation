//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char service[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
};

void generate_password(char* password, int length) {
    const char* charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char service[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the password manager, dear Watson.\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new password\n");
        printf("2. Retrieve a password\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the service name (e.g. Facebook): ");
            scanf("%s", service);

            printf("Enter the username: ");
            scanf("%s", username);

            generate_password(password, rand() % MAX_PASSWORD_LENGTH + 8);

            strcpy(passwords[num_passwords].service, service);
            strcpy(passwords[num_passwords].username, username);
            strcpy(passwords[num_passwords].password, password);

            num_passwords++;

            printf("\nPassword generated and saved.\n");
        } else if (choice == 2) {
            printf("Enter the service name: ");
            scanf("%s", service);

            for (int i = 0; i < num_passwords; i++) {
                if (strcmp(passwords[i].service, service) == 0) {
                    printf("\nService: %s\nUsername: %s\nPassword: %s\n", passwords[i].service, passwords[i].username, passwords[i].password);
                }
            }
        } else if (choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}