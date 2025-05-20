//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void to_hex(unsigned char input) {
    char hex[3];
    sprintf(hex, "%02X", input);
    printf("%s ", hex);
}

void convert_hex(char *hex_string) {
    int i, j;
    unsigned char hex_value;

    for (i = 0; i < strlen(hex_string); i += 2) {
        sscanf(hex_string + i, "%2hx", &hex_value);
        putchar(hex_value);
    }
}

int main(int argc, char **argv) {
    char hex_string[MAX_SIZE];
    int choice;

    printf("\n*** HEXADECIMAL CONVERTER PROGRAM ***\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter decimal value : ");
        scanf("%s", hex_string);

        for (int i = 0; hex_string[i] != '\0'; i++) {
            if (isdigit(hex_string[i])) {
                putchar(hex_string[i]);
            } else {
                to_hex((unsigned char) (toupper(hex_string[i]) - 55));
            }
        }
        putchar('\n');
    } else if (choice == 2) {
        printf("\nEnter hexadecimal string : ");
        scanf("%s", hex_string);

        printf("\nConverted decimal value : ");
        convert_hex(hex_string);
        putchar('\n');
    } else {
        printf("\nInvalid choice!\n");
    }

    return 0;
}