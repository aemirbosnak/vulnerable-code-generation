//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INT 2147483647
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square, cube;
    char operation;
    srand(time(NULL));

    printf("Welcome to the Arithmetic Wonderland!\n");

    do {
        printf("Please enter a number: ");
        scanf("%d", &num1);

        printf("Please enter an operation (+, -, x, /): ");
        scanf(" %c", &operation);

        if (operation == '+') {
            num2 = rand() % MAX_INT;
            sum = num1 + num2;
        } else if (operation == '-') {
            num2 = rand() % MAX_INT;
            sum = num1 - num2;
        } else if (operation == 'x') {
            num2 = rand() % MAX_INT;
            product = num1 * num2;
        } else if (operation == '/') {
            num2 = rand() % MAX_INT;
            if (num2 == 0) {
                printf("Error: division by zero!\n");
                break;
            }
            sum = num1 / num2;
        } else {
            printf("Invalid operation. Please try again.\n");
            continue;
        }

        printf("The result of %d %s %d is %d\n", num1, operation, num2, sum);

        square = num1 * num1;
        cube = num1 * num1 * num1;

        printf("The square of %d is %d\n", num1, square);
        printf("The cube of %d is %d\n", num1, cube);

        if (sum == MAGIC_NUMBER) {
            printf("Congratulations! You found the magic number %d!\n", MAGIC_NUMBER);
        }
    } while (1);

    return 0;
}