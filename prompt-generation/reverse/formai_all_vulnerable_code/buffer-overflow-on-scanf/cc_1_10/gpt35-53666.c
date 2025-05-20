//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include<stdio.h>

// function to check if a given number is even or odd
int even_or_odd(int num) {
    if (num & 1) { 
        // if the value of num AND 1 is 1 i.e., the 1st bit is set, then it is an odd number  
        return 0; //return 0 to indicate the number is odd
    } else { 
        // if the value of num AND 1 is 0 i.e., the 1st bit is unset, then it is an even number
        return 1; // return 1 to indicate the number is even
    }
}

// function to swap two numbers using bitwise XOR operation
void swap_numbers(int *a, int *b) {
    *a = *a ^ *b; // XOR operation to swap the values
    *b = *b ^ *a;
    *a = *a ^ *b;
}

// function to find the complement of a given number using bitwise NOT operation
int find_complement(int num) {
    // XOR the value of num with all ones 
    // to get the bitwise complement of num
    int mask = ~0; // setting all bits to 1
    while (num & mask) { 
        // to get the bit width of num, we need to count the number of bits it takes up when represented in binary
        // use a right shift to move the mask to the right until the num is completely shifted out
        mask <<= 1;
    }
    // to get the bitwise complement of num, XOR num with all ones
    return ~num ^ mask;
}

int main() {
    int num1, num2, result;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // check if the first number is even or odd
    if (even_or_odd(num1)) { 
        printf("%d is an even number\n", num1);
    } else {
        printf("%d is an odd number\n", num1);
    }
    
    // swap the values of num1 and num2 using bitwise XOR operation
    swap_numbers(&num1, &num2);
    printf("After swapping, num1 is %d and num2 is %d\n", num1, num2);
    
    // find the bitwise complement of num2 using bitwise NOT operation
    result = find_complement(num2);
    printf("The bitwise complement of %d is %d\n", num2, result);
    
    return 0;
}