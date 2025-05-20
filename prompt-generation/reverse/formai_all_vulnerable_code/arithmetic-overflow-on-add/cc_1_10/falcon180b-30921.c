//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char operation;
    float temp;
    srand(time(NULL));
    printf("Welcome to the Happy Arithmetic Program!\n");
    printf("Let's do some math with a smile on our faces!\n\n");

    while(1) {
        printf("Please enter an arithmetic expression (e.g. 5 + 3): ");
        scanf("%d %c %d", &num1, &operator, &num2);

        switch(operator) {
            case '+':
                result = num1 + num2;
                printf("The result is %d!\n\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("The result is %d!\n\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("The result is %d!\n\n", result);
                break;
            case '/':
                if(num2 == 0) {
                    printf("Oops! Division by zero is not allowed.\n\n");
                } else {
                    temp = (float)num1 / num2;
                    printf("The result is %.2f!\n\n", temp);
                }
                break;
            default:
                printf("Invalid operator. Please try again.\n\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &operation);
        if(operation == 'n' || operation == 'N') {
            break;
        }
    }

    printf("Thank you for using the Happy Arithmetic Program!\n");
    return 0;
}