//FormAI DATASET v1.0 Category: Educational ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("Welcome to C Programming!\n\n");
    
    printf("Let's write a program to calculate the factorial of a number. \n");
    printf(" Enter a positive number: ");
    
    int num, i;
    unsigned long long fact = 1;
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
    } else {
        for (i = 1; i <= num; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %llu\n", num, fact);
    }
    
    printf("\n\nNow, let's create a program to find the greatest common divisor (GCD) of two integer numbers. \n");
    printf(" Enter the first number: ");
    
    int n1, n2;
    scanf("%d", &n1);
    
    printf(" Enter the second number: ");
    scanf("%d", &n2);
    
    int gcd;
    for (i = 1; i <= n1 && i <= n2; ++i) {
        // check if i is factor of both integers
        if (n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }
    printf("GCD of %d and %d is %d\n", n1, n2, gcd);
    
    printf("\n\nThat was fun! Let's try something else. How about calculating the sum of all the odd numbers from 1 to a given integer?\n");
    printf(" Enter a positive number: ");
    
    int limit, sum = 0;
    scanf("%d", &limit);
    
    for (i = 1; i <= limit; i += 2) {
        sum += i;
    }
    printf("Sum of all odd numbers from 1 to %d is %d.\n", limit, sum);
    
    printf("\n\nOk, let's create a program that converts a decimal number to binary. \n");
    printf(" Enter a decimal number: ");
    
    int decimal, binary[20], j = 0;
    scanf("%d", &decimal);
    
    while (decimal > 0) {
        binary[j] = decimal % 2;
        decimal /= 2;
        j++;
    }
    printf("Binary representation is: ");
    for (i = j - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    
    printf("\n\nThanks for joining me! We just explored some of the basics of C programming and had some fun along the way!\n");
    
    return 0;
}