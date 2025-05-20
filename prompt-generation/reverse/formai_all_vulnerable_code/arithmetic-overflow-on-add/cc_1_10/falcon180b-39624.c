//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator;
    char choice;
    float result;

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Enter '1' for addition, '2' for subtraction, '3' for multiplication, and '4' for division.\n");
    scanf("%d", &operator);

    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    switch(operator) {
        case 1:
            result = num1 + num2;
            printf("The result is: %.2f\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("The result is: %.2f\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result is: %.2f\n", result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result is: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid operator!\n");
    }

    printf("Do you want to perform another calculation? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for using the Arithmetic Calculator!\n");
    }

    return 0;
}