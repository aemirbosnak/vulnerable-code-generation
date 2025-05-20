//Falcon-180B DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void error_handling(int error_code);
int calculate_sum(int num1, int num2);

// main function
int main() {
    int num1, num2, result;

    // get user input
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2)!= 2) {
        error_handling(1);
    }

    // calculate sum
    result = calculate_sum(num1, num2);

    // print result
    printf("The sum of %d and %d is %d.\n", num1, num2, result);

    return 0;
}

// calculate sum function
int calculate_sum(int num1, int num2) {
    int sum;

    // check for division by zero
    if (num2 == 0) {
        error_handling(2);
    }

    // calculate sum
    sum = num1 + num2;

    return sum;
}

// error handling function
void error_handling(int error_code) {
    switch (error_code) {
        case 1:
            printf("Error: Invalid input.\n");
            break;
        case 2:
            printf("Error: Division by zero.\n");
            break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }

    // exit program with error code
    exit(error_code);
}