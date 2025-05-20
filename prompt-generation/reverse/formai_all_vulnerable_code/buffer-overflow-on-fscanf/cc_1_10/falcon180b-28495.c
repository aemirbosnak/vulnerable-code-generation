//Falcon-180B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void create_password(Password *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_size = strlen(charset);
    int password_length = rand() % MAX_PASSWORD_LENGTH + 1;

    for (int i = 0; i < password_length; i++) {
        password->password[i] = charset[rand() % charset_size];
    }
    password->password[password_length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    FILE *file = fopen("passwords.txt", "r");

    if (file == NULL) {
        printf("No passwords found.\n");
    } else {
        while (fscanf(file, "%s %s\n", passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
            num_passwords++;
        }
        fclose(file);

        char username[MAX_USERNAME_LENGTH];
        printf("Enter your username: ");
        scanf("%s", username);

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(username, passwords[i].username) == 0) {
                printf("Password: %s\n", passwords[i].password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("User not found.\n");
        }
    }

    return 0;
}