//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <string.h>

// Function to convert a decimal number to binary
int decimalToBinary(int decimal, int binary[]) {
    // Base case
    if (decimal == 0) {
        binary[0] = 0;
        binary[1] = 0;
        return 2;
    }

    // Recursive case
    int result = 0;
    int count = 0;
    while (decimal > 0) {
        result += 1;
        decimal = decimal / 2;
    }

    for (int i = 0; i < result; i++) {
        binary[i] = decimal;
        decimal = decimal / 2;
    }

    return result;
}

// Function to calculate the subnet mask
int calculateSubnetMask(int decimal, int binary[]) {
    // Base case
    if (decimal == 0) {
        return 1;
    }

    // Recursive case
    int result = 0;
    int count = 0;
    while (decimal > 0) {
        result += 1;
        decimal = decimal / 2;
    }

    for (int i = 0; i < result; i++) {
        if (binary[i] == 0) {
            binary[i] = 1;
            binary[i + 1] = 1;
            result += 1;
        }
    }

    return result;
}

// Function to print the subnet mask in binary
void printSubnetMask(int binary[]) {
    int i;
    for (i = 0; i < 32; i++) {
        if (binary[i] == 0) {
            printf("0");
        } else {
            printf("1");
        }
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter the decimal value of the subnet mask: ");
    scanf("%d", &decimal);

    int binary[32];
    int result = decimalToBinary(decimal, binary);
    if (result!= 32) {
        printf("Error: Invalid decimal value.\n");
        return 1;
    }

    result = calculateSubnetMask(decimal, binary);
    if (result!= 32) {
        printf("Error: Invalid decimal value.\n");
        return 1;
    }

    printSubnetMask(binary);

    return 0;
}