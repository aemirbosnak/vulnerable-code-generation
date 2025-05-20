//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Romantic Periodic Table Quiz */

int main () {
    int score = 0;
    char answer[20];
        
    printf("Welcome to the Romantic Periodic Table Quiz!\n\n");
    printf("Question 1: The symbol for the element Hydrogen is:\n");
    printf("a) Hy\nb) Hg\nc) H\n\n");
    printf("Your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "c") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong. The correct answer is c.\n");
    }

    printf("\nQuestion 2: The atomic number of Carbon is:\n");
    printf("a) 4\nb) 6\nc) 12\n\n");
    printf("Your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "b") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong. The correct answer is b.\n");
    }

    printf("\nQuestion 3: The symbol for the element Magnesium is:\n");
    printf("a) Mg\nb) Ma\nc) Mn\n\n");
    printf("Your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "a") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong. The correct answer is a.\n");
    }

    printf("\nQuestion 4: The element with the highest atomic number is:\n");
    printf("a) Uranium\nb) Carbon\nc) Oganesson\n\n");
    printf("Your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "c") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong. The correct answer is c.\n");
    }

    printf("\nQuestion 5: The symbol of the element that comes after Iron in the periodic table is:\n");
    printf("a) Zn\nb) Ga\nc) Co\n\n");
    printf("Your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "c") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong. The correct answer is c.\n");
    }

    printf("\nCongratulations! You finished the quiz with a score of %d out of 5.\n", score);

    if (score == 5) {
        printf("Wow! You really know your elements! I'm impressed.\n");
    } else if (score >= 3) {
        printf("Not bad. You have a decent understanding of the periodic table.\n");
    } else {
        printf("Better luck next time. Keep studying those elements!\n");
    }

    return 0;
}