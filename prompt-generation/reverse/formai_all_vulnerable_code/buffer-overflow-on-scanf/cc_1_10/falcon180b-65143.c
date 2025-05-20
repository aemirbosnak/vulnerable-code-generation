//Falcon-180B DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char* username;
    char* password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char* password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int length = strlen(charset);

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % length];
    }

    password[PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    srand(time(NULL));

    char username[20];
    char password[PASSWORD_LENGTH];

    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nPlease enter a username (max 20 characters): ");
        scanf("%s", username);

        if (strlen(username) >= 20) {
            printf("Username is too long.\n");
            continue;
        }

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (!strcmp(passwords[i].username, username)) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Username already exists.\n");
        } else {
            generate_password(password);

            printf("\nYour new password is: %s\n", password);

            strcpy(passwords[num_passwords].username, username);
            strcpy(passwords[num_passwords].password, password);

            num_passwords++;

            printf("\nPassword saved!\n");
        }
    }

    return 0;
}