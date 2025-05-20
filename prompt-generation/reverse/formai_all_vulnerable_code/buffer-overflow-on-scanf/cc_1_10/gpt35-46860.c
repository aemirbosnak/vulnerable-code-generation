//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>

// Hex to Decimal conversion function
int hexToDec(char hex[]) {
    int dec = 0, base = 1, i;
    int len = strlen(hex);
    
    for(i = len-1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return dec;
}

// Decimal to Hex conversion function
void decToHex(int dec) {
    int i = 0, remainder;
    char hex[20];
    
    while(dec != 0) {
        remainder = dec % 16;
        if(remainder < 10)
            hex[i] = remainder + 48;
        else
            hex[i] = remainder + 55;
        i++;
        dec /= 16;
    }
    printf("Hexadecimal equivalent: ");
    for(i = i-1; i >= 0; i--)
        printf("%c", hex[i]);
}

int main() {
    char hex[20];
    int choice, decimal;
    
    printf("\n=================== HEXADECIMAL CONVERTER ===================\n");
    
    // Menu
    printf("\n1. Convert Hexadecimal to Decimal\n");
    printf("2. Convert Decimal to Hexadecimal\n");
    printf("3. Exit\n");
    printf("\nEnter your choice (1/2/3): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nEnter a Hexadecimal Number: ");
            scanf("%s", hex);
            decimal = hexToDec(hex);
            printf("Decimal equivalent: %d", decimal);
            break;
            
        case 2:
            printf("\nEnter a Decimal Number: ");
            scanf("%d", &decimal);
            decToHex(decimal);
            break;
            
        case 3:
            exit(0); // Exit the program
            
        default:
            printf("\nInvalid Choice");
    }
    
    printf("\n\n=========== THANK YOU FOR USING HEXADECIMAL CONVERTER ===========\n");
    
    return 0;
}