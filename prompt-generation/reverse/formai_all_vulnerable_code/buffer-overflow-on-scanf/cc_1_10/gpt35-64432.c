//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
// This program demonstrates a unique way of performing arithmetic operations using bitwise operators

#include <stdio.h>

int main() {
    // Taking two inputs from the user
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Performing addition using bitwise operators
    int sum = num1;
    while(num2 != 0) {
        int carry = (sum & num2) << 1;
        sum = sum ^ num2;
        num2 = carry;
    }
    printf("Sum of the two numbers using bitwise operators: %d\n", sum);

    // Performing subtraction using bitwise operators
    int diff = num1;
    while(num2 != 0) {
        int borrow = (~diff & num2) << 1;
        diff = diff ^ num2;
        num2 = borrow;
    }
    printf("Difference of the two numbers using bitwise operators: %d\n", diff);

    // Performing multiplication using bitwise operators
    int product = 0, cnt = 0;
    while(num2 != 0) {
        if(num2 & 1) {
            product += num1 << cnt;
        }
        cnt++;
        num2 = num2 >> 1;
    }
    printf("Product of the two numbers using bitwise operators: %d\n", product);

    // Performing division using bitwise operators
    int quotient = 0;
    for(int i = 31; i >= 0; i--) {
        if((num1 >> i) >= num2) {
            quotient += 1 << i;
            num1 -= num2 << i;
        }
    }
    printf("Quotient of the two numbers using bitwise operators: %d\n", quotient);

    return 0;
}