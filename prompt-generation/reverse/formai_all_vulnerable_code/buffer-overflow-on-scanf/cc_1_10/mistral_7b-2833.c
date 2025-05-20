//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
//***************************************************************************
//* Hexadecimal Converter: A High-Octane, Super-Charged, Lightning-Fast     *
//* Hex to Decimal and Decimal to Hex Converter for the Brave and the Bold!   *
//* This program converts Hexadecimal numbers to Decimal and Decimal to     *
//* Hexadecimal numbers with the speed and agility of a cheetah on roller    *
//* skates!                                                                 *
//***************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

typedef struct HexConverter {
    char input[MAX_INPUT_SIZE];
    int base;
    int result;
} HexConverter;

void hexToDec(HexConverter *converter) {
    int i = 0, len = strlen(converter->input);
    int num = 0, temp = 0;

    for (; i < len; i++) {
        if (isdigit(converter->input[i])) {
            num += (converter->input[i] - '0') * pow(16, len - i - 1);
        } else if (isalpha(converter->input[i])) {
            num += (converter->input[i] - 'A' + 10) * pow(16, len - i - 1);
        }
        temp += num;
        num = 0;
    }

    converter->result = temp;
}

void decToHex(HexConverter *converter) {
    int i = 0, temp = converter->result;
    char hex[MAX_INPUT_SIZE];

    do {
        hex[i++] = temp % 16 > 9 ? (temp % 16 - 10) + 'A' : temp % 16 + '0';
        temp /= 16;
    } while (temp != 0);

    converter->base = i;
    strncpy(converter->input, &hex[i], MAX_INPUT_SIZE);
}

int main() {
    HexConverter converter;
    char command[MAX_INPUT_SIZE];
    int choice;

    printf("Welcome to the Hexadecimal Converter, the fastest in town!\n");
    printf("Enter the number or hexadecimal value you want to convert:\n");
    fgets(converter.input, MAX_INPUT_SIZE, stdin);
    converter.input[strcspn(converter.input, "\n")] = '\0';

    do {
        printf("\nChoose an option:\n1. Convert Hexadecimal to Decimal\n2. Convert Decimal to Hexadecimal\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                hexToDec(&converter);
                printf("The decimal value of %s is %d.\n", converter.input, converter.result);
                break;
            case 2:
                converter.result = 0;
                decToHex(&converter);
                printf("The hexadecimal value of %d is %s.\n", converter.result, converter.input);
                break;
            case 3:
                printf("Goodbye and have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}