//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // declare variables
    int num1, num2, choice;
    float result;

    // initialize random seed
    srand(time(NULL));

    // prompt user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // prompt user to choose an operation
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    // perform selected operation
    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    // prompt user to continue or exit
    printf("Do you want to continue? (y/n): ");
    char cont;
    scanf(" %c", &cont);

    if(cont == 'y' || cont == 'Y') {
        main();
    } else {
        return 0;
    }

}