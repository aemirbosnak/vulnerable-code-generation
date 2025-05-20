//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binaryToDecimal(char *binary){
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    // Iterate through the binary string from right to left
    for(int i = length - 1; i >= 0; i--){
        // If the current character is '1', add 2^power to the decimal value
        if(binary[i] == '1'){
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal){
    char binary[33];
    int i = 0;

    // Iterate through the decimal value, adding the appropriate binary digit to the string
    while(decimal > 0){
        if(decimal % 2 == 0){
            strcat(binary, "0");
        }
        else{
            strcat(binary, "1");
        }
        decimal /= 2;
        i++;
    }

    // Reverse the binary string
    for(int j = 0; j < i/2; j++){
        char temp = binary[j];
        binary[j] = binary[i-1-j];
        binary[i-1-j] = temp;
    }

    // Print the binary string
    printf("Binary: %s\n", binary);
}

int main(){
    char input[33];

    // Prompt the user for input
    printf("Enter a binary number: ");
    scanf("%s", input);

    // Convert the binary string to decimal
    int decimal = binaryToDecimal(input);

    // Print the decimal value
    printf("Decimal: %d\n", decimal);

    // Convert the decimal value to binary
    decimalToBinary(decimal);

    return 0;
}