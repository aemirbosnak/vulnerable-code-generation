//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function to check if input is a valid binary string
int is_binary(char* input) {
    int i = 0;
    while (input[i]!= '\0') {
        if (input[i]!= '0' && input[i]!= '1') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int i = strlen(binary) - 1;
    
    while (i >= 0) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
        i--;
    }
    
    return decimal;
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[MAX_INPUT_SIZE];
    int i = 0;
    
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            strcat(binary, "0");
        } else {
            strcat(binary, "1");
        }
        decimal /= 2;
        i++;
    }
    
    printf("%s\n", binary);
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter a binary number: ");
    scanf("%s", input);
    
    if (is_binary(input)) {
        int decimal = binary_to_decimal(input);
        printf("Decimal equivalent: %d\n", decimal);
        decimal_to_binary(decimal);
    } else {
        printf("Invalid binary number.\n");
    }
    
    return 0;
}