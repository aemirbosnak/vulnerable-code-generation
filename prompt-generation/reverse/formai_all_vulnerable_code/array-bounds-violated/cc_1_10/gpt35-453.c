//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>

// function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    int remainder, quotient;
    char hex[17] = "0123456789ABCDEF";
    char hexadecimal[100];
    int i = 0;
    
    quotient = decimal;
    
    while(quotient != 0) {
        remainder = quotient % 16;
        hexadecimal[i++] = hex[remainder];
        quotient /= 16;
    }
    
    // printing the hexadecimal value
    printf("The hexadecimal value is: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

// function to convert hexadecimal to decimal
void hexadecimalToDecimal(char hex[]) {
    int decimal = 0, base = 1;
    int length = strlen(hex);
    
    for(int i = length - 1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    
    // printing the decimal value
    printf("The decimal value is: %d\n", decimal);
}

int main() {    
    char choice;
    
    do {
        int decimal;
        char hex[100];
        printf("Enter your choice:\n");
        printf("1. Decimal to hexadecimal conversion.\n");
        printf("2. Hexadecimal to decimal conversion.\n");
        printf("3. Exit.\n");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                printf("Enter the decimal number: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                break;
            
            case '2':
                printf("Enter the hexadecimal number: ");
                scanf("%s", hex);
                hexadecimalToDecimal(hex);
                break;
            
            case '3':
                printf("Exiting the program...\n");
                exit(0);
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while(choice != '3');
    
    return 0;
}