//FormAI DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h> 

// function to convert decimal to binary 
int decimalToBinary(int decimal) 
{ 
    int binary = 0; 
    int multiplier = 1; 
    
    while (decimal > 0) 
    { 
        binary += (decimal % 2) * multiplier; 
        decimal /= 2; 
        multiplier *= 10; 
    } 
    
    return binary; 
} 

// function to convert binary to decimal 
int binaryToDecimal(int binary) 
{ 
    int decimal = 0; 
    int base = 1;
    
    while (binary > 0) 
    { 
        int lastDigit = binary % 10; 
        binary /= 10; 
        decimal += lastDigit * base; 
        base *= 2; 
    } 
    
    return decimal; 
} 

// function to print the binary equivalent of a decimal number 
void printBinary(int decimal) 
{ 
    int binary = decimalToBinary(decimal); 
    printf("The binary equivalent of %d is %d.\n\n", decimal, binary); 
} 

// function to print the decimal equivalent of a binary number 
void printDecimal(int binary) 
{ 
    int decimal = binaryToDecimal(binary); 
    printf("The decimal equivalent of %d is %d.\n\n", binary, decimal); 
} 

int main() 
{ 
    printf("Welcome to the Binary Converter!\n\n"); 
    printf("Please select an option:\n"); 
    printf("1. Convert decimal to binary\n"); 
    printf("2. Convert binary to decimal\n"); 
    printf("3. Exit\n"); 
    
    int choice = 0; 

    while (choice != 3) 
    { 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 

        switch (choice) 
        { 
            case 1: 
                printf("\nEnter the decimal number: "); 
                int decimal; 
                scanf("%d", &decimal); 
                printBinary(decimal); 
                break; 
                
            case 2: 
                printf("\nEnter the binary number: "); 
                int binary; 
                scanf("%d", &binary); 
                printDecimal(binary); 
                break; 
                
            case 3: 
                printf("\nThank you for using the Binary Converter!\n"); 
                break; 
                
            default: 
                printf("\nInvalid choice. Please try again.\n"); 
                break; 
        } 
    } 
    
    return 0; 
}