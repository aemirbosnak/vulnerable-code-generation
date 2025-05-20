//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert decimal to hexadecimal
void decimalToHex(int decimal) {
    char hex[10];
    int i = 0;
    
    while(decimal != 0) {
        int remainder = decimal % 16;
        
        if (remainder < 10) {
            hex[i] = remainder + 48;
            i++;
        } else {
            hex[i] = remainder + 55;
            i++;
        }
        
        decimal /= 16;
    }
    
    printf("Hexadecimal equivalent: ");
    
    for(int j = i-1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    
    printf("\n");
}

// Convert hexadecimal to decimal
void hexToDecimal(char hex[]) {
    int decimal = 0;
    int length = strlen(hex);
    int base = 1;
    
    for(int i = length-1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    
    printf("Decimal equivalent: %d\n", decimal);
}

int main() {
    int choice;
    
    do {
        printf("********** MENU **********\n");
        printf("1. Convert decimal to hexadecimal\n");
        printf("2. Convert hexadecimal to decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                printf("Enter decimal number: ");
                int decimal;
                scanf("%d", &decimal);
                decimalToHex(decimal);
                getchar();
                break;
            case 2:
                printf("Enter hexadecimal number: ");
                char hex[10];
                gets(hex);
                hexToDecimal(hex);
                break;
            case 3:
                printf("Thanks for using the program!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);
    
    return 0;
}