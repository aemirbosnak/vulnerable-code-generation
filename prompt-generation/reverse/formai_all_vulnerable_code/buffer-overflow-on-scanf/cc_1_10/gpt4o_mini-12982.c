//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

void surpriseMessage() {
    const char *messages[] = {
        "Wow! Prepare to be amazed!",
        "Surprise! Your password is about to be generated!",
        "Hold on tight! A magical password is coming your way!",
        "Get ready for the unexpected!",
        "Buckle up! Your secure password is on its way!"
    };
    int randomIndex = rand() % (sizeof(messages) / sizeof(messages[0]));
    printf("%s\n", messages[randomIndex]);
}

char generateRandomCharacter(int includeSpecial) {
    char characterSet[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char specialCharacters[17] = "!@#$%^&*()-_=+[]{};:,.<>?/~";

    if (includeSpecial && rand() % 2) { // Randomly decide to include a special character
        return specialCharacters[rand() % strlen(specialCharacters)];
    } else {
        return characterSet[rand() % strlen(characterSet)];
    }
}

void generatePassword(int length, int includeSpecial) {
    char password[MAX_PASSWORD_LENGTH + 1];
    password[length] = '\0'; // Null-terminate the string

    // Ensure that the password has at least one special character if requested
    int hasSpecialCharacter = 0;
    for (int i = 0; i < length; i++) {
        password[i] = generateRandomCharacter(includeSpecial);
        if (strchr("!@#$%^&*()-_=+[]{};:,.<>?/~", password[i]) != NULL) {
            hasSpecialCharacter = 1;
        }
    }

    // If we require special characters but didn't include any, enforce it
    if (includeSpecial && !hasSpecialCharacter) {
        password[rand() % length] = generateRandomCharacter(1); // Replace random character with a special one
    }

    printf("Your generated password is: %s\n", password);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    surpriseMessage();

    int length;
    printf("Enter desired password length (%d to %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
    
    while (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Please enter a valid length between %d and %d: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &length);
    }

    char choice;
    printf("Do you want to include special characters? (y/n): ");
    scanf(" %c", &choice);
    
    int includeSpecial = (choice == 'y' || choice == 'Y') ? 1 : 0;

    printf("Hold your breath as we craft your password...\n");
    sleep(1); // Pause for dramatic effect
    generatePassword(length, includeSpecial);

    return 0;
}