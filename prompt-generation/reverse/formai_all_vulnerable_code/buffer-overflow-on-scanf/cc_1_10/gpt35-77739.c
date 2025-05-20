//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cryptic
#include <stdio.h>

# define DIGITS 256

int main() {
    int i, j, k, n, temp, f1, f2, t;
    // Initialization of variables
    int num1[DIGITS] = {0};
    int num2[DIGITS] = {0};
    int result[DIGITS] = {0};
    char input1[DIGITS], input2[DIGITS];

    printf("Enter the first number: ");
    scanf("%s", input1);
    printf("Enter the second number: ");
    scanf("%s", input2);

    // Finding the length of the numbers
    f1 = strlen(input1);
    f2 = strlen(input2);

    // Reversing the numbers
    for(i = 0; i < f1; i++) 
        num1[i] = input1[f1 - i - 1] - '0';

    for(i = 0; i < f2; i++)
        num2[i] = input2[f2 - i - 1] - '0' ;

    // Multiplication
    for(i = 0; i < f1; i++) {
        t = 0;
        for(j = 0; j < f2 || t; j++) {
            temp = result[i+j] + num1[i] * (j < f2 ? num2[j] : 0) + t;
            result[i + j] = temp % 10;
            t = temp / 10;
        }
    }

    // Reversing the result
    for(i = DIGITS - 1; i >= 0; i--)
        if(result[i]) break;

    printf("The Multiplication of two number is: ");

    for(; i >= 0; i--)
        printf("%d", result[i]);
    printf("\n");

    return 0;
}