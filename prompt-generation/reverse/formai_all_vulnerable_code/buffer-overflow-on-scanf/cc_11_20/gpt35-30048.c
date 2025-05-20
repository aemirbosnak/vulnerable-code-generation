//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: futuristic
#include<stdio.h>
#include<string.h>

// Function to check password strength
int check_password_strength(char password[]) {
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digit = 0, special_char = 0;

    // Loop through the characters to check for various criteria
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z')
            uppercase++;

        else if (password[i] >= 'a' && password[i] <= 'z')
            lowercase++;

        else if (password[i] >= '0' && password[i] <= '9')
            digit++;

        else
            special_char++;
    }

    // Check the strength of the password based on the length and criteria met
    if (length < 8 || uppercase == 0 || lowercase == 0 || digit == 0 || special_char == 0)
        return 0;

    else if (length >= 8 && length <= 12 && uppercase >= 1 && lowercase >= 1 && digit >= 1 && special_char >= 1)
        return 1;

    else if (length > 12 && length <= 20 && uppercase >= 2 && lowercase >= 2 && digit >= 2 && special_char >= 2)
        return 2;

    else if (length > 20 && uppercase >= 3 && lowercase >= 3 && digit >= 3 && special_char >= 3)
        return 3;
    
    else
        return -1;
}

int main() {
    char password[100];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    // Display the strength of the password to the user
    switch (strength) {
        case 0:
            printf("Your password is weak. Please try again!\n");
            break;
        case 1:
            printf("Your password is moderately strong. Good job!\n");
            break;
        case 2:
            printf("Your password is strong. Keep it up!\n");
            break;
        case 3:
            printf("Your password is extremely strong. Excellent!\n");
            break;
        default:
            printf("Invalid password! Please enter a valid password.\n");
            break;
    }

    return 0;
}