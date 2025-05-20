//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to check if the password contains at least one uppercase letter
int contains_uppercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one lowercase letter
int contains_lowercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one digit
int contains_digit(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one special character
int contains_special_char(char *password) {
    int i;
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (i = 0; i < strlen(password); i++) {
        int j;
        for (j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check the strength of the password
int check_password_strength(char *password) {
    int strength = 0;
    if (contains_uppercase(password)) {
        strength++;
    }
    if (contains_lowercase(password)) {
        strength++;
    }
    if (contains_digit(password)) {
        strength++;
    }
    if (contains_special_char(password)) {
        strength++;
    }
    if (strength == 0) {
        printf("Weak\n");
    } else if (strength == 1) {
        printf("Average\n");
    } else if (strength == 2) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }
}

int main() {
    char password[100];
    printf("Enter the password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}