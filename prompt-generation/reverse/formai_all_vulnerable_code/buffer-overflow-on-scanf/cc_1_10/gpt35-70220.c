//FormAI DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for the password
#define MAX_PASSWORD_LENGTH 20

// Define the maximum number of allowed attempts before the program terminates
#define MAX_LOGIN_ATTEMPTS 3

// Define the default password
const char* DEFAULT_PASSWORD = "password123";

// Define the password variable
char password[MAX_PASSWORD_LENGTH + 1];

// Define the counter for unsuccessful login attempts
int loginAttemptCounter = 0;

// Define function to check if entered password is correct
int isPasswordCorrect() {
    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);
    // Check password
    if (strcmp(password, DEFAULT_PASSWORD) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Define function to turn on the lights
void turnOnLights() {
    printf("Lights turned on!\n");
}

// Define function to turn off the lights
void turnOffLigts() {
    printf("Lights turned off!\n");
}

int main() {
    // Check password
    while(loginAttemptCounter < MAX_LOGIN_ATTEMPTS && !isPasswordCorrect()) {
        printf("Incorrect password! Please try again.\n");
        loginAttemptCounter++;
    }
    
    if (loginAttemptCounter == MAX_LOGIN_ATTEMPTS) {
        printf("Max attempts reached. Terminating program.\n");
        exit(1);
    }
    
    // Password is correct, proceed with program
    printf("Access granted.\n");
    printf("Welcome to Smart Home Light Control!\n");
    
    // Define variable for user input
    char userInput;
    
    // Loop through user input until user quits
    do {
        printf("Enter 'o' to turn on the lights, 'f' to turn off the lights, and 'q' to quit.\n");
        scanf(" %c", &userInput);
        switch(userInput) {
            case 'o':
                turnOnLights();
                break;
            case 'f':
                turnOffLigts();
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (userInput != 'q');
    
    return 0;
}