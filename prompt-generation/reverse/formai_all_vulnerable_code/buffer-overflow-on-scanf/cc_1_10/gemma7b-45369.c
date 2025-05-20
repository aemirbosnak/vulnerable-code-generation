//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int input_size;
    int converted_size;
} HexadecimalConverter;

void convertToHexadecimal(HexadecimalConverter *converter, int value)
{
    int i = 0;
    char hex_digits[] = "0123456789abcdef";

    converter->buffer[converter->position++] = hex_digits[value & 0xf];
    converter->buffer[converter->position++] = hex_digits[value >> 4 & 0xf];

    converter->converted_size++;
}

int main()
{
    HexadecimalConverter converter;
    converter.position = 0;
    converter.input_size = 0;
    converter.converted_size = 0;

    printf("Enter an integer: ");
    scanf("%d", &converter.input_size);

    for (int i = 0; i < converter.input_size; i++)
    {
        int value;
        printf("Enter an integer: ");
        scanf("%d", &value);

        convertToHexadecimal(&converter, value);
    }

    printf("Converted hexadecimal values:\n");
    for (int i = 0; i < converter.converted_size; i++)
    {
        printf("%c ", converter.buffer[i]);
    }

    printf("\n");

    return 0;
}