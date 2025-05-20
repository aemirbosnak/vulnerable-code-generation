//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    char option; 
    int num, result; 
    char hex[10]; 

    do { 

        printf("Select an option \n"); 
        printf("1. Convert Hexadecimal to Decimal \n"); 
        printf("2. Convert Decimal to Hexadecimal \n"); 
        scanf("%c", &option); 

        switch(option) 
        { 
            case '1': 
                printf("Enter a hexadecimal number: "); 
                scanf("%s", hex); 
                result = convertHex(hex, num); 
                printf("Decimal equivalent of %s is %d \n", hex, result); 
                break; 

            case '2': 
                printf("Enter a decimal number: "); 
                scanf("%d", &num); 
                result = convertDec(num, hex); 
                printf("Hexadecimal equivalent of %d is %s \n", num, hex); 
                break; 

            default: 
                printf("Invalid option selected!\n"); 
        } 

        printf("Do you want to continue? (y/n) "); 
        scanf("%c", &option); 
    } while(option == 'y'); 

    return 0; 
} 

int convertHex(char *hex, int *num) 
{ 
    *num = 0; 

    for(int i=0; i<strlen(hex); i++) 
    { 
        if(hex[i] >= '0' && hex[i] <= '9') 
        { 
            *num = (*num)*16 + hex[i] - '0'; 
        } 
        else if(hex[i] >= 'a' && hex[i] <= 'f') 
        { 
            *num = (*num)*16 + hex[i] - 'a' + 10; 
        } 
        else if(hex[i] >= 'A' && hex[i] <= 'F') 
        { 
            *num = (*num)*16 + hex[i] - 'A' + 10; 
        } 
        else 
        { 
            printf("Invalid character in input!"); 
            return 1; 
        } 
    } 

    return 0; 
} 

int convertDec(int dec, char *hex) 
{ 
    int i, j; 
    int digit; 

    for(i=0; dec!=0; i++) 
    { 
        digit = dec%16; 

        if(digit < 10) 
        { 
            *(hex+i) = digit + '0'; 
        } 
        else if(digit < 16) 
        { 
            *(hex+i) = digit + 'a'-10; 
        } 
        else if(digit < 26) 
        { 
            *(hex+i) = digit + 'A'-10; 
        } 
        else 
        { 
            printf("Invalid input!"); 
            return 1; 
        } 

        dec /= 16; 
    } 

    return 0; 
}