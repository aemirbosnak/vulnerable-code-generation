//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 25
#define MAX_QUESTION_LENGTH 50

// Define the knightly virtues
#define BRAVERY 1
#define WISDOM 2
#define COURAGE 3
#define HONOR 4

// Define the questions and answers
#define QUESTION1 "What is thy banner's name?"
#define ANSWER1 "My banner's name is 'Valor'."
#define QUESTION2 "What is thy armor's strength?"
#define ANSWER2 "My armor's strength is 'Invincible'."
#define QUESTION3 "What is thy sword's name?"
#define ANSWER3 "My sword's name is 'Justice'."

// Define the knight's name and banner
#define KNIGHT_NAME "Sir Edward"
#define BANNER_NAME "Loyalty"

int main() {
    // Initialize the knight's virtues
    int bravery = 0;
    int wisdom = 0;
    int courage = 0;
    int honor = 0;

    // Ask the knight questions and adjust virtues accordingly
    printf("Hail, Sir Edward! What is thy banner's name?\n");
    gets(KNIGHT_NAME);
    if (strcmp(KNIGHT_NAME, BANNER_NAME) == 0) {
        bravery += BRAVERY;
    } else {
        bravery -= COURAGE;
    }
    printf("Well done, Sir Edward! What is thy armor's strength?\n");
    gets(KNIGHT_NAME);
    if (strcmp(KNIGHT_NAME, "Invincible") == 0) {
        courage += COURAGE;
    } else {
        courage -= WISDOM;
    }
    printf("Excellent, Sir Edward! What is thy sword's name?\n");
    gets(KNIGHT_NAME);
    if (strcmp(KNIGHT_NAME, "Justice") == 0) {
        honor += HONOR;
    } else {
        honor -= BRAVERY;
    }

    // Print the knight's virtues
    printf("Thy virtues are:\n");
    printf("  Bravery: %d\n", bravery);
    printf("  Wisdom: %d\n", wisdom);
    printf("  Courage: %d\n", courage);
    printf("  Honor: %d\n", honor);

    // Determine the knight's worthiness
    if (bravery > 0 && wisdom > 0 && courage > 0 && honor > 0) {
        printf("Thou art a true and worthy knight! May thy banner forever fly high and thy sword strike true!\n");
    } else {
        printf("Thou art not worthy of the title 'knight'... yet. Return and seek the virtues of thy order!\n");
    }

    return 0;
}