//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function declarations
int generateRandomNumber(int min, int max);
void shuffleArray(char arr[], int n);
char* generateSecurePassword(int length);

// Main function
int main() {
    int length;
    char* password;

    // Set the length of the password
    printf("Enter the length of the password (minimum 8 characters): ");
    scanf("%d", &length);
    while (length < 8) {
        printf("Password length must be at least 8 characters. Please try again.\n");
        printf("Enter the length of the password (minimum 8 characters): ");
        scanf("%d", &length);
    }

    // Generate the password
    password = generateSecurePassword(length);

    // Print the password
    printf("Your new password is: %s\n", password);

    // Free the password memory
    free(password);

    return 0;
}

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    static int flag = 0;
    if (flag == 0) {
        srand(time(NULL));
        flag = 1;
    }
    return (rand() % (max - min + 1)) + min;
}

// Function to shuffle an array
void shuffleArray(char arr[], int n) {
    int i, j;
    char temp;
    for (i = n - 1; i > 0; i--) {
        j = generateRandomNumber(0, i);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to generate a secure password of the given length
char* generateSecurePassword(int length) {
    char* password = (char*) malloc(sizeof(char) * length + 1);
    int i, j;
    char symbols[32] = {
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=',
        '[', ']', '{', '}', '|', '\\', ';', ':', '\'', '\"', ',', '.', '<', '>', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    // Shuffle the symbols array for randomness
    shuffleArray(symbols, 32);

    // Generate the password
    for (i = 0; i < length; i++) {
        j = generateRandomNumber(0, 31);
        password[i] = symbols[j];
    }
    password[length] = '\0';

    // Check if the password is secure enough
    int has_digit = 0, has_lower = 0, has_upper = 0, has_symbol = 0;
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) has_digit = 1;
        if (islower(password[i])) has_lower = 1;
        if (isupper(password[i])) has_upper = 1;
        if (!isdigit(password[i]) && !islower(password[i]) && !isupper(password[i])) has_symbol = 1;
    }

    // If the password does not meet the security requirements, regenerate the password
    if (!(has_digit && has_lower && has_upper && has_symbol)) {
        free(password);
        password = generateSecurePassword(length);
    }

    return password;
}