//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));
    int num1, num2, operator;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);
        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operator);
        printf("Enter another number: ");
        scanf("%d", &num2);
        printf("Enter Y to perform the operation or N to generate new numbers: ");
        scanf(" %c", &choice);

        switch(operator) {
            case '+':
                printf("The sum of %d and %d is %d\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("The difference between %d and %d is %d\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("The product of %d and %d is %d\n", num1, num2, num1 * num2);
                break;
            case '/':
                if(num2 == 0) {
                    printf("Cannot divide by zero!\n");
                } else {
                    printf("The quotient of %d and %d is %.2f\n", num1, num2, (float)num1 / num2);
                }
                break;
            default:
                printf("Invalid operator!\n");
        }

        if(choice == 'Y' || choice == 'y') {
            int result;
            switch(operator) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = (int)(num1 / num2 + 0.5);
                    break;
            }
            printf("The result is %d\n", result);
        }

    } while(choice == 'Y' || choice == 'y');

    return 0;
}