//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    double x;
    double y;
} Point;

typedef enum {
    ADD,
    SUB,
    MUL,
    DIV
} Operation;

int main() {
    char input[MAX_INPUT_SIZE];
    Point p1, p2;
    Operation op;
    double result;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Enter the first point (x,y): ");
    scanf("%lf, %lf", &p1.x, &p1.y);
    printf("Enter the second point (x,y): ");
    scanf("%lf, %lf", &p2.x, &p2.y);
    printf("Enter the operation (+, -, *, /): ");
    scanf("%s", input);

    if (strcmp(input, "+") == 0) {
        op = ADD;
    } else if (strcmp(input, "-") == 0) {
        op = SUB;
    } else if (strcmp(input, "*") == 0) {
        op = MUL;
    } else if (strcmp(input, "/") == 0) {
        op = DIV;
    } else {
        printf("Invalid operation!\n");
        return 1;
    }

    switch (op) {
        case ADD:
            result = p1.x + p2.x;
            break;
        case SUB:
            result = p1.x - p2.x;
            break;
        case MUL:
            result = p1.x * p2.x;
            break;
        case DIV:
            result = p1.x / p2.x;
            break;
    }

    printf("Result: %lf\n", result);

    return 0;
}