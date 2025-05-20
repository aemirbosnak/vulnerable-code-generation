//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */

int check_length(char *password);
int check_upper_case(char *password);
int check_lower_case(char *password);
int check_digit(char *password);
int check_special_char(char *password);

int main()
{
    // Declare variables
    char password[50];
    int length_ok, upper_case_ok, lower_case_ok, digit_ok, special_char_ok, strength_score;

    // Read in password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    length_ok = check_length(password);
    upper_case_ok = check_upper_case(password);
    lower_case_ok = check_lower_case(password);
    digit_ok = check_digit(password);
    special_char_ok = check_special_char(password);

    // Calculate strength score
    strength_score = length_ok + upper_case_ok + lower_case_ok + digit_ok + special_char_ok;

    // Print results
    if (strength_score == 5) {
        printf("Password is very strong.\n");
    } else if (strength_score >= 3) {
        printf("Password is strong.\n");
    } else if (strength_score >= 2) {
        printf("Password is moderately strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

/* Function to check if password length is at least 8 characters */
int check_length(char *password)
{
    if (strlen(password) >= 8) {
        printf("Password length OK.\n");
        return 1;
    } else {
        printf("Password length must be at least 8 characters.\n");
        return 0;
    }
}

/* Function to check if password contains at least one uppercase letter */
int check_upper_case(char *password)
{
    int i;
    int len = strlen(password);
    for (i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            printf("Password contains uppercase letter.\n");
            return 1;
        }
    }
    printf("Password must contain at least one uppercase letter.\n");
    return 0;
}

/* Function to check if password contains at least one lowercase letter */
int check_lower_case(char *password)
{
    int i;
    int len = strlen(password);
    for (i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            printf("Password contains lowercase letter.\n");
            return 1;
        }
    }
    printf("Password must contain at least one lowercase letter.\n");
    return 0;
}

/* Function to check if password contains at least one digit */
int check_digit(char *password)
{
    int i;
    int len = strlen(password);
    for (i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            printf("Password contains digit.\n");
            return 1;
        }
    }
    printf("Password must contain at least one digit.\n");
    return 0;
}

/* Function to check if password contains at least one special character */
int check_special_char(char *password)
{
    int i;
    int len = strlen(password);
    for (i = 0; i < len; i++) {
        if (!(password[i] >= 'A' && password[i] <= 'Z') && !(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= '0' && password[i] <= '9')) {
            printf("Password contains special character.\n");
            return 1;
        }
    }
    printf("Password must contain at least one special character.\n");
    return 0;
}