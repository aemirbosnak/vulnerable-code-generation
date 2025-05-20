//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>

// function prototypes
void decToHex(int num);
int hexToDec(char hex);

int main() {
    int num;
    char hex;
    
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    
    printf("Decimal to hexadecimal: 0x");
    decToHex(num);
    
    printf("\nEnter a hexadecimal number: ");
    scanf(" %c", &hex);
    
    printf("Hexadecimal to decimal: %d\n", hexToDec(hex));
    
    return 0;
}

// function to convert decimal to hexadecimal
void decToHex(int num) {
    int rem, i = 0;
    char hex[50];
    
    while(num != 0) {
        rem = num % 16;
        if(rem < 10) {
            hex[i] = rem + 48;
        }
        else {
            hex[i] = rem + 55;
        }
        i++;
        num = num / 16;
    }
    
    for(int j = i-1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

// function to convert hexadecimal to decimal
int hexToDec(char hex) {
    if(hex >= '0' && hex <= '9') {
        return hex - '0';
    }
    else if(hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
    else if(hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    }
    else {
        printf("Invalid hexadecimal input!");
        return -1;
    }
}