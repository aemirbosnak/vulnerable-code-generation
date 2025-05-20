//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec_val = 0;
    
    for(int i = len - 1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            dec_val += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            dec_val += (hex[i] - 87) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            dec_val += (hex[i] - 55) * base;
            base *= 16;
        }
        else {
            printf("\nInvalid Hexadecimal Number!\n\n");
            exit(0);
        }
    }
    
    printf("\nThe Decimal Value of Hexadecimal Number %s is : %d\n\n", hex, dec_val);
}

void decToHex(int dec) {
    char hex[17];
    int i = 0;
    
    while(dec != 0) {
        int rem = dec % 16;
        if(rem < 10) {
            hex[i] = rem + 48;
            i++;
        }
        else {
            hex[i] = rem + 55;
            i++;
        }
        dec /= 16;
    }
    
    printf("\nThe Hexadecimal Value of Decimal Number %d is : ", dec);
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n\n");
}

int main() {
    int choice;
    while(1) {
        printf("Select an Option\n");
        printf("1. Hexadecimal to Decimal Conversion\n");
        printf("2. Decimal to Hexadecimal Conversion\n");
        printf("3. Quit\n");
        
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter a Hexadecimal Number (0-9 or A-F) : ");
                char hex[20];
                scanf("%s", hex);
                hexToDec(hex);
                break;
            case 2:
                printf("\nEnter a Decimal Number : ");
                int dec;
                scanf("%d", &dec);
                decToHex(dec);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid Option!\n\n");
        }
    }
}