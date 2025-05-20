//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// Constants for the game
#define MAX_SEQUENCE_LENGTH 100
#define COLOR_COUNT 4
#define MAX_ROUNDS 5

const char* colors[COLOR_COUNT] = {"Red", "Green", "Blue", "Yellow"};
char sequence[MAX_SEQUENCE_LENGTH];
int playerInput[MAX_SEQUENCE_LENGTH];

// Function to generate a random color sequence
void generateSequence(int round) {
    for (int i = 0; i < round; i++) {
        sequence[i] = rand() % COLOR_COUNT;
    }
}

// Function to display the sequence
void displaySequence(int round) {
    printf("Remember this sequence:\n");
    for (int i = 0; i < round; i++) {
        printf("%s ", colors[sequence[i]]);
        fflush(stdout); // Ensure immediate output
        sleep(1); // Pause for a second
    }
    printf("\n");
    sleep(1); // Pause before next input
}

// Function to get player input
void getPlayerInput(int round) {
    printf("Enter the sequence (numbers 0-3 for Red, Green, Blue, Yellow):\n");
    for (int i = 0; i < round; i++) {
        scanf("%d", &playerInput[i]);
    }
}

// Function to check the player's input against the sequence
int checkInput(int round) {
    for (int i = 0; i < round; i++) {
        if (playerInput[i] != sequence[i]) {
            return 0; // Wrong input
        }
    }
    return 1; // Correct input
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int score = 0;

    printf("Welcome to the Color Memory Game!\n");
    printf("You will need to remember a sequence of colors.\n");
    printf("Enter the number corresponding to each color:\n");
    printf("0: Red, 1: Green, 2: Blue, 3: Yellow\n");

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        generateSequence(round);
        displaySequence(round);
        getPlayerInput(round);

        if (checkInput(round)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct sequence was:\n");
            for (int i = 0; i < round; i++) {
                printf("%s ", colors[sequence[i]]);
            }
            printf("\n");
            break; // End game on first wrong input
        }
    }

    printf("Game Over! Your score: %d out of %d\n", score, MAX_ROUNDS);
    return 0;
}