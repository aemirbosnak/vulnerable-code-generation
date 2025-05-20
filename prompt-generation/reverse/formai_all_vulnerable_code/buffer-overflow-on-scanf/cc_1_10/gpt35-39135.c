//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printHeader() {
    printf("========================\n");
    printf("   PASSWORD GENERATOR\n");
    printf("========================\n\n");
}

int getRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

char generateRandomSymbol() {
    char symbols[] = {'!', '@', '#', '$', '%', '&', '*', '?'};
    int idx = getRandomNumber(0, 7);
    char symbol = symbols[idx];
    return symbol;
}

char generateRandomLetter() {
    int uppercase = getRandomNumber(0, 1);
    int ascii = getRandomNumber(65, 90);
    char letter;
    if (uppercase) {
        letter = (char) ascii;
    } else {
        letter = (char) (ascii + 32);
    }
    return letter;
}

int main() {
    int length = 0;
    while (length < 8) {
        printHeader();
        printf("Enter password length (min. 8 characters): ");
        scanf("%d", &length);
    }

    srand(time(0));
    printf("\nYour secure password:\n");

    int numLetters = length / 2;
    int numSymbols = length - numLetters;

    for (int i = 0; i < numLetters; i++) {
        printf("%c", generateRandomLetter());
    }

    for (int i = 0; i < numSymbols; i++) {
        printf("%c", generateRandomSymbol());
    }

    printf("\n");

    return 0;
}