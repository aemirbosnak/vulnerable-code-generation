//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN -100
#define MAX 100

void clearScreen() {
    printf("\033[2J");
}

void setColor(int fg, int bg) {
    printf("\033[%dm", (fg + 40 * bg));
}

int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    clearScreen();

    int num1 = randomNumber(MIN, MAX),
        num2 = randomNumber(MIN, MAX),
        result = 0;
    char operator;

    setColor(31, 40); // Red background
    printf("Welcome to the Magic Number Box!\n");
    setColor(31, 49); // Red text on dark red background

    do {
        setColor(31, 49);
        printf("\nChoose an operation (+, -, *, /): ");
        scanf(" %c", &operator);

        if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
            setColor(31, 41); // Red text on black background
            printf("\nInvalid input! Please try again.\n");
            continue;
        }

        setColor(31, 49);
        printf("\nNumber 1: %d", num1);
        setColor(31, 44); // Red text on dark green background
        printf("\nNumber 2: %d", num2);

        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    setColor(31, 41); // Red text on black background
                    printf("\nCannot divide by zero! Try again.\n");
                    continue;
                }
                result = num1 / num2;
                break;
        }

        setColor(31, 49);
        printf("\nResult: %d", result);

        num1 = randomNumber(MIN, MAX);
        num2 = randomNumber(MIN, MAX);

    } while (1);

    return 0;
}