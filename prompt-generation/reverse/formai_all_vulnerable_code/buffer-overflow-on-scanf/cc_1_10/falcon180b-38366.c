//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char binary[MAX_LENGTH];
    char decimal[MAX_LENGTH];
    int length;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    length = strlen(binary);

    if (length == 0) {
        printf("Error: Empty binary number\n");
        return 1;
    }

    if (binary[0] == '0' && length > 1) {
        printf("Error: Binary number cannot start with 0\n");
        return 1;
    }

    int i = 0;
    while (binary[i]!= '\0') {
        if (binary[i]!= '0' && binary[i]!= '1') {
            printf("Error: Invalid binary number\n");
            return 1;
        }
        i++;
    }

    int decimal_value = 0;
    int power = 0;

    for (int j = length - 1; j >= 0; j--) {
        if (binary[j] == '1') {
            decimal_value += (int) pow(2, power);
        }
        power++;
    }

    sprintf(decimal, "%d", decimal_value);

    printf("Decimal equivalent of %s is %s\n", binary, decimal);

    return 0;
}