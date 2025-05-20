//FormAI DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

void binaryToDecimal(){
    char binary[MAX_LENGTH];
    int decimal = 0, power = 1, i, n;
    
    printf("Enter the binary number: ");
    scanf("%s", binary);
    
    n = strlen(binary);
    for(i = n-1; i >= 0; i--){
        if(binary[i] == '1')
            decimal += power;
        power *= 2;
    }
    
    printf("Decimal equivalent of %s is %d\n\n", binary, decimal);
}

void decimalToBinary(){
    int decimal, binary[MAX_LENGTH], quotient, i=0, j;
    
    printf("Enter the decimal number: ");
    scanf("%d", &decimal);
    
    quotient = decimal;
    while(quotient !=0 ){
        binary[i++] = quotient % 2;
        quotient = quotient / 2;
    }
    
    printf("Binary equivalent of %d is ", decimal);
    for(j = i-1; j >= 0; j--)
        printf("%d",binary[j]);
    printf("\n\n");
}

int main(){
    int choice;
    
    printf("Welcome to Binary Converter\n");
    printf("---------------------------\n");
    printf("1. Binary to Decimal Conversion\n");
    printf("2. Decimal to Binary Conversion\n");
    printf("3. Exit\n\n");
    
    do{
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                binaryToDecimal();
                break;
            case 2:
                decimalToBinary();
                break;
            case 3:
                printf("Thank you for using Binary Converter!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }while(choice != 3);
    
    return 0;
}