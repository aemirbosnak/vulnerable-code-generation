//FormAI DATASET v1.0 Category: Math exercise ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given five random math problems to solve.\n");
    printf("Type in the answer and press enter to continue.\n");
    printf("Let's begin!\n\n");

    srand(time(NULL));
    int correct = 0;
    int total = 0;

    for (int i = 0; i < 5; i++) {
        int a = rand() % 10;
        int b = rand() % 10;

        int operation = rand() % 3;

        int result;
        char symbol;

        if (operation == 0) {
            result = a + b;
            symbol = '+';
        } else if (operation == 1) {
            result = a - b;
            symbol = '-';
        } else {
            result = a * b;
            symbol = '*';
        }

        printf("%d %c %d = ", a, symbol, b);

        int answer;
        scanf("%d", &answer);

        if (answer == result) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", result);
        }

        total++;
    }

    printf("\nYou got %d out of %d correct!\n", correct, total);
    printf("Thanks for playing the Math Exercise Program!\n");

    return 0;
}