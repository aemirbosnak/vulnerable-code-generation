//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <string.h>

int hexadecimalToDecimal(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;
   
    for (int i = len - 1; i >= 0; i--) {
		
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
	else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}

void decimalToHexadecimal(int decimal) {
    int remainder, i = 0;
    char hexadecimal[100];
 
    while(decimal != 0) {
        remainder = decimal % 16;
        if(remainder < 10) {
            hexadecimal[i] = remainder + 48;
            i++;
        }
        else {
            hexadecimal[i] = remainder + 55;
            i++;
        }
        decimal /= 16;
    }
 
    printf("\nHexadecimal Number: ");
    for(int j=i-1; j>=0; j--)
        printf("%c", hexadecimal[j]);
}
 
int main() {
    char hex[100];
    int decimal;
     
    printf("Enter Hexadecimal Number: ");
    scanf("%s",hex);
     
    decimal = hexadecimalToDecimal(hex);
    printf("Decimal Number: %d\n", decimal);
 
    decimalToHexadecimal(decimal);
    return 0;
}