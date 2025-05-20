//FormAI DATASET v1.0 Category: Math exercise ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed for random number generation

    int score = 0; // player's score
    printf("Welcome to the Math Challenge!\n");
    printf("You will be given a series of mathematical equations to solve.\n");
    printf("Each correct answer will give you one point.\n");
    printf("You have 60 seconds to solve as many equations as possible.\n");
    printf("Press enter to start.");
    getchar();

    int start_time = time(0); // get start time
    int end_time = start_time + 60; // set end time

    while (time(0) < end_time) {
        // generate random equation
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;
        int operator = rand() % 3; // 0 = addition, 1 = subtraction, 2 = multiplication
        int result;
        char op_char;
        switch (operator) {
            case 0:
                result = a + b;
                op_char = '+';
                break;
            case 1:
                result = a - b;
                op_char = '-';
                break;
            case 2:
                result = a * b;
                op_char = '*';
                break;
        }

        // display equation and get player's answer
        printf("%d %c %d = ", a, op_char, b);
        int answer;
        scanf("%d", &answer);

        // check answer and update score
        if (answer == result) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("Time's up!\n");
    printf("Your score is %d.\n", score);
    return 0;
}