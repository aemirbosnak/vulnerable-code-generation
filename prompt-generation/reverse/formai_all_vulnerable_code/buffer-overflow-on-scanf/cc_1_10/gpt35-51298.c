//FormAI DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// function to validate user input
int validate_input(char input[]) {
    // loop through each character in input
    for (int i = 0; input[i] != '\0'; i++) {
        // if character is not 0 or 1, return an error code
        if (input[i] != '0' && input[i] != '1') {
            return 0;
        }
    }
    // return success code if input is valid
    return 1;
}

// function to convert binary to decimal
int binary_to_decimal(char binary[]) {
    // validate binary input
    if (!validate_input(binary)) {
        printf("Invalid binary input\n");
        return 0;
    }
    // initialize decimal variable to store result
    int decimal = 0;
    // loop through each character in binary input
    for (int i = 0; binary[i] != '\0'; i++) {
        // multiply decimal by 2 and add the current binary digit
        decimal *= 2;
        decimal += binary[i] - '0';
    }
    // return decimal result
    return decimal;
}

// function to convert binary to hex
char *binary_to_hex(char binary[]) {
    // validate binary input
    if (!validate_input(binary)) {
        printf("Invalid binary input\n");
        return NULL;
    }
    // initialize hex string to store result
    char *hex = (char*) malloc(3 * sizeof(char));
    // convert binary to decimal
    int decimal = binary_to_decimal(binary);
    // convert decimal to hex
    sprintf(hex, "%02X", decimal);
    // return hex result
    return hex;
}

int main() {
    // get binary input from user
    char binary[100];
    printf("Enter a binary value: ");
    scanf("%s", binary);
    
    // convert binary to decimal and print result
    int decimal = binary_to_decimal(binary);
    printf("Decimal value: %d\n", decimal);
    
    // convert binary to hex and print result
    char *hex = binary_to_hex(binary);
    printf("Hex value: 0x%s\n", hex);
    free(hex);
    
    return 0;
}