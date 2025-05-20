//Falcon-180B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_PASSWORD_ATTEMPTS 3

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int attempts;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            printf("Error: Password already exists.\n");
            return;
        }
    }

    strcpy(passwords[num_passwords].password, password);
    passwords[num_passwords].attempts = 0;
    num_passwords++;

    printf("Password added successfully.\n");
}

int authenticate_password(char *password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            if (passwords[i].attempts >= MAX_PASSWORD_ATTEMPTS) {
                printf("Error: Maximum number of attempts reached.\n");
                return -1;
            }

            passwords[i].attempts++;
            return 0;
        }
    }

    printf("Error: Invalid password.\n");
    return -1;
}

void reset_password_attempts() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        passwords[i].attempts = 0;
    }
}

int main() {
    int choice;
    do {
        printf("\nPassword Management System\n");
        printf("1. Add a password\n");
        printf("2. Authenticate a password\n");
        printf("3. Reset password attempts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char password[MAX_PASSWORD_LENGTH];
                printf("Enter the password: ");
                scanf("%s", password);
                add_password(password);
                break;
            }
            case 2: {
                char password[MAX_PASSWORD_LENGTH];
                printf("Enter the password: ");
                scanf("%s", password);
                int result = authenticate_password(password);
                if (result == 0) {
                    printf("Password authenticated successfully.\n");
                }
                break;
            }
            case 3: {
                reset_password_attempts();
                printf("Password attempts reset successfully.\n");
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (choice!= 4);

    return 0;
}