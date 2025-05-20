//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check if password contains uppercase letters
int contains_uppercase(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// function to check if password contains lowercase letters
int contains_lowercase(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// function to check if password contains numbers
int contains_numbers(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// function to check if password contains special characters
int contains_special(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    
    int strength = 0;
    
    if (strlen(password) >= 8) {
        strength++;
    }
    if (contains_uppercase(password)) {
        strength++;
    }
    if (contains_lowercase(password)) {
        strength++;
    }
    if (contains_numbers(password)) {
        strength++;
    }
    if (contains_special(password)) {
        strength++;
    }
    
    printf("Password strength: %d/5\n", strength);
    
    if (strength == 5) {
        printf("Password is very strong!\n");
    } else if (strength >= 3) {
        printf("Password is strong.\n");
    } else if (strength >= 2) {
        printf("Password is okay.\n");
    } else {
        printf("Password is weak. Please choose a stronger password.\n");
    }
    
    return 0;
}