//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize variables
    int num1, num2, result;
    char choice;
    int i = 0;

    //seed the random number generator
    srand(time(NULL));

    //prompt user for input
    printf("Welcome to the Bitwise Operations Program!\n");
    printf("Please enter two integers to perform bitwise operations on:\n");

    //get two integers from user
    while (i < 2) {
        scanf("%d", &num1);
        if (num1 == 0) {
            printf("Please enter a non-zero integer:\n");
        } else {
            i++;
        }
    }
    i = 0;
    while (i < 2) {
        scanf("%d", &num2);
        if (num2 == 0) {
            printf("Please enter a non-zero integer:\n");
        } else {
            i++;
        }
    }

    //prompt user for operation choice
    printf("Please choose an operation:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    scanf(" %c", &choice);

    //perform chosen operation
    switch (choice) {
        case '1':
            result = num1 & num2;
            printf("The result of %d AND %d is %d.\n", num1, num2, result);
            break;
        case '2':
            result = num1 | num2;
            printf("The result of %d OR %d is %d.\n", num1, num2, result);
            break;
        case '3':
            result = num1 ^ num2;
            printf("The result of %d XOR %d is %d.\n", num1, num2, result);
            break;
        case '4':
            result = ~num1;
            printf("The result of NOT %d is %d.\n", num1, result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}