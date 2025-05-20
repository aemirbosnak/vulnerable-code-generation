//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player struct
typedef struct {
    char name[20];
    int score;
} player;

// Define the password struct
typedef struct {
    char password[20];
    int strength;
} password;

// Function to check the strength of a password
int check_password_strength(char *password) {
    int strength = 0;

    // Check for length
    if (strlen(password) >= 8) {
        strength++;
    }

    // Check for uppercase characters
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
            break;
        }
    }

    // Check for lowercase characters
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength++;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            strength++;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            strength++;
            break;
        }
    }

    return strength;
}

// Function to play the game
void play_game() {
    // Initialize the players
    player players[2];

    // Get the players' names
    printf("Player 1, enter your name: ");
    scanf("%s", players[0].name);
    printf("Player 2, enter your name: ");
    scanf("%s", players[1].name);

    // Initialize the passwords
    password passwords[2];

    // Get the players' passwords
    printf("Player 1, enter your password: ");
    scanf("%s", passwords[0].password);
    printf("Player 2, enter your password: ");
    scanf("%s", passwords[1].password);

    // Check the strength of the passwords
    int strength1 = check_password_strength(passwords[0].password);
    int strength2 = check_password_strength(passwords[1].password);

    // Print the results
    printf("Player 1, your password strength is: %d\n", strength1);
    printf("Player 2, your password strength is: %d\n", strength2);

    // Determine the winner
    if (strength1 > strength2) {
        printf("Player 1 wins!\n");
    } else if (strength2 > strength1) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

// Main function
int main() {
    // Play the game
    play_game();

    return 0;
}