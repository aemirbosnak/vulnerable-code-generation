//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

void secure_hex_convert(char *hex_string)
{
    int i = 0;
    char upper_hex_string[100];
    char lower_hex_string[100];

    // Convert the input string to uppercase
    for (i = 0; hex_string[i] != '\0'; i++)
    {
        upper_hex_string[i] = hex_string[i] - 32;
    }

    // Convert the uppercase string to lowercase
    for (i = 0; upper_hex_string[i] != '\0'; i++)
    {
        lower_hex_string[i] = upper_hex_string[i] + 32;
    }

    // Validate the converted string
    if (validate_hex_string(lower_hex_string) == 0)
    {
        printf("Invalid hexadecimal string.\n");
        exit(1);
    }

    // Print the converted string
    printf("Converted hexadecimal string: %s\n", lower_hex_string);
}

int validate_hex_string(char *hex_string)
{
    int i = 0;

    // Check for invalid characters
    for (i = 0; hex_string[i] != '\0'; i++)
    {
        if ((hex_string[i] < 'a' || hex_string[i] > 'f') && (hex_string[i] < 'A' || hex_string[i] > 'F'))
        {
            return 0;
        }
    }

    // Check for invalid length
    if (strlen(hex_string) % 2 != 0)
    {
        return 0;
    }

    return 1;
}

int main()
{
    char hex_string[100];

    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_string);

    secure_hex_convert(hex_string);

    return 0;
}