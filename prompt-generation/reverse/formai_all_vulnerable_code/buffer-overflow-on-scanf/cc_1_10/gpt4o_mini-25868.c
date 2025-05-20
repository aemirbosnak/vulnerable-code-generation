//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SEQ_LENGTH 100
#define CLEAR_SCREEN "clear" // Use "cls" for Windows

void clear() {
    system(CLEAR_SCREEN);
}

void generateSequence(int sequence[], int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 10; // Random number between 0-9
    }
}

void displaySequence(int sequence[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", sequence[i]);
        fflush(stdout); // Make sure to output immediately
        usleep(1000000); // Display each number for 1 second
        clear();
    }
}

int getUserInput(int userInput[], int length) {
    printf("Enter the sequence (space-separated): ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &userInput[i]);
    }
    return 0;
}

int checkSequence(int sequence[], int userInput[], int length) {
    for (int i = 0; i < length; i++) {
        if (sequence[i] != userInput[i]) {
            return 0; // Sequence is incorrect
        }
    }
    return 1; // Sequence is correct
}

int main() {
    int sequence[MAX_SEQ_LENGTH] = {0};
    int userInput[MAX_SEQ_LENGTH] = {0};
    int length = 1; // Starting length of sequence
    int score = 0;

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Memory Game!\n");
    sleep(2); // Brief pause for effect

    while (length <= MAX_SEQ_LENGTH) {
        clear();
        printf("Round %d:\n", (score + 1));
        
        generateSequence(sequence, length);
        
        displaySequence(sequence, length);

        getUserInput(userInput, length);
        
        if (checkSequence(sequence, userInput, length)) {
            printf("Correct! Well done!\n");
            score++;
            length++; // Increase difficulty by increasing the sequence length
        } else {
            printf("Incorrect! Game Over! Your score is %d\n", score);
            break;
        }

        sleep(2); // Pause before the next round
    }

    if (length > MAX_SEQ_LENGTH) {
        printf("Congratulations! You've mastered the game with a perfect score of %d!\n", score);
    }

    return 0;
}