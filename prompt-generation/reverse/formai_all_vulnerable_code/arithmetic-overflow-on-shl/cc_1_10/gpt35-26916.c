//FormAI DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include<stdio.h>

// Function to print bits of integer
void printBits(unsigned int num)
{
    // Mask to extract bit
    unsigned int mask = 1 << 31;
    for(int i=0; i<32; i++)
    {
        // Bitwise AND operation
        // Extracts bit starting from left-most
        unsigned int bit = num & mask;
        if(bit == 0)
            printf("0");
        else
            printf("1");
        num <<= 1; // Shift num to get next bit
    }
    printf("\n");
}

int main()
{
    // Example program to demonstrate bitwise operations in C
    
    // Bitwise AND
    unsigned int and_result = 14 & 7;
    printf("14 & 7 = %d\n", and_result);

    // Bitwise OR
    unsigned int or_result = 14 | 7;
    printf("14 | 7 = %d\n", or_result);

    // Bitwise XOR
    unsigned int xor_result = 14 ^ 7;
    printf("14 ^ 7 = %d\n", xor_result);

    // Bitwise NOT
    unsigned int not_num = 14;
    unsigned int not_result = ~not_num; 
    printf("~14 = %d\n", not_result);
    
    // Left shift
    unsigned int left_num = 7;
    unsigned int left_shift_result = left_num << 3; // 7 * 2^3
    printf("7 << 3 = %d\n", left_shift_result);

    // Right shift
    unsigned int right_num = 7;
    unsigned int right_shift_result = right_num >> 2; // 7 / 2^2
    printf("7 >> 2 = %d\n", right_shift_result);
    
    // Bitwise AND with mask
    unsigned int num = 0b110101101; // 437
    unsigned int mask = 0b111100000; // 496
    unsigned int masked_result = num & mask;
    printf("num & mask = ");
    printBits(masked_result); // should print 0b110100000 (416)
    
    return 0;
}