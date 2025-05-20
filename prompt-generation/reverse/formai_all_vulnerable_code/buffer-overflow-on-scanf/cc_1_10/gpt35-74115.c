//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

/* Donald Knuth Style C Color Code Converter Program */

int hexToDec(char hex);
char decToHex(int decimal);
int pow(int base, int exponent);

int main() {
    char hexColor[7];
    int red, green, blue;
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hexColor);
    printf("\n");
    red = hexToDec(hexColor[0]) * 16 + hexToDec(hexColor[1]);
    green = hexToDec(hexColor[2]) * 16 + hexToDec(hexColor[3]);
    blue = hexToDec(hexColor[4]) * 16 + hexToDec(hexColor[5]);
    printf("The RGB values for #%s are: %d, %d, %d\n", hexColor, red, green, blue);
    printf("\n");

    int choice;
    printf("Would you like to convert the RGB values to hexadecimal? (Enter 1 for Yes, 0 for No) ");
    scanf("%d", &choice);
    printf("\n");
    if(choice == 1){
        char redHex[2], greenHex[2], blueHex[2];
        redHex[0] = decToHex(red / 16);
        redHex[1] = decToHex(red % 16);
        greenHex[0] = decToHex(green / 16);
        greenHex[1] = decToHex(green % 16);
        blueHex[0] = decToHex(blue / 16);
        blueHex[1] = decToHex(blue % 16);
        printf("The hexadecimal color code for %d, %d, %d is #%s%s%s", red, green, blue, redHex, greenHex, blueHex);
        printf("\n");
    }
    else{
        printf("Thank you for using the Color Code Converter!\n");
    }
    return 0;
}

/* Function to convert hexadecimal digits to decimal */
int hexToDec(char hex) {
    if(hex >= '0' && hex <= '9'){
        return (int)hex - 48;
    }
    else{
        return (int)hex - 55;
    }
}

/* Function to convert decimal numbers to hexadecimal digits */
char decToHex(int decimal) {
    if(decimal < 10){
        return (char)(decimal + 48);
    }
    else{
        return (char)(decimal + 55);
    }
}

/* Function to find the power of a number using recursion */
int pow(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    else{
        return base * pow(base, exponent - 1);
    }
}