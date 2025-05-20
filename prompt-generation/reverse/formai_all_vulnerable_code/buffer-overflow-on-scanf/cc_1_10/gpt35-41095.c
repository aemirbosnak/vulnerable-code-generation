//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 15

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"programming", "language", "computer",
                    "science", "software", "engineering", "algorithm", "data", "structure",
                    "memory", "input", "output", "system", "network", "database", "security",
                    "encryption", "decryption", "binary", "machine"};

    int i, j, k, l, n, len, score = 0;
    time_t t;
    char answer[MAX_WORD_LENGTH];

    srand((unsigned) time(&t)); // seed for random number generator

    printf("**************************\n");
    printf("* Typing Speed Test Game *\n");
    printf("**************************\n\n");

    printf("In this game, you will be presented with a series of words.\n");
    printf("Type each word as it appears on the screen.\n");
    printf("You will receive one point for each word you type correctly.\n");
    printf("The game will continue until you type an incorrect word.\n\n");

    printf("Are you ready to start? (y/n): ");

    char response;
    scanf("%c", &response);

    if(response == 'y') {
        for(i = 0; i < MAX_WORDS; i++) {
            n = rand() % MAX_WORDS; // random number between 0 and MAX_WORDS
            len = strlen(words[n]);

            // Display the word
            for(j = 0; j < len; j++) {
                printf("%c", words[n][j]);
            }
            printf("\n");

            // Get the user's answer and check if it is correct
            scanf("%s", answer);
            if(strcmp(answer, words[n]) == 0) {
                score++;
            } else {
                break;
            }
        }

        // Display the final score
        printf("\nGame over. Your score is %d.\n", score);
    } else {
        printf("Maybe next time!\n");
    }

    return 0;
}