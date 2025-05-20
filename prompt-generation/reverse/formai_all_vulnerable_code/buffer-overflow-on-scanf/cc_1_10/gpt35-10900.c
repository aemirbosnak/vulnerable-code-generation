//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, ans, userAns, correct = 0, total = 0;
    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the Math Exercise program!\n");
    printf("You will be presented with a series of math exercises to solve.\n");
    printf("Please enter your answer and press Enter to submit.\n");
    printf("Type 'Q' or 'q' at any time to quit.\n\n");

    while (1) { // repeat forever until user quits
        a = rand() % 100 + 1; // generate random numbers between 1 and 100
        b = rand() % 100 + 1;

        int op = rand() % 4; // randomly select an operator
        switch (op) {
            case 0: // addition
                ans = a + b;
                printf("%d + %d = ", a, b);
                break;
            case 1: // subtraction
                ans = a - b;
                printf("%d - %d = ", a, b);
                break;
            case 2: // multiplication
                ans = a * b;
                printf("%d * %d = ", a, b);
                break;
            case 3: // division
                ans = a / b;
                printf("%d / %d = ", a, b);
                break;
        }

        // read user input
        char buf[10];
        scanf("%s", buf);
        if (buf[0] == 'q' || buf[0] == 'Q') break; // exit if user types 'q' or 'Q'

        userAns = atoi(buf); // convert user input to integer

        if (userAns == ans) { // check if user's answer is correct
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", ans);
        }

        total++;
    }

    printf("You answered %d out of %d questions correctly.\n", correct, total);

    return 0;
}