//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

// function to find the Fibonacci series
void fibonacci(int n) {
    int a = 0, b = 1, c, i;
    if(n == 0)
        printf("%d", a);
    else if(n == 1)
        printf("%d %d", a, b);
    else {
        printf("%d %d ", a, b);
        for(i=2; i<n; i++) {
            c = a + b;
            printf("%d ", c);
            a = b;
            b = c;
        }
    }
    printf("\n");
}

// function to find the greatest common divisor (GCD) of two numbers
int GCD(int num1, int num2) {
    int gcd, i;
    for(i=1; i<=num1 && i<=num2; i++) {
        if(num1%i==0 && num2%i==0)
            gcd = i;
    }
    return gcd;
}

// function to convert a decimal number to binary
long decimalToBinary(int n) {
    long binary = 0;
    int remainder, i=1;
    while(n != 0) {
        remainder = n%2;
        n /= 2;
        binary += remainder*i;
        i *= 10;
    }
    return binary;
}

// main function
int main() {
    int choice, num1, num2, n;
    long binary;
    do {
        printf("\n1. Fibonacci Series\n");
        printf("2. Greatest Common Divisor (GCD)\n");
        printf("3. Decimal to Binary Conversion\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                printf("Fibonacci Series: ");
                fibonacci(n);
                break;
            
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("GCD of %d and %d is %d", num1, num2, GCD(num1, num2));
                break;
                
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &num1);
                binary = decimalToBinary(num1);
                printf("Binary equivalent of %d is %ld", num1, binary);
                break;
                
            case 4:
                printf("Thank you for using the program.");
                break;
                
            default:
                printf("Invalid choice. Please try again.");
        }
        
    } while(choice != 4);
    
    return 0;
}