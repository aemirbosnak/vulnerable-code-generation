//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For sleep function

#define MAX_ROUNDS 10
#define SEQUENCE_LENGTH 5

void generate_sequence(int sequence[], int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

void display_sequence(int sequence[], int length) {
    printf("Memorize this sequence:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", sequence[i]);
        fflush(stdout); // Ensure the output is displayed immediately
        sleep(1); // Pause for a second to let the player memorize
    }
    printf("\n");
}

int get_user_input(int user_sequence[], int length) {
    printf("Enter the sequence (space-separated):\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &user_sequence[i]);
    }
    return 0;
}

int compare_sequences(int seq1[], int seq2[], int length) {
    for (int i = 0; i < length; i++) {
        if (seq1[i] != seq2[i]) {
            return 0; // Sequences do not match
        }
    }
    return 1; // Sequences match
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int round;
    int sequence[SEQUENCE_LENGTH];
    int user_sequence[SEQUENCE_LENGTH];

    printf("Welcome to the Memory Game!\n");
    printf("You have %d rounds to test your memory!\n", MAX_ROUNDS);

    for (round = 1; round <= MAX_ROUNDS; round++) {
        printf("\nRound %d:\n", round);
        generate_sequence(sequence, round + SEQUENCE_LENGTH - 1); // Increase difficulty
        
        display_sequence(sequence, round + SEQUENCE_LENGTH - 1);

        // Clear the screen for user input (Unix/Linux way)
        printf("\033[H\033[J");

        get_user_input(user_sequence, round + SEQUENCE_LENGTH - 1);

        if (compare_sequences(sequence, user_sequence, round + SEQUENCE_LENGTH - 1)) {
            printf("Correct! Moving to the next round...\n");
        } else {
            printf("Oops! The correct sequence was: ");
            for (int i = 0; i < round + SEQUENCE_LENGTH - 1; i++) {
                printf("%d ", sequence[i]);
            }
            printf("\nGame Over! You reached round %d.\n", round);
            break;
        }
    }

    if (round > MAX_ROUNDS) {
        printf("Congratulations! You've completed all rounds!\n");
    }

    return 0;
}