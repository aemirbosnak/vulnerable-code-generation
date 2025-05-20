//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hex[17], ascii[16], binary[65] = {'\0'};
    int decimal, i, length;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    // convert hexadecimal to decimal
    decimal = 0;
    length = strlen(hex);
    for(i = 0; i < length; i++) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * (int) pow(16, length - i - 1);
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * (int) pow(16, length - i - 1);
        } else {
            printf("Invalid input.\n");
            return 1;
        }
    }
    
    // convert decimal to binary
    int j = 0;
    while(decimal > 0) {
        binary[j++] = decimal % 2 + '0';
        decimal /= 2;
    }
    
    // reverse binary string
    int k = 0;
    char temp;
    while(k < j - 1) {
        temp = binary[k];
        binary[k] = binary[j - 1];
        binary[j - 1] = temp;
        k++;
        j--;
    }
    
    // convert binary to ASCII
    length = strlen(binary);
    for(i = 0; i < length; i += 8) {
        memcpy(ascii + i / 8, binary + i, 8);
        ascii[i / 8 + 1] = '\0';
    }
    
    // output results
    printf("Hexadecimal input: %s\n", hex);
    printf("Decimal output: %d\n", decimal);
    printf("Binary output: %s\n", binary);
    printf("ASCII output: %s\n", ascii);
    
    return 0;
}