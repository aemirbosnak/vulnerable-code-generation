//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if(argc!= 2)
    {
        printf("Usage: %s <hex-string>\n", argv[0]);
        return 1;
    }

    char *hex_str = argv[1];
    char *bin_str = (char*)malloc(strlen(hex_str) * 3 + 1);

    for(int i = 0; i < strlen(hex_str); i++)
    {
        if(isdigit(hex_str[i]))
        {
            bin_str[i * 3] = hex_str[i];
            bin_str[i * 3 + 1] = '0';
            bin_str[i * 3 + 2] = '0';
        }
        else if(isupper(hex_str[i]))
        {
            char hex_char = hex_str[i];
            if(hex_char == 'A')
                hex_char = '0';
            else if(hex_char == 'B')
                hex_char = '1';
            else if(hex_char == 'C')
                hex_char = '2';
            else if(hex_char == 'D')
                hex_char = '3';
            else if(hex_char == 'E')
                hex_char = '4';
            else if(hex_char == 'F')
                hex_char = '5';
            else
                hex_char = '?';

            bin_str[i * 3] = hex_char;
            bin_str[i * 3 + 1] = '0';
            bin_str[i * 3 + 2] = '0';
        }
        else
        {
            bin_str[i * 3] = '?';
            bin_str[i * 3 + 1] = '?';
            bin_str[i * 3 + 2] = '?';
        }
    }

    printf("HEX: %s\nBIN: %s\n", hex_str, bin_str);
    free(bin_str);
    return 0;
}