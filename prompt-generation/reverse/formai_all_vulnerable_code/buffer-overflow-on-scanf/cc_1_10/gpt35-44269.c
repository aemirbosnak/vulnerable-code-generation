//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    
    for (int i=len-1; i>=0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    
    return dec;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec) {
    char hex[100];
    int remainder,quotient;
    quotient = dec; 
    int i=0;
    
    while(quotient != 0) {
         remainder = quotient % 16;
         
         if(remainder < 10)
            hex[i++] = 48 + remainder;
         else
            hex[i++] = 55 + remainder;
            
         quotient = quotient / 16;
    }
    
    // Printing hexadecimal number array in reverse order
    for(int j=i-1; j>=0; j--)
        printf("%c", hex[j]);
}

int main() {
    int choice;
    char hex[100];
    
    do {
        // User menu
        printf("\n Choose an option:\n");
        printf("1. Convert hexadecimal to decimal.\n");
        printf("2. Convert decimal to hexadecimal.\n");
        printf("3. Quit.\n");
        printf("Enter an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
            {
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                
                int dec = hexToDec(hex);
                printf("Decimal: %d\n", dec);
                break;
            }
            
            case 2:
            {
                int dec;
                printf("Enter a decimal number: ");
                scanf("%d", &dec);
                
                printf("Hexadecimal: ");
                decToHex(dec);
                printf("\n");
                break;
            }
            
            case 3:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid option selected.\n");
        }
    } while(choice != 3);
    
    return 0;
}