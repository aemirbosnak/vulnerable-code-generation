//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char puzzle[100];
    int correct = 0;
    int operation = 0;
    float result = 0.0;

    printf("Welcome to the Puzzle Calculator!\n");
    printf("Please enter an operation (e.g., add, subtract, multiply, divide): ");
    scanf("%s", input);

    if (strcmp(input, "add") == 0) {
        operation = 1;
    } else if (strcmp(input, "subtract") == 0) {
        operation = 2;
    } else if (strcmp(input, "multiply") == 0) {
        operation = 3;
    } else if (strcmp(input, "divide") == 0) {
        operation = 4;
    } else {
        printf("Invalid operation. Please enter a valid operation.\n");
        return 0;
    }

    printf("Enter two numbers: ");
    scanf("%s", input);

    strcpy(puzzle, input);

    if (strcmp(puzzle, "1+2") == 0) {
        strcpy(puzzle, "3");
        correct = 1;
    } else if (strcmp(puzzle, "2+3") == 0) {
        strcpy(puzzle, "5");
        correct = 1;
    } else if (strcmp(puzzle, "3+4") == 0) {
        strcpy(puzzle, "7");
        correct = 1;
    } else if (strcmp(puzzle, "4+5") == 0) {
        strcpy(puzzle, "9");
        correct = 1;
    } else {
        printf("Invalid puzzle. Please enter a valid puzzle.\n");
        return 0;
    }

    if (correct == 1) {
        result = atof(puzzle);
    }

    printf("Result: %.2f\n", result);

    return 0;
}