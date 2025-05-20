//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <string.h>

/* Function to convert hexadecimal to decimal */
int hexToDecimal(char hex[]) {
    int decimal = 0, base = 1, len = strlen(hex), i;
    for(i = len - 1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
        }
        base *= 16;
    }
    return decimal;
}

/* Function to convert decimal to hexadecimal */
void decimalToHex(int decimal) {
    int rem, i = 0;
    char hexadecimal[50];
    while(decimal > 0) {
        rem = decimal % 16;
        if(rem < 10) {
            hexadecimal[i++] = rem + 48;
        }
        else {
            hexadecimal[i++] = rem + 55;
        }
        decimal /= 16;
    }
    printf("The hexadecimal value = ");
    for(i = i - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

int main() {
    char hex[50];
    int decimal;
    printf("Enter hexadecimal value: ");
    scanf("%s", hex);
    decimal = hexToDecimal(hex);
    printf("The decimal value = %d\n", decimal);
    decimalToHex(decimal);
    return 0;
}