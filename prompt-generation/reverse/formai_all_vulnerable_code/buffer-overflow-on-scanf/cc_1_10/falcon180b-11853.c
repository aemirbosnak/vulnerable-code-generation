//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void generatePassword(char* password, int length);
int isPasswordValid(char* password);

int main() {
    char password[100];
    int length;

    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Check if the password length is valid
    if (length < 8 || length > 32) {
        printf("Invalid password length. Please enter a length between 8 and 32.\n");
        return 1;
    }

    // Generate the password
    generatePassword(password, length);

    // Print the generated password
    printf("Your secure password is: %s\n", password);

    return 0;
}

// Generates a random password of a given length
void generatePassword(char* password, int length) {
    const char alphanumeric[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const char specialChars[] = "!@#$%^&*()_+~`|}{[]\:;?><,./-=";

    // Initialize the password with random characters
    for (int i = 0; i < length; i++) {
        password[i] = alphanumeric[rand() % (sizeof(alphanumeric) - 1)];
    }

    // Add some special characters to the password
    int numSpecialChars = rand() % 4 + 2;
    for (int i = 0; i < numSpecialChars; i++) {
        int index = rand() % (sizeof(specialChars) - 1);
        password[rand() % length] = specialChars[index];
    }
}

// Checks if the given password is valid
int isPasswordValid(char* password) {
    // Check if the password contains at least one uppercase letter, one lowercase letter, one number, and one special character
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isdigit(password[i])) {
            hasNumber = 1;
        } else if (strchr("!@#$%^&*()_+~`|}{[]\:;?><,./-=", password[i])!= NULL) {
            hasSpecialChar = 1;
        }
    }

    return (hasUppercase && hasLowercase && hasNumber && hasSpecialChar);
}