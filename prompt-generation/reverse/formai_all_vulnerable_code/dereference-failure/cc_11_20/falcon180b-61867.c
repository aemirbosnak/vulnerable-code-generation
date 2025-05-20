//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    char *binary_str = argv[1];
    char *decimal_str = argv[2];
    char *hexadecimal_str = argv[3];

    if (argc!= 4) {
        printf("Error: Invalid number of arguments. Please provide binary, decimal, and hexadecimal strings.\n");
        return 1;
    }

    int binary_len = strlen(binary_str);
    int decimal_len = strlen(decimal_str);
    int hexadecimal_len = strlen(hexadecimal_str);

    if (binary_len > MAX_LENGTH || decimal_len > MAX_LENGTH || hexadecimal_len > MAX_LENGTH) {
        printf("Error: Input strings are too long. Please provide strings with a maximum length of %d characters.\n", MAX_LENGTH);
        return 1;
    }

    int binary_int = 0;
    int decimal_int = 0;
    int hexadecimal_int = 0;

    for (int i = 0; i < binary_len; i++) {
        if (!isdigit(binary_str[i])) {
            printf("Error: Binary string contains non-numeric characters.\n");
            return 1;
        }
        binary_int = binary_int * 2 + (binary_str[i] - '0');
    }

    for (int i = 0; i < decimal_len; i++) {
        if (!isdigit(decimal_str[i])) {
            printf("Error: Decimal string contains non-numeric characters.\n");
            return 1;
        }
        decimal_int = decimal_int * 10 + (decimal_str[i] - '0');
    }

    for (int i = 0; i < hexadecimal_len; i++) {
        if (!isxdigit(hexadecimal_str[i])) {
            printf("Error: Hexadecimal string contains non-numeric or non-hexadecimal characters.\n");
            return 1;
        }
        hexadecimal_int = hexadecimal_int * 16 + (hexadecimal_str[i] - (isdigit(hexadecimal_str[i])? '0' : 'A' - 10));
    }

    printf("Binary: %s\n", binary_str);
    printf("Decimal: %s\n", decimal_str);
    printf("Hexadecimal: %s\n", hexadecimal_str);

    printf("Binary equivalent: %d\n", binary_int);
    printf("Decimal equivalent: %d\n", decimal_int);
    printf("Hexadecimal equivalent: %d\n", hexadecimal_int);

    return 0;
}