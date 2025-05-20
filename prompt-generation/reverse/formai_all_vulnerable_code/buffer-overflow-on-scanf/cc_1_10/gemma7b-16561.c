//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#pragma warning(disable: 4838)
#endif

void main()
{
    char **hex_array = NULL;
    char input_buffer[256];
    int input_size = 0;
    int i = 0;
    int j = 0;
    long int number = 0;
    char output_buffer[256];
    char output_hex[256];

    hex_array = malloc(input_size);

    printf("Enter hexadecimal data (separated by spaces): ");
    scanf("%s", input_buffer);

    input_size = strlen(input_buffer) + 1;
    hex_array = realloc(hex_array, input_size);

    strcpy(hex_array, input_buffer);

    for (i = 0; i < input_size - 1; i++)
    {
        number = strtol(hex_array[i], NULL, 16);

        if (number < 0 || number > 255)
        {
            printf("Error: Invalid hexadecimal value.\n");
            return;
        }

        output_buffer[j] = (number & 0x0F) << 4 | (number & 0x0F);
        j++;
    }

    printf("Converted hexadecimal data:\n");

    for (i = 0; i < j; i++)
    {
        sprintf(output_hex, "%02x ", output_buffer[i]);
        printf("%s ", output_hex);
    }

    printf("\n");

    free(hex_array);

    return;
}