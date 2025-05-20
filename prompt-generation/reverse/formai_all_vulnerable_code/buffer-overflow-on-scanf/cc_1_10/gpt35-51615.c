//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to convert a decimal number to binary
int* decimalToBinary(int decimalNumber) {
    int* binaryNumber = (int*)malloc(8 * sizeof(int));
    int index = 0;
    while(decimalNumber > 0) {
        binaryNumber[index++] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
    }
    while(index < 8) {
        binaryNumber[index++] = 0;
    }
    return binaryNumber;
}

// Function to perform a bitwise AND operation on two numbers
int bitwiseAnd(int number1, int number2) {
    int* binaryNumber1 = decimalToBinary(number1);
    int* binaryNumber2 = decimalToBinary(number2);
    int bitwiseANDnumber = 0;
    for(int i = 0; i < 8; i++) {
        if(binaryNumber1[i] == 1 && binaryNumber2[i] == 1) {
            bitwiseANDnumber = bitwiseANDnumber + (1 << i);
        }
    }
    free(binaryNumber1);
    free(binaryNumber2);
    return bitwiseANDnumber;
}

// Function to perform a bitwise OR operation on two numbers
int bitwiseOr(int number1, int number2) {
    int* binaryNumber1 = decimalToBinary(number1);
    int* binaryNumber2 = decimalToBinary(number2);
    int bitwiseORnumber = 0;
    for(int i = 0; i < 8; i++) {
        if(binaryNumber1[i] == 0 && binaryNumber2[i] == 0) {
            bitwiseORnumber = bitwiseORnumber + 0;
        } else {
            bitwiseORnumber = bitwiseORnumber + (1 << i);
        }
    }
    free(binaryNumber1);
    free(binaryNumber2);
    return bitwiseORnumber;
}

// Function to perform a bitwise XOR operation on two numbers
int bitwiseXor(int number1, int number2) {
    int* binaryNumber1 = decimalToBinary(number1);
    int* binaryNumber2 = decimalToBinary(number2);
    int bitwiseXORnumber = 0;
    for(int i = 0; i < 8; i++) {
        if(binaryNumber1[i] == binaryNumber2[i]) {
            bitwiseXORnumber = bitwiseXORnumber + 0;
        } else {
            bitwiseXORnumber = bitwiseXORnumber + (1 << i);
        }
    }
    free(binaryNumber1);
    free(binaryNumber2);
    return bitwiseXORnumber;
}

// Function to generate a random number between 1 and 255
int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 255 + 1;
}

int main() {
    int number1, number2;
    char operation[4];

    printf("Welcome to the Bitwise Operations Multiplayer Game!\n\n");
    printf("To start the game, please enter your name: ");
    char playerName[50];
    scanf("%s", playerName);
    printf("\nHello, %s! Let's get started.\n\n", playerName);
    printf("Here's how to play: You and your opponent will take turns generating random numbers.\n");
    printf("Then, you will choose whether to perform a bitwise AND, OR, or XOR operation on the numbers.\n");
    printf("The player with the highest resulting number wins the round!\n");
    printf("You will play three rounds total. Let's begin!\n\n");

    int player1Score = 0;
    int player2Score = 0;

    for(int round = 1; round <= 3; round++) {
        printf("********** ROUND %d **********\n\n", round);
        printf("Player 1, it's your turn to generate a random number. Press enter to continue.\n");
        getchar(); // For clearing the newline character in the input buffer
        getchar();
        number1 = generateRandomNumber();
        printf("\nPlayer 1, your number is %d\n\n", number1);

        printf("Player 2, it's your turn to generate a random number. Press enter to continue.\n");
        getchar();
        number2 = generateRandomNumber();
        printf("\nPlayer 2, your number is %d\n\n", number2);

        printf("Player 1, choose an operation: AND, OR, or XOR. Type the operation in all caps and press enter.\n");
        scanf("%s", operation);
        printf("\n");

        int result;
        if(strcmp(operation, "AND") == 0) {
            result = bitwiseAnd(number1, number2);
            printf("The result of %d AND %d is %d\n\n", number1, number2, result);
        } else if(strcmp(operation, "OR") == 0) {
            result = bitwiseOr(number1, number2);
            printf("The result of %d OR %d is %d\n\n", number1, number2, result);
        } else if(strcmp(operation, "XOR") == 0) {
            result = bitwiseXor(number1, number2);
            printf("The result of %d XOR %d is %d\n\n", number1, number2, result);
        } else {
            printf("Invalid operation. Please choose from AND, OR, or XOR.\n\n");
            round--;
            continue;
        }

        if(result == number1 || result == number2) {
            printf("The resulting number is one of the input numbers, so no points will be awarded for this round.\n\n");
        } else if(result > number1 && result > number2) {
            player1Score++;
            printf("Player 1 wins this round! Player 1's score: %d, Player 2's score: %d\n\n", player1Score, player2Score);
        } else if(result < number1 && result < number2) {
            player2Score++;
            printf("Player 2 wins this round! Player 1's score: %d, Player 2's score: %d\n\n", player1Score, player2Score);
        } else {
            printf("It's a tie! No points will be awarded for this round. Player 1's score: %d, Player 2's score: %d\n\n", player1Score, player2Score);
        }
    }

    printf("********** GAME OVER **********\n\n");
    if(player1Score > player2Score) {
        printf("Congratulations, %s! You win the game with a score of %d-%d.\n", playerName, player1Score, player2Score);
    } else if(player2Score > player1Score) {
        printf("Sorry, %s. You lost the game with a score of %d-%d.\n", playerName, player2Score, player1Score);
    } else {
        printf("It's a tie! The final score is %d-%d.\n", player1Score, player2Score);
    }

    return 0;
}