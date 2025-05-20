//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define CLEAR_SCREEN() printf("\033[H\033[J") // macro to clear the terminal screen

// main function
int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    int level = 1; // starting level
    int score = 0; // current score
    int health = 100; // starting health
    
    CLEAR_SCREEN(); // clear the screen
    
    printf("Welcome to Hacker's Quest!\n");
    sleep(1); // pause for a moment
    
    while (health > 0 && level <= 10) { // main game loop, continue until the player runs out of health or reaches the final level
        CLEAR_SCREEN();
        
        printf("Level %d\n", level);
        printf("Score: %d\n", score);
        printf("Health: %d\n", health);
        printf("--------------------\n");
        printf("Enter your password: ");
        
        char password[10]; // input buffer
        scanf("%s", password);
        
        int difficulty = rand() % 3 + 1; // generate a random difficulty level
        
        int correct = 0; // flag to indicate if the password was correct
        
        switch (difficulty) {
            case 1: // easy level
                if (strcmp(password, "password1") == 0) {
                    printf("Access granted!\n");
                    correct = 1;
                } else {
                    printf("Access denied.\n");
                }
                break;
            case 2: // medium level
                if (strcmp(password, "password2") == 0) {
                    printf("Access granted!\n");
                    correct = 1;
                } else {
                    printf("Access denied.\n");
                }
                break;
            case 3: // hard level
                if (strcmp(password, "password3") == 0) {
                    printf("Access granted!\n");
                    correct = 1;
                } else {
                    printf("Access denied.\n");
                }
                break;
        }
        
        if (correct) { // if the password was correct, increase the score and level
            score += difficulty * 100;
            level++;
        } else { // otherwise, decrease the player's health
            health -= difficulty * 25;
        }
        
        sleep(1); // pause for a moment
    }
    
    CLEAR_SCREEN();
    printf("Game over!\n");
    printf("Your final score: %d\n", score);
    
    if (health <= 0) {
        printf("You ran out of health.\n");
    } else {
        printf("You completed all levels!\n");
    }
    
    return 0;
}