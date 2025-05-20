//FormAI DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 10

int main() {
    int numArray[MAX_INPUT_SIZE];
    int numCount = 0;
    char input[MAX_INPUT_SIZE*2];
    char *inputPtr = input;

    printf("Enter up to %d integers, separated by commas:\n", MAX_INPUT_SIZE);
    fgets(input, sizeof(input), stdin);

    while(*inputPtr != '\0') {
        int tempNum = strtol(inputPtr, &inputPtr, 10);
        numArray[numCount++] = tempNum;

        if(numCount == MAX_INPUT_SIZE) {
            break;
        }

        if(*inputPtr == ',') {
            inputPtr++;
        } else {
            break;
        }
    }

    printf("\nEntered integers: ");
    for(int i = 0; i < numCount; i++) {
        if(i == numCount - 1) {
            printf("%d\n", numArray[i]);
        } else {
            printf("%d, ", numArray[i]);
        }
    }

    bool validOperator = false;
    char operator;
    do {
        printf("\nEnter a valid operator (+, -, *, /): ");
        scanf("%c", &operator);
        if(operator == '+' || operator == '-' || operator == '*' || operator == '/') {
            validOperator = true;
        } else {
            printf("\nInvalid operator. Please enter a valid operator.\n");
            fflush(stdin);
        }
    } while(!validOperator);

    int result;
    switch(operator) {
        case '+':
            result = numArray[0] + numArray[1];
            break;
        case '-':
            result = numArray[0] - numArray[1];
            break;
        case '*':
            result = numArray[0] * numArray[1];
            break;
        case '/':
            result = numArray[0] / numArray[1];
            break;
        default:
            printf("\nUnexpected operator. Something went wrong.\n");
            exit(EXIT_FAILURE);
    }

    printf("\nResult: %d %c %d = %d\n", numArray[0], operator, numArray[1], result);

    return 0;
}