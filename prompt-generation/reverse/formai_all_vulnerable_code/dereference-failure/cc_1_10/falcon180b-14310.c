//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8
#define CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-="

int main() {
    int password_length;
    char password[MAX_PASSWORD_LENGTH];
    char *user_password = NULL;
    int user_password_length = 0;
    char *password_copy = NULL;
    int password_copy_length = 0;
    int i;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Password length must be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    printf("Please enter your password (minimum %d characters): ", password_length);
    scanf("%s", user_password);
    user_password_length = strlen(user_password);

    if (user_password_length < password_length) {
        printf("Password must be at least %d characters long.\n", password_length);
        return 1;
    }

    password_copy = malloc(password_length + 1);
    if (password_copy == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    password_copy_length = 0;
    for (i = 0; i < password_length; i++) {
        char c = CHARACTERS[rand() % strlen(CHARACTERS)];
        while (strchr(user_password, c)!= NULL) {
            c = CHARACTERS[rand() % strlen(CHARACTERS)];
        }
        password_copy[password_copy_length++] = c;
    }
    password_copy[password_copy_length] = '\0';

    printf("Your new password is: %s\n", password_copy);

    free(password_copy);
    return 0;
}