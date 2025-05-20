//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int passwordLength, lowercase, uppercase, specialCharacters, numbers;
    char password[50] = "";
    char characterSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-={}[]|:;<>,.?/0123456789";

    printf("Welcome to the Secure Password Generator!\n");

    // Get password length from user
    printf("Enter password length (8-50): ");
    scanf("%d", &passwordLength);

    while (passwordLength < 8 || passwordLength > 50) {
        printf("Invalid length, please enter a value between 8 and 50: ");
        scanf("%d", &passwordLength);
    }

    // Ask user for password requirements
    printf("Include lowercase letters? (1 = yes, 0 = no) ");
    scanf("%d", &lowercase);

    printf("Include uppercase letters? (1 = yes, 0 = no) ");
    scanf("%d", &uppercase);

    printf("Include special characters? (1 = yes, 0 = no) ");
    scanf("%d", &specialCharacters);

    printf("Include numbers? (1 = yes, 0 = no) ");
    scanf("%d", &numbers);

    // Seed random number generator
    srand(time(NULL));

    // Generate password
    for (int i = 0; i < passwordLength; i++) {
        int randomIndex = rand() % 87; // 87 is the length of characterSet
        char randomCharacter = characterSet[randomIndex];

        if (lowercase && randomCharacter >= 'a' && randomCharacter <= 'z') {
            password[i] = randomCharacter;
        } else if (uppercase && randomCharacter >= 'A' && randomCharacter <= 'Z') {
            password[i] = randomCharacter;
        } else if (specialCharacters && (randomCharacter == '!' || randomCharacter == '@' || randomCharacter == '#' || randomCharacter == '$' || randomCharacter == '%' || randomCharacter == '^' || randomCharacter == '&' || randomCharacter == '*' || randomCharacter == '(' || randomCharacter == ')' || randomCharacter == '_' || randomCharacter == '+' || randomCharacter == '-' || randomCharacter == '=' || randomCharacter == '{' || randomCharacter == '}' || randomCharacter == '[' || randomCharacter == ']' || randomCharacter == '|' || randomCharacter == ';' || randomCharacter == ':' || randomCharacter == '<' || randomCharacter == '>' || randomCharacter == ',' || randomCharacter == '.' || randomCharacter == '?')) {
            password[i] = randomCharacter;
        } else if (numbers && randomCharacter >= '0' && randomCharacter <= '9') {
            password[i] = randomCharacter;
        } else {
            i--; // try again
        }
    }

    // Print password to user
    printf("Your secure password is: %s\n", password);

    return 0;
}