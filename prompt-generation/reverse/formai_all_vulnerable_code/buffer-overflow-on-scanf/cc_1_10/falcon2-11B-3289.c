//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int guessesLeft = 10;
    char word[10];
    char letter;
    int i;

    strcpy(word, "hello");

    while (guessesLeft > 0) {
        printf("Game Board:\n");
        printf("---------\n");
        for (i = 0; i < strlen(word); i++) {
            if (word[i] == '_') {
                printf("_ ");
            } else {
                printf("%c ", word[i]);
            }
            if (i % 4 == 3) {
                printf("\n");
            }
        }
        printf("\n");

        printf("Guess a letter: ");
        scanf(" %c", &letter);

        if (strstr(word, letter)) {
            printf("Correct!\n");
            for (i = 0; i < strlen(word); i++) {
                if (word[i] == letter) {
                    word[i] = letter;
                }
            }
        } else {
            printf("Incorrect!\n");
            guessesLeft--;
            if (guessesLeft == 0) {
                printf("You lost!\n");
                break;
            }
        }
    }

    printf("Game over!\n");
    printf("Do you want to play again? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    return 0;
}