//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
    char symbol[3], answer;
    int score = 0;
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Enter the symbol for each element in the periodic table.\n");
    printf("Press 'q' to quit at any time.\n");

    // Question 1
    printf("\n1. What is the symbol for Carbon? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "C") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'C'.\n");
    }

    // Question 2
    printf("\n2. What is the symbol for Oxygen? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "O") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'O'.\n");
    }

    // Question 3
    printf("\n3. What is the symbol for Helium? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "He") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'He'.\n");
    }

    // Question 4
    printf("\n4. What is the symbol for Sodium? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "Na") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'Na'.\n");
    }

    // Question 5
    printf("\n5. What is the symbol for Silver? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "Ag") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'Ag'.\n");
    }

    // Question 6
    printf("\n6. What is the symbol for Iron? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "Fe") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'Fe'.\n");
    }

    // Question 7
    printf("\n7. What is the symbol for Nitrogen? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "N") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'N'.\n");
    }

    // Question 8
    printf("\n8. What is the symbol for Gold? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "Au") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'Au'.\n");
    }

    // Question 9
    printf("\n9. What is the symbol for Calcium? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "Ca") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'Ca'.\n");
    }

    // Question 10
    printf("\n10. What is the symbol for Zinc? ");
    scanf("%s", symbol);
    if (strcmp(symbol, "Zn") == 0) {
        printf("Correct!\n");
        score++;
    } else if (strcmp(symbol, "q") == 0) {
        goto end;
    } else {
        printf("Incorrect. The correct symbol is 'Zn'.\n");
    }

    printf("\nQuiz Complete!\n");
    printf("Your score is %d out of 10.\n", score);

    end:
    printf("Thank you for playing the C Periodic Table Quiz!\n");

    return 0;
}