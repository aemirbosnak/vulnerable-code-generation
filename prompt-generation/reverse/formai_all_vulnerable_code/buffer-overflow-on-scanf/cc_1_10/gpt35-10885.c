//FormAI DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include<stdio.h> 

// Function to display binary representation of an integer 
void binary(int num) 
{ 
    int rem=0,binary=0,power=1; 
    while(num>0) 
    { 
        rem=num%2; 
        binary=rem*power+binary; 
        num=num/2; 
        power=power*10; 
    } 
    printf("Binary Representation: %d\n", binary); 
} 

// Function to clear a bit 
void clearBit(int *num, int bitPosition) 
{ 
    int mask = ~(1<<bitPosition); 
    *num &= mask; 
    printf("After clearing %d bit, the integer is: %d\n", bitPosition, *num); 
} 

// Function to set a bit 
void setBit(int *num, int bitPosition) 
{ 
    int mask = (1<<bitPosition); 
    *num |= mask; 
    printf("After setting %d bit, the integer is: %d\n", bitPosition, *num); 
} 

// Function to toggle a bit 
void toggleBit(int *num, int bitPosition) 
{ 
    int mask = (1<<bitPosition); 
    *num ^= mask; 
    printf("After toggling %d bit, the integer is: %d\n", bitPosition, *num); 
} 

// Function to check if a bit is set or not 
void isBitSet(int num, int bitPosition) 
{ 
    int mask = (1<<bitPosition); 
    if(num & mask) 
        printf("Bit %d is set\n", bitPosition); 
    else
        printf("Bit %d is not set\n", bitPosition); 
} 

// Function to perform bitwise AND operation 
void bitwiseAnd(int num1, int num2) 
{ 
    int result = num1 & num2; 
    printf("Result of bitwise AND operation is: %d\n", result); 
} 

// Function to perform bitwise OR operation 
void bitwiseOr(int num1, int num2) 
{ 
    int result = num1 | num2; 
    printf("Result of bitwise OR operation is: %d\n", result); 
} 

// Function to perform bitwise XOR operation 
void bitwiseXor(int num1, int num2) 
{ 
    int result = num1 ^ num2; 
    printf("Result of bitwise XOR operation is: %d\n", result); 
} 

int main() 
{ 
    int num1,num2,bitPosition; 
    
    // Taking input of two numbers 
    printf("Enter two integers: "); 
    scanf("%d%d",&num1,&num2); 
    
    // Displaying the binary representation of both numbers 
    printf("Binary representation of first number: "); 
    binary(num1); 
    printf("Binary representation of second number: "); 
    binary(num2); 
    
    // Clearing the 3rd bit of first number 
    clearBit(&num1,3); 
    
    // Setting the 2nd bit of second number 
    setBit(&num2,2); 
    
    // Toggling the 5th bit of first number 
    toggleBit(&num1,5); 
    
    // Checking if the 4th bit of second number is set or not 
    isBitSet(num2,4); 
    
    // Bitwise AND operation 
    bitwiseAnd(num1,num2); 
    
    // Bitwise OR operation 
    bitwiseOr(num1,num2); 
    
    // Bitwise XOR operation 
    bitwiseXor(num1,num2); 
    
    return 0; 
}