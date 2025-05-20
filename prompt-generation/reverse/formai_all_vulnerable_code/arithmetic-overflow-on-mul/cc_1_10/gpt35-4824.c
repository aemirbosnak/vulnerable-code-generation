//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>

int main()
{
    int num1, num2, sum, sub, mul, div;
    
    printf("Welcome to the Arithmetic Program!\n\n");
    
    printf("Enter first number: ");
    scanf("%d", &num1); // get first number from user
    
    printf("Enter second number: ");
    scanf("%d", &num2); // get second number from user
    
    // perform arithmetic operations
    sum = num1 + num2;
    sub = num1 - num2;
    mul = num1 * num2;
    div = num1 / num2;
    
    // print results
    printf("\nResults:\n");
    
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, sub);
    printf("%d x %d = %d\n", num1, num2, mul);
    printf("%d / %d = %d\n", num1, num2, div);
    
    // check for even or odd numbers
    if(num1 % 2 == 0){
        printf("%d is even.\n", num1);
    } else {
        printf("%d is odd.\n", num1);
    }
    
    if(num2 % 2 == 0){
        printf("%d is even.\n", num2);
    } else {
        printf("%d is odd.\n", num2);
    }
    
    // check for positive or negative numbers
    if(num1 > 0){
        printf("%d is positive.\n", num1);
    } else if(num1 < 0){
        printf("%d is negative.\n", num1);
    } else {
        printf("%d is neither positive nor negative.\n", num1);
    }
    
    if(num2 > 0){
        printf("%d is positive.\n", num2);
    } else if(num2 < 0){
        printf("%d is negative.\n", num2);
    } else {
        printf("%d is neither positive nor negative.\n", num2);
    }
    
    return 0;
}