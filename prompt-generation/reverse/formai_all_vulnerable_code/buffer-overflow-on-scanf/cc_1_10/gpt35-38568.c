//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToInt(char *hex)
{
    int val = 0;

    for (int i = 0; i < strlen(hex); i++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
            val = val * 16 + (hex[i] - '0');
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            val = val * 16 + (hex[i] - 'a' + 10);
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            val = val * 16 + (hex[i] - 'A' + 10);
        else
            return -1; // error: invalid hex code
    }

    return val;
}

int main()
{
    char hex[8];
    printf("Enter a hex color code (eg. FF9933): ");
    scanf("%s", hex);

    // check if the input is a valid hex code
    if (strlen(hex) != 6)
    {
        printf("Error: Invalid hex code\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < strlen(hex); i++)
    {
        if (!((hex[i] >= '0' && hex[i] <= '9') ||
              (hex[i] >= 'a' && hex[i] <= 'f') ||
              (hex[i] >= 'A' && hex[i] <= 'F')))
        {
            printf("Error: Invalid hex code\n");
            exit(EXIT_FAILURE);
        }
    }

    int red = hexToInt(strncpy(NULL, hex, 2));
    int green = hexToInt(strncpy(NULL, hex + 2, 2));
    int blue = hexToInt(strncpy(NULL, hex + 4, 2));

    printf("RGB code: (%d, %d, %d)\n", red, green, blue);

    return 0;
}