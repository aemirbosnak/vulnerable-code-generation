//FormAI DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 8
#define PLAYER_COUNT 4

void generate_password(char *password) {
    int i;
    for(i=0; i<PASSWORD_LENGTH; i++) {
        password[i] = rand()%94 + 33; // Generate random printable ASCII character
    }
    password[PASSWORD_LENGTH] = '\0'; // Add null character to end of string
}

int main() {
    char passwords[PLAYER_COUNT][PASSWORD_LENGTH+1];
    int i, j;
    
    // Generate passwords for each player
    for(i=0; i<PLAYER_COUNT; i++) {
        generate_password(passwords[i]);
    }
    
    // Print players and their passwords
    printf("Passwords:\n");
    for(i=0; i<PLAYER_COUNT; i++) {
        printf("Player %d: %s\n", i+1, passwords[i]);
    }
    
    // Password entry phase
    char guess[PASSWORD_LENGTH+1];
    int correct_guesses[PLAYER_COUNT];
    for(i=0; i<PLAYER_COUNT; i++) {
        printf("\nPlayer %d, enter your guess: ", i+1);
        scanf("%s", guess);
        correct_guesses[i] = (strcmp(guess, passwords[i]) == 0);
    }
    
    // Display results and winner
    int num_correct = 0;
    int winner_index = -1;
    for(i=0; i<PLAYER_COUNT; i++) {
        if(correct_guesses[i]) {
            num_correct++;
            winner_index = i;
        }
    }
    printf("\nResults:\n");
    if(num_correct == 1) {
        printf("Player %d wins!\n", winner_index+1);
    } else {
        printf("No winner.\n");
    }
    
    return 0;
}