//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_PASSWORD_LENGTH 32

/* Function to generate a random password */
char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        printf("Error: Could not allocate memory for password\n");
        exit(1);
    }
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
    return password;
}

/* Function to check if a string is a valid password */
int is_valid_password(char *password) {
    int length = strlen(password);
    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        if (strchr(charset, password[i]) == NULL) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char *password;
    int length;
    printf("Enter password length (between 8 and %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
    while (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Please enter a value between 8 and %d: ", MAX_PASSWORD_LENGTH);
        scanf("%d", &length);
    }
    password = generate_password(length);
    printf("Generated password: %s\n", password);
    if (is_valid_password(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }
    free(password);
    return 0;
}