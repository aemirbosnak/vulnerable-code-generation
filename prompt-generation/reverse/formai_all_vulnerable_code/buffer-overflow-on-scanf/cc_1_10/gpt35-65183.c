//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToDec(char* hex);
void decToHex(int dec);

int main() {
    char choice;
    char hex[100];
    int dec;
    
    printf("*** HEXADECIMAL CONVERTER ***\n\n");
    printf("Enter 'H' to convert from hexadecimal to decimal.\n");
    printf("Enter 'D' to convert from decimal to hexadecimal.\n");
    printf("Enter 'Q' to quit.\n");
    
    do {
        printf("\nChoice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case 'H':
            case 'h':
                printf("Enter hexadecimal number: ");
                scanf("%s", hex);
                hexToDec(hex);
                break;
            case 'D':
            case 'd':
                printf("Enter decimal number: ");
                scanf("%d", &dec);
                decToHex(dec);
                break;
            case 'Q':
            case 'q':
                printf("\nExiting...");
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    } while (choice != 'Q' && choice != 'q');
    
    return 0;
}

void hexToDec(char* hex) {
    int len = strlen(hex);
    int dec = 0;
    int base = 1;
    int i;
    
    for (i = len-1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
        } else {
            printf("\nInvalid hexadecimal format.");
            return;
        }
        base *= 16;
    }
    
    printf("\nDecimal representation of %s is %d.", hex, dec);
}

void decToHex(int dec) {
    char hex[100];
    int i = 0;
    
    while (dec != 0) {
        int remainder = dec % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48;
        } else {
            hex[i] = remainder + 55;
        }
        i++;
        dec /= 16;
    }
    
    if (i == 0) {
        printf("\nDecimal representation of 0 is 0.");
        return;
    }
    
    hex[i] = '\0';
    
    printf("\nHexadecimal representation of %d is ", dec);
    for (i = strlen(hex)-1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
}