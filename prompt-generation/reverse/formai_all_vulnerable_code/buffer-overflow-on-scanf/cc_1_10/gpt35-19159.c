//FormAI DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateQuestion(int *x, int *y, char *op) {
    /* generate two random numbers between 1 and 50 */
    *x = rand() % 50 + 1;
    *y = rand() % 50 + 1;

    /* generate a random operator from +, -, * */
    int operatorIndex = rand() % 3;
    if (operatorIndex == 0) {
        *op = '+';
    } else if (operatorIndex == 1) {
        *op = '-';
    } else {
        *op = '*';
    }
}

int solveQuestion(int x, int y, char op) {
    /* calculate the expression based on the operator */
    if (op == '+') {
        return x + y;
    } else if (op == '-') {
        return x - y;
    } else {
        return x * y;
    }
}

int main() {
    /* initialize the random seed */
    srand(time(NULL));

    int numOfPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numOfPlayers);

    int score[numOfPlayers];
    for (int i = 0; i < numOfPlayers; i++) {
        score[i] = 0;
    }

    int totalQuestions;
    printf("Enter the total number of questions: ");
    scanf("%d", &totalQuestions);

    for (int i = 0; i < totalQuestions; i++) {
        printf("\nQuestion %d:\n", i + 1);

        int x, y;
        char op;
        generateQuestion(&x, &y, &op);
        int answer = solveQuestion(x, y, op);

        printf("%d %c %d = ?\n", x, op, y);

        for (int j = 0; j < numOfPlayers; j++) {
            int playerAnswer;
            printf("Player %d, please enter the answer: ", j + 1);
            scanf("%d", &playerAnswer);

            if (playerAnswer == answer) {
                printf("Correct!\n");
                score[j]++;
            } else {
                printf("Wrong answer!\n");
            }
        }
    }

    printf("\nFinal scores:\n");

    for (int i = 0; i < numOfPlayers; i++) {
        printf("Player %d: %d points\n", i + 1, score[i]);
    }

    return 0;
}