//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear screen
void clearScreen() {
    system("clear"); // for linux and mac
    //system("cls"); // for windows
}

// Function to generate random number
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random generator
    srand(time(NULL));

    // Define the shape-shifting characters
    char characters[] = {'#', '$', '%', '&', '*', '+', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~'};

    // Define the game variables
    int score = 0;
    int level = 1;
    int lives = 3;
    int target = 5;
    int duration = 1000;

    // Start the game loop
    while(1) {
        // Clear the screen
        clearScreen();

        // Print the game information
        printf("Shape-Shifting Game\n");
        printf("===================\n");
        printf("Level: %d\n", level);
        printf("Score: %d\n", score);
        printf("Lives: %d\n", lives);

        // Print the target character
        char targetChar = characters[randomNumber(0, sizeof(characters) - 1)];
        printf("Target: %c\n", targetChar);

        // Print the player prompt
        printf("Enter the character: ");

        // Get the player input
        char playerInput;
        scanf("%c", &playerInput);
        fflush(stdin);

        // Check if the player's input matches the target character
        if(playerInput == targetChar) {
            printf("Correct!\n");
            score++;

            // Check if the player has reached the target score
            if(score >= target) {
                printf("Level up!\n");
                level++;
                score = 0;
                target++;
                lives++;
                duration -= 50; // Decrease the duration by 50 milliseconds for added difficulty
            }
        }
        else {
            printf("Wrong!\n");
            lives--;

            // Check if the player has run out of lives
            if(lives <= 0) {
                printf("Game over!\n");
                break;
            }
        }

        // Delay for the next target
        printf("Next target in %d milliseconds...\n", duration);
        usleep(duration * 1000);
    }

    return 0;
}