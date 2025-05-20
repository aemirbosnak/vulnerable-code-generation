//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000
#define MAX_STR_LENGTH 100

int main(void)
{
    char input_buffer[MAX_LINE_LENGTH];
    char hex_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];
    int line_number = 0;
    int char_number = 0;
    int hex_val = 0;
    int decimal_val = 0;
    int i = 0;
    int j = 0;
    bool is_hex = false;

    printf("Enter the hexadecimal number to convert:\n");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    for (i = 0; input_buffer[i]!= '\0'; i++)
    {
        if (!isalnum(input_buffer[i]))
        {
            printf("Error: Input contains non-alphanumeric characters.\n");
            return 1;
        }
    }

    for (i = 0; i < strlen(input_buffer); i++)
    {
        if (isdigit(input_buffer[i]))
        {
            decimal_val = decimal_val * 16 + (input_buffer[i] - '0');
        }
        else if (isalpha(input_buffer[i]))
        {
            if (isupper(input_buffer[i]))
            {
                hex_val = hex_val * 16 + (input_buffer[i] - 'A' + 10);
            }
            else
            {
                hex_val = hex_val * 16 + (input_buffer[i] - 'a' + 10);
            }
        }
        else
        {
            printf("Error: Input contains non-alphanumeric characters.\n");
            return 1;
        }
    }

    sprintf(output_buffer, "Hexadecimal: %X\nDecimal: %d\n", hex_val, decimal_val);
    printf("%s", output_buffer);

    return 0;
}