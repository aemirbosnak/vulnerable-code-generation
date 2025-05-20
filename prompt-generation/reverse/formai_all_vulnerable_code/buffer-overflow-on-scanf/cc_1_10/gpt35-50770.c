//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Generates random numbers for the operands
    srand(time(NULL));
    int a = rand()%101;
    int b = rand()%101;

    // Generates a random operator
    char ops[4] = {'+', '-', '*', '/'};
    int r = rand()%4;
    char op = ops[r];

    // Evaluate the expression generated
    float res;
    switch(op) {
        case '+':
            res = a+b;
            break;
        case '-':
            res = a-b;
            break;
        case '*':
            res = a*b;
            break;
        case '/':
            res = (float)a/b;
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }

    // Print the expression
    printf("Evaluate the following expression:\n");
    printf("%d %c %d = ?\n", a, op, b);

    // Input the value from the user
    float input;
    scanf("%f", &input);

    // Check the user's answer and print the result
    if(input == res) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %f\n", res);
    }

    return 0;
}