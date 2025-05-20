//FormAI DATASET v1.0 Category: Binary Converter ; Style: random
#include<stdio.h>
#include<string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal){
    int binary[32], i = 1, j;
    
    // Store Remainders in Array
    while(decimal != 0){
        binary[i++] = decimal % 2; 
        decimal /= 2;
    }
    
    // Print Binary Value
    printf("\nBinary Value: ");
    for(j = i - 1; j > 0; j--){
        printf("%d", binary[j]);
    }
}

// Function to convert binary to decimal
void binaryToDecimal(char binary[]){
    int decimal = 0, i, j, power = 1;
    int len = strlen(binary);
    
    // Calculate Decimal Value
    for(i = len - 1; i >= 0; i--){
        if(binary[i] == '1'){
            decimal += power;
        }
        power *= 2;
    }
    
    // Print Decimal Value
    printf("\nDecimal Value: %d", decimal);
}

int main(){
    int choice, decimal;
    char binary[100];
    
    printf("========= BINARY CONVERTER ==========\n\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: printf("\nEnter Decimal Number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;
                
        case 2: printf("\nEnter Binary Number: ");
                scanf("%s", &binary);
                binaryToDecimal(binary);
                break;
                
        default: printf("\nInvalid Choice\n");
    }
    
    return 0;
}