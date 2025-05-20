//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int has_lowercase(const char *password);
int has_uppercase(const char *password);
int has_digit(const char *password);
int has_specialchar(const char *password);

int main() {
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);
    
    if (strlen(password) < 8) {
        printf("Your password is too short. It must be at least 8 characters.\n");
        return -1;
    }
    
    if (!has_lowercase(password)) {
        printf("Your password must contain at least one lowercase letter.\n");
        return -1;
    }
    
    if (!has_uppercase(password)) {
        printf("Your password must contain at least one uppercase letter.\n");
        return -1;
    }
    
    if (!has_digit(password)) {
        printf("Your password must contain at least one digit.\n");
        return -1;
    }
    
    if (!has_specialchar(password)) {
        printf("Your password must contain at least one special character.\n");
        return -1;
    }
    
    printf("Your password meets the minimum requirements. Good job!\n");
    return 0;
}

// Function to check if password contains lowercase letter
int has_lowercase(const char *password) {
    int i;
    for (i = 0; password[i]; i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if password contains uppercase letter
int has_uppercase(const char *password) {
    int i;
    for (i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if password contains digit
int has_digit(const char *password) {
    int i;
    for (i = 0; password[i]; i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if password contains special character
int has_specialchar(const char *password) {
    int i;
    for (i = 0; password[i]; i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}