//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_NUMERIC_DIGITS 1
#define MIN_UPPERCASE_LETTERS 1
#define MIN_LOWERCASE_LETTERS 1
#define MIN_SPECIAL_CHARACTERS 1

typedef struct {
    char *password;
    int length;
    int has_uppercase;
    int has_lowercase;
    int has_numeric;
    int has_special;
} Password;

void generate_password(Password *password) {
    char charset[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int charset_length = strlen(charset);

    password->password = malloc(MAX_PASSWORD_LENGTH + 1);
    password->length = rand() % MAX_PASSWORD_LENGTH + MIN_PASSWORD_LENGTH;

    for (int i = 0; i < password->length; i++) {
        int random_index = rand() % charset_length;
        password->password[i] = charset[random_index];
    }

    password->password[password->length] = '\0';
}

int main() {
    srand(time(NULL));

    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);

    Password pwd;
    generate_password(&pwd);

    printf("\nYour password strength:\n");
    printf("Length: %d\n", length);
    printf("Has Uppercase: %s\n", (pwd.has_uppercase)? "Yes" : "No");
    printf("Has Lowercase: %s\n", (pwd.has_lowercase)? "Yes" : "No");
    printf("Has Numeric: %s\n", (pwd.has_numeric)? "Yes" : "No");
    printf("Has Special: %s\n", (pwd.has_special)? "Yes" : "No");

    return 0;
}