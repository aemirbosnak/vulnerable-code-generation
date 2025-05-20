//FormAI DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_NUM_PASSWORDS 100

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int num_passwords = 0;
Password passwords[MAX_NUM_PASSWORDS];

void add_password() {
    if (num_passwords == MAX_NUM_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    Password new_password;
    printf("Enter a username: ");
    fgets(new_password.username, 50, stdin);

    printf("Enter a password: ");
    fgets(new_password.password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline characters from input
    new_password.username[strcspn(new_password.username, "\n")] = 0;
    new_password.password[strcspn(new_password.password, "\n")] = 0;

    passwords[num_passwords++] = new_password;

    printf("Password added.\n");
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Stored passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }
}

bool check_password(char* username, char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0 && strcmp(passwords[i].password, password) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    while (1) {
        printf("\n");
        printf("1. Add a password\n");
        printf("2. View stored passwords\n");
        printf("3. Check a password\n");
        printf("4. Exit program\n");
        printf("Enter a number: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline character left over from scanf

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3: {
                char username[50];
                char password[MAX_PASSWORD_LENGTH];
                printf("Enter a username: ");
                fgets(username, 50, stdin);
                printf("Enter a password: ");
                fgets(password, MAX_PASSWORD_LENGTH, stdin);
                username[strcspn(username, "\n")] = 0;
                password[strcspn(password, "\n")] = 0;
                bool result = check_password(username, password);
                if (result) {
                    printf("Password is correct.\n");
                } else {
                    printf("Password is incorrect.\n");
                }
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}