//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players and the maximum password length.
#define MAX_PLAYERS 4
#define MAX_PASSWORD_LENGTH 20

// Define the structure of a player.
typedef struct {
    char name[20];
    char password[20];
    int score;
} Player;

// Define the function to check the strength of a password.
int checkPasswordStrength(char *password) {
    int score = 0;

    // Check the length of the password.
    if (strlen(password) < 8) {
        score += 1;
    } else if (strlen(password) < 12) {
        score += 2;
    } else if (strlen(password) < 16) {
        score += 3;
    } else {
        score += 4;
    }

    // Check for uppercase letters.
    int hasUppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }
    if (!hasUppercase) {
        score += 1;
    }

    // Check for lowercase letters.
    int hasLowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }
    if (!hasLowercase) {
        score += 1;
    }

    // Check for digits.
    int hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }
    if (!hasDigit) {
        score += 1;
    }

    // Check for special characters.
    int hasSpecialCharacter = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            hasSpecialCharacter = 1;
            break;
        }
    }
    if (!hasSpecialCharacter) {
        score += 1;
    }

    // Return the score.
    return score;
}

// Define the function to play the game.
void playGame() {
    // Create an array of players.
    Player players[MAX_PLAYERS];

    // Get the names and passwords of the players.
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter your name: ");
        scanf("%s", players[i].name);
        printf("Enter your password: ");
        scanf("%s", players[i].password);
    }

    // Check the strength of the passwords.
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].score = checkPasswordStrength(players[i].password);
    }

    // Find the player with the strongest password.
    int strongestPasswordScore = -1;
    int strongestPasswordPlayer = -1;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].score > strongestPasswordScore) {
            strongestPasswordScore = players[i].score;
            strongestPasswordPlayer = i;
        }
    }

    // Print the results.
    printf("The winner is %s with a password strength of %d.\n", players[strongestPasswordPlayer].name, players[strongestPasswordPlayer].score);
}

// Define the main function.
int main() {
    // Play the game.
    playGame();

    return 0;
}