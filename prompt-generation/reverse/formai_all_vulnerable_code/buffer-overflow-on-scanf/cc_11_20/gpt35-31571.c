//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
    char hex[17];
    int decimal, i, j, remainder;
    
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    decimal = 0;
    j = 0;
    for(i = strlen(hex) - 1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * (int) pow(16, j);
            j++;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * (int) pow(16, j);
            j++;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * (int) pow(16, j);
            j++;
        }
        else {
            printf("Invalid input. Exiting program.");
            return 0;
        }
    }
    
    printf("The decimal equivalent of %s is %d\n", hex, decimal);
    
    printf("Converting back to hexadecimal...\n");
    
    char hex_reversed[17];
    i = 0;
    while(decimal != 0) {
        remainder = decimal % 16;
        if(remainder < 10) {
            hex_reversed[i] = remainder + 48;
        }
        else {
            hex_reversed[i] = remainder + 55;
        }
        decimal /= 16;
        i++;
    }
    hex_reversed[i] = '\0';
    
    printf("The hexadecimal equivalent of %d is ", decimal);
    
    for(i = strlen(hex_reversed) - 1; i >= 0; i--) {
        printf("%c", hex_reversed[i]);
    }
    printf("\n");
    
    return 0;
}