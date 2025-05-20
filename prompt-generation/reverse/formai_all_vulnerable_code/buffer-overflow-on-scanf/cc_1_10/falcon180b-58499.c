//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // maximum length of input string

int main() {
    char input[MAX_LENGTH]; // input string
    char output[MAX_LENGTH]; // output string
    int length, i;

    // prompt user for input string
    printf("Enter a binary number: ");
    scanf("%s", input);

    // validate input string
    length = strlen(input);
    for (i = 0; i < length; i++) {
        if (input[i]!= '0' && input[i]!= '1') {
            printf("Invalid input. Please enter a binary number.\n");
            return 1;
        }
    }

    // convert binary to decimal
    int decimal = 0;
    int power = 0;
    for (i = strlen(input) - 1; i >= 0; i--) {
        if (input[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    // convert decimal to binary
    int binary = 0;
    power = 0;
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binary += pow(10, power);
        }
        decimal /= 2;
        power++;
    }

    // print output string
    sprintf(output, "Binary: %s\nDecimal: %d", input, binary);
    printf("%s", output);

    return 0;
}