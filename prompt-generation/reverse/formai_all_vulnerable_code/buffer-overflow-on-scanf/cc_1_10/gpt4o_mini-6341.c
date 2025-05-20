//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void initializeMatrix(int matrix[SIZE][SIZE]);
void displayMatrix(int matrix[SIZE][SIZE]);
void addMatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);
void subtractMatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);
void multiplyMatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);
void getMatrixInput(int matrix[SIZE][SIZE], int player);
void playerTurn(int player, int matrix[SIZE][SIZE]);
void playerOptions(int player, int matrix[SIZE][SIZE], int operation, int tempMatrix[SIZE][SIZE]);

int main() {
    int matrix[SIZE][SIZE];
    int playerCount, currentPlayer = 1;

    srand(time(0));

    printf("Welcome to the Multiplayer Matrix Game!\n");
    printf("Enter number of players (2-4): ");
    scanf("%d", &playerCount);

    if (playerCount < 2 || playerCount > 4) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }

    initializeMatrix(matrix);

    while (1) {
        displayMatrix(matrix);
        playerTurn(currentPlayer, matrix);
        currentPlayer = (currentPlayer % playerCount) + 1;

        char choice;
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("Final Matrix:\n");
    displayMatrix(matrix);
    return 0;
}

void initializeMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = rand() % 10;
}

void displayMatrix(int matrix[SIZE][SIZE]) {
    printf("Current Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void addMatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

void subtractMatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

void multiplyMatrices(int result[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
}

void getMatrixInput(int matrix[SIZE][SIZE], int player) {
    printf("Player %d, enter your matrix (%dx%d):\n", player, SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &matrix[i][j]);
}

void playerTurn(int player, int matrix[SIZE][SIZE]) {
    int operation;
    int tempMatrix[SIZE][SIZE];

    getMatrixInput(tempMatrix, player);

    printf("Player %d, choose an operation:\n", player);
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    printf("Enter the operation number: ");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            addMatrices(matrix, matrix, tempMatrix);
            break;
        case 2:
            subtractMatrices(matrix, matrix, tempMatrix);
            break;
        case 3:
            multiplyMatrices(matrix, matrix, tempMatrix);
            break;
        default:
            printf("Invalid operation selected!\n");
    }
}