//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * This C program generates a secure password based on user specifications.
 * It is designed to have a minimum length of 12 characters and use a combination
 * of upper and lowercase letters, numbers, and special characters based on the user's choice.
 */

int main()
{
    int length, choice, i, randomIndex;
    char characters[81];
    char password[21] = "";
    const char* upperCaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* lowerCaseLetters = "abcdefghijklmnopqrstuvwxyz";
    const char* numbers = "0123456789";
    const char* specialCharacters = "!@#$%^&*()_-=+[]{};:,.<>?";

    // Seed the random number generator with the current time
    srand(time(NULL));

    printf("\nWelcome to the Secure Password Generator!\n\n");

    // Get the desired password length from the user
    do {
        printf("Enter the desired length of your password (minimum 12): ");
        scanf("%d", &length);
    } while (length < 12);

    // Choose which characters to include in the password
    printf("\nWhich characters would you like to include in your password?\n");
    printf("1. Upper and lowercase letters\n");
    printf("2. Numbers\n");
    printf("3. Special characters\n");
    printf("4. Upper and lowercase letters and numbers\n");
    printf("5. Upper and lowercase letters and special characters\n");
    printf("6. Numbers and special characters\n");
    printf("7. All of the above\n\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);

    // Build the list of characters to choose from based on the user's choice
    switch (choice) {
        case 1:
            strcpy(characters, upperCaseLetters);
            strcat(characters, lowerCaseLetters);
            break;
        case 2:
            strcpy(characters, numbers);
            break;
        case 3:
            strcpy(characters, specialCharacters);
            break;
        case 4:
            strcpy(characters, upperCaseLetters);
            strcat(characters, lowerCaseLetters);
            strcat(characters, numbers);
            break;
        case 5:
            strcpy(characters, upperCaseLetters);
            strcat(characters, lowerCaseLetters);
            strcat(characters, specialCharacters);
            break;
        case 6:
            strcpy(characters, numbers);
            strcat(characters, specialCharacters);
            break;
        case 7:
            strcpy(characters, upperCaseLetters);
            strcat(characters, lowerCaseLetters);
            strcat(characters, numbers);
            strcat(characters, specialCharacters);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            exit(1);
    }

    // Generate the secure password one character at a time
    for (i = 0; i < length; i++) {
        randomIndex = rand() % strlen(characters);
        password[i] = characters[randomIndex];
    }

    // Print the final password
    printf("\nYour secure password is: %s\n\n", password);

    // Exit the program
    return 0;
}