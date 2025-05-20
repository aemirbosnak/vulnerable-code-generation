//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include<stdio.h>

int hex_to_dec(char hex[]) { //function to convert hexadecimal to decimal
    int i, decimal = 0;
    
    for(i=0; hex[i]!='\0'; i++) {
        if(hex[i]>='0' && hex[i]<='9') {
            decimal = decimal * 16 + (hex[i] - '0');
        }
        else if(hex[i]>='A' && hex[i]<='F') {
            decimal = decimal * 16 + (hex[i] - 'A' + 10);
        }
        else if(hex[i]>='a' && hex[i]<='f') {
            decimal = decimal * 16 + (hex[i] - 'a' + 10);
        }
    }
    
    return decimal;
}

int dec_to_hex(int decimal) { //function to convert decimal to hexadecimal
    int i=1, hex=0, remainder; 
    
    while(decimal!=0) {
        remainder = decimal % 16;
        decimal = decimal / 16;
        hex = hex + remainder * i;
        i = i * 10;
    }
    
    return hex;
}

int main() {
    char hex[20];
    int decimal;
    
    printf("Enter a hexadecimal number:\n");
    scanf("%s", hex);
    
    decimal = hex_to_dec(hex);
    
    printf("In decimal: %d\n", decimal);
    printf("In hexadecimal: %X\n", decimal); //%X formats the output as hexadecimal representation
    
    printf("Enter a decimal number:\n");
    scanf("%d", &decimal);
    
    printf("In hexadecimal: %X\n", dec_to_hex(decimal)); //%X formats the output as hexadecimal representation
    
    return 0;
}