//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    // Check if password contains uppercase letter
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check if password contains lowercase letter
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check if password contains number
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check if password contains special character
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special = 1;
            break;
        }
    }

    // Determine password strength based on criteria
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (has_uppercase) {
        strength++;
    }
    if (has_lowercase) {
        strength++;
    }
    if (has_number) {
        strength++;
    }
    if (has_special) {
        strength++;
    }

    return strength;
}

int main() {
    char password[100];

    // Post-apocalyptic style message
    printf("In the wasteland of the post-apocalyptic world, \n");
    printf("the only thing that stands between you and certain death \n");
    printf("is the strength of your password. \n");
    printf("Enter your password to test its strength: ");

    // Read in password from user
    scanf("%s", password);

    // Check password strength and display result
    int strength = check_password_strength(password);
    if (strength == 0) {
        printf("Weak password. You're as good as dead. \n");
    } else if (strength == 1) {
        printf("Fair password. You might survive a day or two. \n");
    } else if (strength == 2) {
        printf("Good password. You have a fighting chance. \n");
    } else if (strength == 3) {
        printf("Strong password. You might just make it out alive. \n");
    } else if (strength == 4) {
        printf("Uncrackable password. You're a true survivor. \n");
    }

    return 0;
}