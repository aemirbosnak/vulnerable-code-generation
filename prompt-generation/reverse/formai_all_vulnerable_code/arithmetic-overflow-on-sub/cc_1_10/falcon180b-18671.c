//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char choice;

    printf("Welcome to the Arithmetic Program!\n");
    printf("Enter '1' to perform addition.\n");
    printf("Enter '2' to perform subtraction.\n");
    printf("Enter '3' to perform multiplication.\n");
    printf("Enter '4' to perform division.\n");
    scanf("%d", &operator);

    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    switch(operator) {
        case 1:
            result = num1 + num2;
            printf("The result of %d + %d is %d.\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The result of %d - %d is %d.\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result of %d * %d is %d.\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Division by zero error!\n");
            } else {
                result = num1 / num2;
                printf("The result of %d / %d is %d.\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operator!\n");
    }

    printf("Do you want to perform another operation? (y/n)\n");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for using the Arithmetic Program!\n");
    }

    return 0;
}