//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 30    // Maximum length of password
#define MIN_LENGTH 8     // Minimum length of password
#define TRUE 1
#define FALSE 0

// Function to generate a secure password
void generatePassword(char password[], int length) {

    // Characters to use in password
    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 
                         'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
                         'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                         'x', 'y', '+', '-'};

    // Select a random seed for the generator - based on current time
    srand((unsigned)time(NULL));

    // Generate a random password
    int i;
    for (i = 0; i < length; i++) {
        int random_index = rand() % 54; // 54 is the length of the characters array
        password[i] = characters[random_index];
    }
    password[length] = '\0';
}

// Function to check if a password is secure
int isSecurePassword(char password[]) {

    int i;
    int length = strlen(password);
    int uppercase = FALSE, lowercase = FALSE, number = FALSE, special = FALSE;

    // Check if the password contains at least one uppercase letter
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase = TRUE;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter
    for (i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase = TRUE;
            break;
        }
    }

    // Check if the password contains at least one number
    for (i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            number = TRUE;
            break;
        }
    }

    // Check if the password contains at least one special character
    for (i = 0; i < length; i++) {
        if (password[i] == '+' || password[i] == '-') {
            special = TRUE;
            break;
        }
    }

    // Check if the password is at least 8 characters long and contains all necessary characters
    if (length >= 8 && uppercase == TRUE && lowercase == TRUE && number == TRUE && special == TRUE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int main() {

    char password[MAX_LENGTH + 1];
    int length = 0, secure = FALSE;

    // Generate a secure password
    while (secure == FALSE) {
        printf("Enter the desired length of the password (8-30): ");
        scanf("%d", &length);

        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Password length must be between 8 and 30 characters.\n");
        }
        else {
            generatePassword(password, length);
            secure = isSecurePassword(password);

            if (secure) {
                printf("\nYour new password is: %s", password);
            }
            else {
                printf("Your new password is not secure. Please try again.\n");
            }
        }
    }

    return 0;
}