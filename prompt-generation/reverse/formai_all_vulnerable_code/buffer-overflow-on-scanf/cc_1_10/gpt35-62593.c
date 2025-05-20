//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Welcome to the Periodic Table Quiz! \n");
    printf("Enter your name: ");

    char name[50];
    scanf("%s", name);

    printf("\nGreat, %s! Let's get started.\n\n", name);

    int score = 0;

    printf("Question 1: What is the symbol for oxygen? \n");
    printf("a) O \n");
    printf("b) K \n");
    printf("c) Hg \n");
    printf("d) C \n\n");

    char answer1;
    scanf(" %c", &answer1);

    if(answer1 == 'a') {
        printf("Correct! O stands for oxygen. \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is a) O. \n");
    }

    printf("\n");

    printf("Question 2: What is the atomic number for gold? \n");
    printf("a) 23 \n");
    printf("b) 78 \n");
    printf("c) 90 \n");
    printf("d) 64 \n\n");

    char answer2;
    scanf(" %c", &answer2);

    if(answer2 == 'b') {
        printf("Correct! Gold has an atomic number of 78. \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is b) 78. \n");
    }

    printf("\n");

    printf("Question 3: Which element has the symbol Ag? \n");
    printf("a) Silver \n");
    printf("b) Sodium \n");
    printf("c) Silicon \n");
    printf("d) Strontium \n\n");

    char answer3;
    scanf(" %c", &answer3);

    if(answer3 == 'a') {
        printf("Correct! Ag stands for silver. \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is a) Silver. \n");
    }

    printf("\n");

    printf("Question 4: Which element is necessary for life? \n");
    printf("a) Carbon \n");
    printf("b) Helium \n");
    printf("c) Neon \n");
    printf("d) Lithium \n\n");

    char answer4;
    scanf(" %c", &answer4);

    if(answer4 == 'a') {
        printf("Correct! Carbon is necessary for life. \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is a) Carbon. \n");
    }

    printf("\n");

    printf("Question 5: Which element is used to make potato chips? \n");
    printf("a) Sodium \n");
    printf("b) Chlorine \n");
    printf("c) Carbon \n");
    printf("d) Hydrogen \n\n");

    char answer5;
    scanf(" %c", &answer5);

    if(answer5 == 'a') {
        printf("Correct! Sodium is used to make potato chips. \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is a) Sodium. \n");
    }

    printf("\n");

    printf("Congratulations, %s! You scored %d out of 5.\n", name, score);

    return 0;
}