//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to calculate the strength of the password
int passwordStrength(char *password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int specialChars = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            specialChars = 1;
            break;
        }
    }

    // Calculate the score based on the strength of the password
    int score = 0;
    if (uppercase) score++;
    if (lowercase) score++;
    if (numbers) score++;
    if (specialChars) score++;

    // Return the strength of the password
    if (score <= 1) return 1;
    else if (score <= 2) return 2;
    else if (score <= 3) return 3;
    else return 4;
}

int main() {
    char password[100];

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Calculate the strength of the password
    int strength = passwordStrength(password);

    // Print the strength of the password
    if (strength == 1) printf("Weak\n");
    else if (strength == 2) printf("Fair\n");
    else if (strength == 3) printf("Good\n");
    else printf("Strong\n");

    return 0;
}