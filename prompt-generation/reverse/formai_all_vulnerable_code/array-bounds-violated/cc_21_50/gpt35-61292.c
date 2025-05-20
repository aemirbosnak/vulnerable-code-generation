//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int userBoard[5][5], computerBoard[5][5];
    int userNums[25] = {0}, computerNums[25] = {0};
    int userPoints = 0, computerPoints = 0, numCount = 1;
    int userBingo = 0, computerBingo = 0;
    char playAgain = 'y';

    // initialize random number generator
    srand(time(NULL));

    while (playAgain == 'y') {

        // initialize user board with random numbers
        printf("Your board:\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 2 && j == 2) {
                    userBoard[i][j] = 0;
                    printf("| 0 ");
                } else {
                    int num = rand() % 75 + 1;
                    while (userNums[num - 1] == 1) {
                        num = rand() % 75 + 1;
                    }
                    userBoard[i][j] = num;
                    userNums[num - 1] = 1;
                    printf("| %d ", num);
                }
            }
            printf("|\n");
        }

        // initialize computer board with random numbers
        printf("\nComputer's board:\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 2 && j == 2) {
                    computerBoard[i][j] = 0;
                    printf("| 0 ");
                } else {
                    int num = rand() % 75 + 1;
                    while (computerNums[num - 1] == 1) {
                        num = rand() % 75 + 1;
                    }
                    computerBoard[i][j] = num;
                    computerNums[num - 1] = 1;
                    printf("| X ");
                }
            }
            printf("|\n");
        }

        // game loop
        while (userBingo == 0 && computerBingo == 0) {

            // user's turn
            printf("\nEnter a number between 1 and 75: ");
            int userChoice;
            scanf("%d", &userChoice);
            while (userNums[userChoice - 1] == 1) {
                printf("Already called that number. Enter a different number: ");
                scanf("%d", &userChoice);
            }
            userNums[userChoice - 1] = 1;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (userBoard[i][j] == userChoice) {
                        userBoard[i][j] = 0;
                        userPoints++;
                    }
                }
            }
            printf("Your board:\n");
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    printf("| %d ", userBoard[i][j]);
                }
                printf("|\n");
            }
            printf("\n");

            // check if user has bingo
            if (userPoints >= 5) {
                for (int i = 0; i < 5; i++) {
                    int rowSum = 0, colSum = 0, diagSum1 = 0, diagSum2 = 0;
                    for (int j = 0; j < 5; j++) {
                        rowSum += userBoard[i][j];
                        colSum += userBoard[j][i];
                        if (i == j) {
                            diagSum1 += userBoard[i][j];
                        }
                        if (i + j == 4) {
                            diagSum2 += userBoard[i][j];
                        }
                    }
                    if (rowSum == 0 || colSum == 0 || diagSum1 == 0 || diagSum2 == 0) {
                        userBingo = 1;
                        printf("BINGO! You win!\n");
                    }
                }
            }

            if (userBingo == 1) {
                break;
            }

            // computer's turn
            int computerChoice = rand() % 75 + 1;
            while (computerNums[computerChoice - 1] == 1) {
                computerChoice = rand() % 75 + 1;
            }
            computerNums[computerChoice - 1] = 1;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (computerBoard[i][j] == computerChoice) {
                        computerBoard[i][j] = 0;
                        computerPoints++;
                    }
                }
            }
            printf("Computer's board:\n");
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    printf("| %c ", computerBoard[i][j] == 0 ? 'X' : '-');
                }
                printf("|\n");
            }
            printf("\n");

            // check if computer has bingo
            if (computerPoints >= 5) {
                for (int i = 0; i < 5; i++) {
                    int rowSum = 0, colSum = 0, diagSum1 = 0, diagSum2 = 0;
                    for (int j = 0; j < 5; j++) {
                        rowSum += computerBoard[i][j];
                        colSum += computerBoard[j][i];
                        if (i == j) {
                            diagSum1 += computerBoard[i][j];
                        }
                        if (i + j == 4) {
                            diagSum2 += computerBoard[i][j];
                        }
                    }
                    if (rowSum == 0 || colSum == 0 || diagSum1 == 0 || diagSum2 == 0) {
                        computerBingo = 1;
                        printf("BINGO! Computer wins!\n");
                    }
                }
            }
        }

        // ask if user wants to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        numCount = 1;
        userBingo = 0;
        computerBingo = 0;
        userPoints = 0;
        computerPoints = 0;
        for (int i = 0; i < 25; i++) {
            userNums[i] = 0;
            computerNums[i] = 0;
        }
    }

    return 0;
}