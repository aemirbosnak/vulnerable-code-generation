//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateTable();
void displayTable();
void shuffleTable();

int main() {
    int numQuestions;
    char repeat;
    srand(time(NULL));

    do {
        printf("Welcome to the C Periodic Table Quiz!\n");
        printf("How many questions would you like to answer? ");
        scanf("%d", &numQuestions);
        if (numQuestions <= 0) {
            printf("Invalid number of questions. Please try again.\n");
        }
    } while (numQuestions <= 0);

    int table[118];
    for (int i = 0; i < 118; i++) {
        table[i] = i + 1;
    }

    shuffleTable(table);

    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        int element = table[i];
        char symbol[3];
        sprintf(symbol, "%2c", element + 64);

        printf("Question %d:\n", i + 1);
        printf("What is the symbol for element %d? ", element);

        char answer[3];
        scanf("%s", answer);

        if (strcmp(answer, symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", symbol);
        }
    }

    printf("Your final score is %d out of %d.\n", score, numQuestions);
    printf("Would you like to play again? (y/n) ");
    scanf(" %c", &repeat);

    if (repeat == 'y' || repeat == 'Y') {
        main();
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}

void generateTable() {
    int table[118];
    for (int i = 0; i < 118; i++) {
        table[i] = i + 1;
    }
}

void displayTable() {
    int table[118];
    for (int i = 0; i < 118; i++) {
        table[i] = i + 1;
    }
}

void shuffleTable(int table[]) {
    for (int i = 0; i < 118; i++) {
        int j = rand() % 118;
        int temp = table[i];
        table[i] = table[j];
        table[j] = temp;
    }
}