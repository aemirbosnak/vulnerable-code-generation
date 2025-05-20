//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    int i, j, len, num_digits;
    int decimal_num = 0;
    int hexadecimal_num = 0;
    char hexadecimal_str[1000];

    printf("Enter a hexadecimal number: ");
    fgets(input, 1000, stdin);
    len = strlen(input);

    // Remove leading/trailing whitespace
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (!isspace(input[i]) &&!isspace(input[j]))
            break;
        input[i] = input[j] = '\0';
    }
    len = strlen(input);

    // Convert hexadecimal to decimal
    for (i = 0; i < len; i++) {
        if (isxdigit(input[i])) {
            if (isupper(input[i])) {
                hexadecimal_num = (hexadecimal_num << 4) + (input[i] - 'A' + 10);
            } else {
                hexadecimal_num = (hexadecimal_num << 4) + (input[i] - 'a' + 10);
            }
        } else {
            printf("Invalid hexadecimal character: %c\n", input[i]);
            return 1;
        }
    }

    // Convert decimal to hexadecimal
    num_digits = 0;
    while (decimal_num > 0) {
        int digit = decimal_num % 16;
        if (digit < 10) {
            hexadecimal_str[num_digits++] = digit + '0';
        } else {
            hexadecimal_str[num_digits++] = digit + 'A' - 10;
        }
        decimal_num /= 16;
    }

    // Reverse the hexadecimal string
    for (i = 0, j = num_digits - 1; i < j; i++, j--) {
        char temp = hexadecimal_str[i];
        hexadecimal_str[i] = hexadecimal_str[j];
        hexadecimal_str[j] = temp;
    }
    hexadecimal_str[num_digits] = '\0';

    // Print the results
    printf("Hexadecimal: %s\n", hexadecimal_str);
    printf("Decimal: %d\n", decimal_num);

    return 0;
}