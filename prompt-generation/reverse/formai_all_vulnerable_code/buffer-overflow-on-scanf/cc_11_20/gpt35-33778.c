//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, answer;
    char choice;
    srand(time(NULL)); // Seed random number generator

    printf("\n\n\n\n\n\n\n");
    printf("\t\tWelcome to the Periodic Table Quiz!\n");
    printf("\t\t*********************************\n\n\n");

    printf("\t\tChoose a category:\n\n");
    printf("\t\t1. Alkali Metals\n");
    printf("\t\t2. Halogens\n");
    printf("\t\t3. Transition Metals\n\n");
    printf("\t\tEnter your choice: ");
    scanf("%c", &choice);

    if (choice == '1') {
        printf("\n\n\n\t\tCategory: Alkali Metals\n\n");
        printf("\t\tWhat is the symbol for Sodium? ");
        scanf("%d", &answer);

        if (answer == 11) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 11.\n");
        }

        printf("\t\tWhat is the symbol for Potassium? ");
        scanf("%d", &answer);

        if (answer == 19) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 19.\n");
        }

        printf("\t\tWhat is the symbol for Rubidium? ");
        scanf("%d", &answer);

        if (answer == 37) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 37.\n");
        }

        printf("\n\n\n\t\tYour score is: %d\n", score);

    } else if (choice == '2') {
        printf("\n\n\n\t\tCategory: Halogens\n\n");
        printf("\t\tWhat is the symbol for Fluorine? ");
        scanf("%d", &answer);

        if (answer == 9) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 9.\n");
        }

        printf("\t\tWhat is the symbol for Chlorine? ");
        scanf("%d", &answer);

        if (answer == 17) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 17.\n");
        }

        printf("\t\tWhat is the symbol for Bromine? ");
        scanf("%d", &answer);

        if (answer == 35) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 35.\n");
        }

        printf("\n\n\n\t\tYour score is: %d\n", score);

    } else if (choice == '3') {
        printf("\n\n\n\t\tCategory: Transition Metals\n\n");
        printf("\t\tWhat is the symbol for Iron? ");
        scanf("%d", &answer);

        if (answer == 26) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 26.\n");
        }

        printf("\t\tWhat is the symbol for Copper? ");
        scanf("%d", &answer);

        if (answer == 29) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 29.\n");
        }

        printf("\t\tWhat is the symbol for Gold? ");
        scanf("%d", &answer);

        if (answer == 79) {
            printf("\n\t\tCorrect!\n");
            score++;
        } else {
            printf("\n\t\tWrong answer! The correct answer is 79.\n");
        }

        printf("\n\n\n\t\tYour score is: %d\n", score);

    } else {
        printf("\n\n\n\t\tInvalid choice! Please enter a valid option.\n");
    }

    return 0;
}