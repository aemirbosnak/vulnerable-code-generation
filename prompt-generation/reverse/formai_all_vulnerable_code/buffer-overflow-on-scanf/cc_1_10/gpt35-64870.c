//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Sherlock Holmes Periodic Table Quiz!\n");
    printf("To solve the case, you will need to answer questions about elements.\n\n");

    char ans;
    int score = 0;

    printf("Question 1: Which element has the symbol 'H'? (a) Helium (b) Hydrogen (c) Heliumhydrogenium\n");
    scanf(" %c", &ans);
    if (ans == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer. Sherlock would be disappointed.\n");
    }

    printf("\nQuestion 2: Which element has the symbol 'O'? (a) Oxygen (b) Ozone (c) Octium\n");
    scanf(" %c", &ans);
    if (ans == 'a') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer.\n");
    }

    printf("\nQuestion 3: Which element has the symbol 'Au'? (a) Silver (b) Gold (c) Aluminum\n");
    scanf(" %c", &ans);
    if (ans == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer. The thief got away with the gold.\n");
    }

    printf("\nQuestion 4: Which element has the symbol 'Fe'? (a) Fluorine (b) Iron (c) Neon\n");
    scanf(" %c", &ans);
    if (ans == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer. Back to the lab we go.\n");
    }

    printf("\nQuestion 5: Which element has the symbol 'He'? (a) Helium (b) Hydrogen (c) Heliumhydrogenium\n");
    scanf(" %c", &ans);
    if (ans == 'a') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Wrong answer. Watson, we need to keep digging.\n");
    }

    printf("\nYou have completed the quiz! Your final score is %d out of 5.\n", score);
    if (score == 5) {
        printf("Congratulations! You have solved the case.\n");
    } else {
        printf("Better luck next time, detective.\n");
    }

    return 0;
}