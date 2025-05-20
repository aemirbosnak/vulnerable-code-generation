//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[33]; //Maximum 32 bit binary number + null terminator
    int i = 0;
    while(decimal > 0) {
        binary[i++] = (decimal % 2) + '0'; //Add remainder to binary string
        decimal /= 2; //Divide decimal by 2
    }
    binary[i] = '\0'; //Add null terminator
    printf("Binary representation: %s\n", binary);
}

//Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0, power = 0;
    while(*binary) {
        if(*binary == '1') {
            decimal += pow(2, power); //Add 2^power to decimal if bit is 1
        }
        power++; //Increment power for next bit
        binary++; //Move to next character in binary string
    }
    return decimal;
}

//Function to convert binary to hexadecimal
void binaryToHexadecimal(char* binary) {
    char hexadecimal[9]; //Maximum 32 bit hexadecimal number + null terminator
    int i = 0;
    while(*binary) {
        sprintf(&hexadecimal[i], "%02X", *(unsigned char*)binary); //Convert 4 bits of binary to hexadecimal
        i += 2; //Move to next 2 characters in hexadecimal string
        binary++; //Move to next character in binary string
    }
    hexadecimal[i] = '\0'; //Add null terminator
    printf("Hexadecimal representation: %s\n", hexadecimal);
}

//Main function
int main() {
    int decimal;
    char binary[33];
    char hexadecimal[9];

    //Prompt user for decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    //Convert decimal to binary
    decimalToBinary(decimal);

    //Convert decimal to binary string
    sprintf(binary, "%d", decimal);

    //Convert binary to decimal
    int decimalResult = binaryToDecimal(binary);
    printf("Decimal representation: %d\n", decimalResult);

    //Convert binary to hexadecimal
    binaryToHexadecimal(binary);

    return 0;
}