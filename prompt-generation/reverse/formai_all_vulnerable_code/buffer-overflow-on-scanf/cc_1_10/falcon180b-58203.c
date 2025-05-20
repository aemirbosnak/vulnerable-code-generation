//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int a, b, c;
    int operator;
    int result;

    printf("Welcome to the Mind-Bending Arithmetic Game!\n");
    printf("In this game, you will be given two numbers and an operator.\n");
    printf("Your task is to perform the operation and give the correct answer.\n");
    printf("Are you ready?\n");
    scanf("%d", &a);

    while(a!= 0) {
        b = rand() % 100;
        operator = rand() % 4;
        switch(operator) {
            case 0:
                printf("What is %d + %d?\n", a, b);
                result = a + b;
                break;
            case 1:
                printf("What is %d - %d?\n", a, b);
                result = a - b;
                break;
            case 2:
                printf("What is %d * %d?\n", a, b);
                result = a * b;
                break;
            case 3:
                printf("What is %d / %d?\n", a, b);
                if(b == 0) {
                    printf("Error: Division by zero!\n");
                    result = 0;
                } else {
                    result = a / b;
                }
                break;
            default:
                printf("Error: Invalid operator!\n");
                result = 0;
        }

        printf("Enter your answer: ");
        scanf("%d", &c);

        if(c == result) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", result);
        }

        a--;
    }

    printf("Game over. Thanks for playing!\n");
    return 0;
}