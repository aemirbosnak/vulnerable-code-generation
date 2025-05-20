//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100000

char hex_table[] = "0123456789ABCDEF";

char *int_to_hex(int num) {
    char *hex = malloc(sizeof(char) * 9);
    sprintf(hex, "%08X", num);
    return hex;
}

int hex_to_int(char *hex) {
    int num = 0;
    sscanf(hex, "%X", &num);
    return num;
}

int main() {
    char input[MAX_SIZE];
    char hex_output[MAX_SIZE];
    int decimal_output;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_SIZE, stdin);

    int len = strlen(input);

    if (len == 0 || input[0]!= '0' && input[0]!= 'x' && input[0]!= 'X') {
        printf("Invalid input. Please enter a hexadecimal number.\n");
        return 1;
    }

    if (input[0] == '0' && input[1] == 'x' || input[0] == 'X' && input[1] == 'x') {
        strcpy(input, &input[2]);
        len -= 2;
    }

    if (len > 8) {
        printf("Hexadecimal number is too long.\n");
        return 1;
    }

    for (int i = 0; i < len; i++) {
        if (strchr(hex_table, input[i]) == NULL) {
            printf("Invalid hexadecimal character: %c\n", input[i]);
            return 1;
        }
    }

    for (int i = 0; i < len; i++) {
        hex_output[i] = input[i];
    }

    hex_output[len] = '\0';
    decimal_output = hex_to_int(hex_output);

    printf("Hexadecimal: %s\n", input);
    printf("Decimal: %d\n", decimal_output);

    return 0;
}