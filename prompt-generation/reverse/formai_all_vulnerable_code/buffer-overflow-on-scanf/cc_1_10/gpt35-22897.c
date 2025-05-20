//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void fillSymbolArray(char arr[], int size);
void fillNameArray(char arr[][20], int size);
void fillNumberArray(int arr[], int size);
void printTable(char symbolArr[], char nameArr[][20], int numberArr[], int size);
void quiz(char symbolArr[], char nameArr[][20], int numberArr[], int size);

// main function
int main() {
    // initialize random seed
    srand(time(NULL));

    // set table size and arrays
    int size = 5;
    char symbolArr[size];
    char nameArr[size][20];
    int numberArr[size];

    // fill arrays
    fillSymbolArray(symbolArr, size);
    fillNameArray(nameArr, size);
    fillNumberArray(numberArr, size);

    // print table
    printf("----- Periodic Table Quiz -----\n\n");
    printTable(symbolArr, nameArr, numberArr, size);

    // start quiz
    quiz(symbolArr, nameArr, numberArr, size);

    return 0;
}

// fill symbol array with random symbols
void fillSymbolArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        // generate random lowercase letter
        int c = rand() % 26 + 97;
        arr[i] = (char) c;
    }
}

// fill name array with random names
void fillNameArray(char arr[][20], int size) {
    for (int i = 0; i < size; i++) {
        // generate random uppercase letter
        int c = rand() % 26 + 65;
        arr[i][0] = (char) c;
        // generate random lowercase letters
        for (int j = 1; j < 19; j++) {
            c = rand() % 26 + 97;
            arr[i][j] = (char) c;
        }
        arr[i][19] = '\0'; // null-terminate string
    }
}

// fill number array with sequential numbers starting from 1
void fillNumberArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

// print periodic table
void printTable(char symbolArr[], char nameArr[][20], int numberArr[], int size) {
    printf("| Num | Symbol |      Name      |\n");
    printf("--------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("| %2d  |   %c    | %-14s |\n", numberArr[i], symbolArr[i], nameArr[i]);
    }
}

// start quiz
void quiz(char symbolArr[], char nameArr[][20], int numberArr[], int size) {
    int score = 0;
    printf("\n\n----- Quiz starts now -----\n");
    for (int i = 0; i < size; i++) {
        printf("\nWhat is the symbol and number for element %s? ", nameArr[i]);
        char symbol[2];
        int number;
        scanf("%s %d", symbol, &number);
        if (symbol[0] == symbolArr[i] && number == numberArr[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect, the correct answer is %c and %d.\n", symbolArr[i], numberArr[i]);
        }
    }
    printf("\n\n----- Quiz results -----\n");
    printf("Score: %d/%d\n", score, size);
    if (score == size) {
        printf("Congratulations, you got all the questions correct!\n");
    } else if (score >= (size/2)) {
        printf("Not bad, you got more than half of the questions correct.\n");
    } else {
        printf("Better luck next time.\n");
    }
}