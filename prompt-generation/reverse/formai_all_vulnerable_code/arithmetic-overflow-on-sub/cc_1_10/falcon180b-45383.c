//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void print_binary(int num) {
    int i;
    for (i = MAX_SIZE - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    int num1, num2, choice;
    char operation;

    do {
        printf("Enter an integer (0 to quit): ");
        scanf("%d", &num1);

        printf("Enter an operation (+, -, *, /, &, |, ^, <<, >>): ");
        scanf("%c", &operation);

        if (operation!= 'q') {
            printf("Enter another integer: ");
            scanf("%d", &num2);

            switch (operation) {
                case '+':
                    printf("Result: %d\n", num1 + num2);
                    break;
                case '-':
                    printf("Result: %d\n", num1 - num2);
                    break;
                case '*':
                    printf("Result: %d\n", num1 * num2);
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Error: Division by zero\n");
                    } else {
                        printf("Result: %d\n", num1 / num2);
                    }
                    break;
                case '&':
                    printf("Result in binary: ");
                    print_binary(num1 & num2);
                    printf("\n");
                    break;
                case '|':
                    printf("Result in binary: ");
                    print_binary(num1 | num2);
                    printf("\n");
                    break;
                case '^':
                    printf("Result in binary: ");
                    print_binary(num1 ^ num2);
                    printf("\n");
                    break;
                case '<':
                    printf("Result in binary (left shift): ");
                    print_binary(num1 << num2);
                    printf("\n");
                    break;
                case '>':
                    printf("Result in binary (right shift): ");
                    print_binary(num1 >> num2);
                    printf("\n");
                    break;
            }
        }
    } while (operation!= 'q');

    return 0;
}