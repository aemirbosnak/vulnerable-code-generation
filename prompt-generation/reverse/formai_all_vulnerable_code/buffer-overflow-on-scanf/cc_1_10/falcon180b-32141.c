//Falcon-180B DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20
#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define MAX_ATTEMPTS 3
#define SALT_LENGTH 16

typedef struct {
    char password[PASSWORD_LENGTH];
    time_t last_modified;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Cannot add more passwords.\n");
        return;
    }

    Password new_password;
    strcpy(new_password.password, password);
    new_password.last_modified = time(NULL);

    passwords[num_passwords] = new_password;
    num_passwords++;
}

int get_password_index(char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            return i;
        }
    }

    return -1;
}

int authenticate(char* password) {
    int index = get_password_index(password);

    if (index == -1) {
        printf("Invalid password.\n");
        return 0;
    }

    time_t current_time = time(NULL);
    time_t elapsed_time = difftime(current_time, passwords[index].last_modified);

    if (elapsed_time > (60 * 60 * 24 * 30)) {
        printf("Password has expired. Please change your password.\n");
        return 0;
    }

    return 1;
}

int change_password(char* old_password, char* new_password) {
    int index = get_password_index(old_password);

    if (index == -1) {
        printf("Invalid password.\n");
        return 0;
    }

    if (!authenticate(old_password)) {
        printf("Authentication failed. Please try again.\n");
        return 0;
    }

    if (strcmp(new_password, old_password) == 0) {
        printf("New password cannot be the same as the old password.\n");
        return 0;
    }

    if (strlen(new_password) < MIN_LENGTH || strlen(new_password) > MAX_LENGTH) {
        printf("Password must be between %d and %d characters long.\n", MIN_LENGTH, MAX_LENGTH);
        return 0;
    }

    strcpy(passwords[index].password, new_password);
    passwords[index].last_modified = time(NULL);

    printf("Password changed successfully.\n");
    return 1;
}

int main() {
    char username[20];
    char password[PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    int index = get_password_index(username);

    if (index == -1) {
        add_password(username);
    } else {
        printf("Enter your current password: ");
        scanf("%s", password);

        if (authenticate(password)) {
            printf("Enter your new password: ");
            scanf("%s", password);

            if (change_password(password, password)) {
                printf("Your password has been changed.\n");
            }
        }
    }

    return 0;
}