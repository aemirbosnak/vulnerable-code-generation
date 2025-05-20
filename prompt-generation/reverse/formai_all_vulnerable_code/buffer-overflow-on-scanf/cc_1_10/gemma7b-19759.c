//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HexConverter
{
    char input[16];
    int index;
    char output[32];
    int outIndex;
} HexConverter;

void convertHex(HexConverter *converter)
{
    int i, j, k, num;
    char hex[4], temp[2];

    converter->outIndex = 0;

    for (i = 0; i < converter->index; i++)
    {
        num = converter->input[i] - '0';
        hex[0] = num / 16 + 'A';
        hex[1] = num % 16 + 'A';

        for (j = 0; j < 2; j++)
        {
            converter->output[converter->outIndex++] = hex[j];
        }

        converter->output[converter->outIndex++] = ' ';
    }

    converter->output[converter->outIndex] = '\0';
}

int main()
{
    HexConverter converter;
    converter.index = 0;

    printf("Enter hexadecimal number: ");
    scanf("%s", converter.input);

    convertHex(&converter);

    printf("Converted number: %s\n", converter.output);

    return 0;
}