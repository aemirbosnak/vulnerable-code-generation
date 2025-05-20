//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 7

// Function to check if a word is misspelled
int is_misspelled(char *word) {
    int i, j, k;
    char c, d;
    int score = 0;

    // Check each letter of the word
    for (i = 0; i < strlen(word); i++) {
        c = word[i];

        // Check if the letter is uppercase
        if (isupper(c)) {
            // Check if the letter is the correct case of the letter
            for (j = 'A'; j <= 'Z'; j++) {
                if (c == j) {
                    // If the letter is the correct case, add 1 to the score
                    score++;
                    break;
                }
            }
        } else {
            // Check if the letter is the correct case of the letter
            for (j = 'a'; j <= 'z'; j++) {
                if (c == j) {
                    // If the letter is the correct case, add 1 to the score
                    score++;
                    break;
                }
            }
        }

        // Check if the letter is a digraph (two letters in one)
        if (i + 1 < strlen(word) && word[i + 1] == 'e' && word[i] == 'i') {
            score++;
        }

        // Check if the letter is a silent letter
        if (i + 1 < strlen(word) && word[i + 1] == 'n' && word[i] == 'b') {
            score++;
        }
    }

    // Check if the word is misspelled
    if (score < MAGIC_NUMBER) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char word[MAX_LENGTH];
    int correct = 0;

    // Ask the user for a word
    printf("Enter a word: ");
    fgets(word, MAX_LENGTH, stdin);

    // Check if the word is misspelled
    if (is_misspelled(word)) {
        printf("Oops! %s is misspelled!\n", word);
    } else {
        correct++;
        printf("Well done! %s is spelled correctly!\n", word);
    }

    // Ask the user if they want to try again
    printf("Do you want to try again? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    // Loop until the user gets it right or runs out of tries
    while (answer == 'y' || answer == 'Y') {
        // Ask the user for a word again
        printf("Enter a word: ");
        fgets(word, MAX_LENGTH, stdin);

        // Check if the word is misspelled
        if (is_misspelled(word)) {
            printf("Oops! %s is misspelled!\n", word);
        } else {
            correct++;
            printf("Well done! %s is spelled correctly!\n", word);
        }

        // Ask the user if they want to try again
        printf("Do you want to try again? (y/n): ");
        scanf(" %c", &answer);
    }

    // Print the final score
    printf("You scored %d out of %d\n", correct, MAGIC_NUMBER);

    return 0;
}