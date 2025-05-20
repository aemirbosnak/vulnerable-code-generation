//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define MIN_UPPER_CASE_CHAR 'A'
#define MAX_UPPER_CASE_CHAR 'Z'
#define MIN_LOWER_CASE_CHAR 'a'
#define MAX_LOWER_CASE_CHAR 'z'
#define MIN_NUMBER_CHAR '0'
#define MAX_NUMBER_CHAR '9'
#define MIN_SPECIAL_CHAR '!'
#define MAX_SPECIAL_CHAR '@'

// Define function prototypes
int generateRandomNumber(int min, int max);
int isValidPassword(char* password);

// Main function
int main() {
    // Generate random password
    char password[MAX_LENGTH];
    int length = generateRandomNumber(MIN_LENGTH, MAX_LENGTH);
    for (int i = 0; i < length; i++) {
        char randomChar = (char)generateRandomNumber(MIN_UPPER_CASE_CHAR, MAX_UPPER_CASE_CHAR);
        if (randomChar >= MIN_LOWER_CASE_CHAR && randomChar <= MAX_LOWER_CASE_CHAR) {
            randomChar += 32;
        }
        password[i] = randomChar;
    }
    password[length] = '\0';

    // Print generated password
    printf("Generated password: %s\n", password);

    // Check if password is valid
    if (isValidPassword(password)) {
        printf("Password is valid!\n");
    } else {
        printf("Password is not valid!\n");
    }

    return 0;
}

// Function to generate random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if password is valid
int isValidPassword(char* password) {
    int upperCaseCount = 0;
    int lowerCaseCount = 0;
    int numberCount = 0;
    int specialCharCount = 0;
    int length = strlen(password);

    // Check for at least one upper case character
    for (int i = 0; i < length; i++) {
        if (password[i] >= MIN_UPPER_CASE_CHAR && password[i] <= MAX_UPPER_CASE_CHAR) {
            upperCaseCount++;
        }
    }
    if (upperCaseCount < 1) {
        return 0;
    }

    // Check for at least one lower case character
    for (int i = 0; i < length; i++) {
        if (password[i] >= MIN_LOWER_CASE_CHAR && password[i] <= MAX_LOWER_CASE_CHAR) {
            lowerCaseCount++;
        }
    }
    if (lowerCaseCount < 1) {
        return 0;
    }

    // Check for at least one number character
    for (int i = 0; i < length; i++) {
        if (password[i] >= MIN_NUMBER_CHAR && password[i] <= MAX_NUMBER_CHAR) {
            numberCount++;
        }
    }
    if (numberCount < 1) {
        return 0;
    }

    // Check for at least one special character
    for (int i = 0; i < length; i++) {
        if (password[i] >= MIN_SPECIAL_CHAR && password[i] <= MAX_SPECIAL_CHAR) {
            specialCharCount++;
        }
    }
    if (specialCharCount < 1) {
        return 0;
    }

    // Check for minimum length
    if (length < MIN_LENGTH) {
        return 0;
    }

    // Check for maximum length
    if (length > MAX_LENGTH) {
        return 0;
    }

    return 1;
}