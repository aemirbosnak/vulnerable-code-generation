//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, result;
    char magic_word[10];

    // Part 1: Guess the Magic Number
    printf("Welcome to the Magic Math Puzzle!\n");
    printf("I am thinking of a number between 1 and 100... can you guess it?\n");
    printf("You have 5 guesses...\n");

    for (int i = 0; i < 5; i++) {
        printf("Guess #%d: ", i + 1);
        scanf("%d", &num1);

        if (num1 == MAGIC_NUMBER) {
            printf("Congratulations! You guessed the magic number in %d attempts!\n", i + 1);
            break;
        }

        if (num1 < MAGIC_NUMBER) {
            printf("Too low! The magic number is higher than %d...\n", num1);
        } else {
            printf("Too high! The magic number is lower than %d...\n", num1);
        }
    }

    // Part 2: Crack the Magic Word
    printf("Now that you know the magic number, can you crack the magic word?\n");
    printf("The magic word is a 10-letter string of letters and numbers... can you guess it?\n");

    for (int i = 0; i < 10; i++) {
        magic_word[i] = '?';
    }

    for (int i = 0; i < 5; i++) {
        printf("Guess a letter or number for position %d of the magic word: ", i + 1);
        scanf(" %c", &magic_word[i]);

        if (magic_word[i] == '?') {
            printf("You guessed a ?... that's not very helpful!\n");
        } else {
            printf("Great guess! The magic word now looks like: %s...\n", magic_word);
        }
    }

    // Part 3: Solve the Final Puzzle
    printf("Now that you know the magic number and the magic word, can you solve the final puzzle?\n");
    printf("I have a secret equation that needs to be solved... can you figure it out?\n");

    result = 0;

    for (int i = 0; i < 5; i++) {
        printf("Guess a number between 1 and 100...\n");
        scanf("%d", &num2);

        result = (num1 * num2) + result;

        if (result == MAGIC_NUMBER) {
            printf("Congratulations! You solved the final puzzle and cracked the magic code!\n");
            break;
        }

        if (result < MAGIC_NUMBER) {
            printf("Too low! The secret equation needs a bigger number...\n");
        } else {
            printf("Too high! The secret equation needs a smaller number...\n");
        }
    }

    return 0;
}