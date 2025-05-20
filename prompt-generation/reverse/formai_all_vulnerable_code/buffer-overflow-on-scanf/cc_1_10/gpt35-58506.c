//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge of the elements and their symbols.\n");
    printf("Answer each question by typing the element's symbol and hitting enter.\n");
    printf("Let's get started...\n\n");

    // Question 1
    printf("Q1. What is the symbol for Carbon?\n");
    char answer1[3];
    scanf("%s", answer1);
    if (strcmp(answer1, "C") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Sorry, the correct answer is C.\n");
    }

    // Question 2
    printf("\nQ2. What is the symbol for Oxygen?\n");
    char answer2[3];
    scanf("%s", answer2);
    if (strcmp(answer2, "O") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Sorry, the correct answer is O.\n");
    }

    // Question 3
    printf("\nQ3. What is the symbol for Sodium?\n");
    char answer3[3];
    scanf("%s", answer3);
    if (strcmp(answer3, "Na") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Sorry, the correct answer is Na.\n");
    }

    // Question 4
    printf("\nQ4. What is the symbol for Iron?\n");
    char answer4[3];
    scanf("%s", answer4);
    if (strcmp(answer4, "Fe") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Sorry, the correct answer is Fe.\n");
    }

    // Question 5
    printf("\nQ5. What is the symbol for Gold?\n");
    char answer5[3];
    scanf("%s", answer5);
    if (strcmp(answer5, "Au") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Sorry, the correct answer is Au.\n");
    }

    printf("\nYou scored %d out of 5!\n", score);

    if (score == 5) {
        printf("Great job! You really know your elements!\n");
    } else if (score >= 3) {
        printf("Nice work! You have a good understanding of the elements!\n");
    } else {
        printf("Keep studying! You'll get there!\n");
    }

    return 0;
}