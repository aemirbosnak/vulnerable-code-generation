//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
//Ada Lovelace style C Binary Converter program

#include <stdio.h>

//function to convert decimal to binary
void decToBin(int decimal)  
{  
    int binary[32];  
    int index = 0;  
      
    //converting decimal to binary 
    while(decimal > 0)  
    {  
        binary[index] = decimal % 2;  
        decimal = decimal / 2;  
        index++;  
    }  
      
    //print binary number in reverse order  
    for(int i=index-1; i>=0; i--)  
    {  
        printf("%d", binary[i]);  
    }  
}  

//function to convert binary to decimal  
int binToDec(long long binary)  
{  
    int decimal = 0;  
    int index = 0;  
    int remainder;  
      
    //converting binary to decimal  
    while(binary != 0)  
    {  
        remainder = binary % 10;  
        binary = binary / 10;  
        decimal = decimal + remainder * pow(2,index);  
        index++;  
    }  
      
    return decimal;  
}  

int main()  
{  
    int choice, decimal;  
    long long binary;  
      
    printf("Welcome to the Ada Lovelace Style Binary Converter Program!\n");  
      
    //menu for user to choose conversion type  
    printf("\nPlease choose the conversion type:\n");  
    printf("1. Decimal to Binary Conversion\n");  
    printf("2. Binary to Decimal Conversion\n");  
    scanf("%d", &choice);  
      
    switch(choice)  
    {  
        case 1: printf("\nEnter the decimal number: ");  
                scanf("%d", &decimal);  
                printf("The binary equivalent is: ");  
                decToBin(decimal);  
                break;  
              
        case 2: printf("\nEnter the binary number: ");  
                scanf("%lld", &binary);  
                printf("The decimal equivalent is: %d", binToDec(binary));  
                break;  
              
        default: printf("\nInvalid choice!");  
                 break;  
    }  
      
    printf("\nThank you for using the Ada Lovelace Style Binary Converter Program. Goodbye!");  
      
    return 0;  
}