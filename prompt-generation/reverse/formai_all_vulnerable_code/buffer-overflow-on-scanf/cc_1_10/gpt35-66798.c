//FormAI DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hexVal[]) {

    int len = strlen(hexVal);
    int base = 1;
    int decVal = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            decVal += (hexVal[i] - 48) * base;
            base = base * 16;
        }
        else if (hexVal[i] >= 'a' && hexVal[i] <= 'f') {
            decVal += (hexVal[i] - 87) * base;
            base = base * 16;
        }
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            decVal += (hexVal[i] - 55) * base;
            base = base * 16;
        }
    }
    return decVal;
}

// Function to convert decimal to hexadecimal
void decToHex(int n, char hexVal[]) {

    int i = 0;
    while (n != 0) {
        int temp = 0;

        temp = n % 16;

        if (temp < 10) {
            hexVal[i] = temp + 48;
            i++;
        }
        else {
            hexVal[i] = temp + 55;
            i++;
        }

        n = n / 16;
    }

    // Making hexadecimal number reverse
    for (int j = 0; j < i / 2; j++) {
        char temp = hexVal[j];
        hexVal[j] = hexVal[i - j - 1];
        hexVal[i - j - 1] = temp;
    }
}

int main() {

    char hexColor[7];
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hexColor);

    if (strlen(hexColor) != 6) {
        printf("Invalid input. Please enter a 6-digit hexadecimal color code.\n");
        exit(0);
    }

    // Splitting hex color code into RGB format
    char hexSubstr[3];
    int decSubstr;
    char rgb[3][4];
    for (int i = 0, j = 0; i < 6; i += 2, j++) {
        strncpy(hexSubstr, &hexColor[i], 2);
        decSubstr = hexToDec(hexSubstr);
        decToHex(decSubstr, rgb[j]);
    }

    // Formatting RGB color code
    printf("The RGB color code is: ");
    for (int i = 0; i < 3; i++) {
        printf("%s", rgb[i]);
        if (i != 2) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}