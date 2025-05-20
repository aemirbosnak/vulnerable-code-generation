//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lovePoem() {
    printf("Oh sweet heart, behold my love,\n");
    printf("In a realm where numbers dance and twirl,\n");
    printf("Let us embark on a journey, hand in hand,\n");
    printf("To conquer the depths of hexadecimal, my pearl.\n\n");
}

void decimalToHexadecimal(int decimal, char result[]) {
    char hexChars[] = "0123456789ABCDEF";
    int i = 0;

    if (decimal == 0) {
        result[i++] = '0';
    }
    
    while (decimal > 0) {
        result[i++] = hexChars[decimal % 16];
        decimal /= 16;
    }

    result[i] = '\0'; // Null terminate the string

    // Reverse the string for correct order
    for (int j = 0; j < i / 2; ++j) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }
}

void loveMessage() {
    printf("Let your heart pour out its decimal figure,\n");
    printf("And together we shall turn it to hex with glee,\n");
    printf("For just like love, it's a wondrous mixture,\n");
    printf("With each character filled with sweet mystery.\n\n");
}

void showResult(int decimal, char hex[]) {
    printf("In this enchanting realm, your decimal is: %d\n", decimal);
    printf("And your hexadecimal is: %s\n", hex);
}

int main() {
    char hexResult[20]; // Array to hold the hexadecimal result
    int decimalNumber;

    lovePoem();
    loveMessage();

    printf("Please enter a decimal number that your heart desires: ");
    scanf("%d", &decimalNumber);

    decimalToHexadecimal(decimalNumber, hexResult);
    showResult(decimalNumber, hexResult);

    printf("\nMay your heart forever be a flowing stream,\n");
    printf("And in every conversion, let love's light beam.\n");
    printf("On this journey where numbers transcend,\n");
    printf("Let us embrace the magic that never shall end.\n");

    return 0;
}