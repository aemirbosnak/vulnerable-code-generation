//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
#include<stdio.h>

// Function to perform bitwise AND operation
int bitwise_and(int a, int b){
    return a&b;
}

// Function to perform bitwise OR operation
int bitwise_or(int a, int b){
    return a|b;
}

// Function to perform bitwise XOR operation
int bitwise_xor(int a, int b){
    return a^b;
}

// Function to perform bitwise NOT operation
int bitwise_not(int a){
    return ~a;
}

// Function to perform left shift operation
int left_shift(int a, int b){
    return a<<b;
}

// Function to perform right shift operation
int right_shift(int a, int b){
    return a>>b;
}

int main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("\nBitwise AND: %d\n", bitwise_and(a,b));
    printf("Bitwise OR: %d\n", bitwise_or(a,b));
    printf("Bitwise XOR: %d\n", bitwise_xor(a,b));
    
    printf("Bitwise NOT of first number: %d\n", bitwise_not(a));
    printf("Bitwise NOT of second number: %d\n", bitwise_not(b));
    
    int shift;
    printf("Enter the number of times to perform left shift: ");
    scanf("%d", &shift);
    printf("Left shift of first number: %d\n", left_shift(a,shift));
    printf("Left shift of second number: %d\n", left_shift(b,shift));
    
    printf("Enter the number of times to perform right shift: ");
    scanf("%d", &shift);
    printf("Right shift of first number: %d\n", right_shift(a,shift));
    printf("Right shift of second number: %d\n", right_shift(b,shift));
    
    return 0;
}