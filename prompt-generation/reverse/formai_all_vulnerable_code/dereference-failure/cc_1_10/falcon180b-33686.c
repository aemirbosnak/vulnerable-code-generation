//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char *input_str = (char *)malloc(100 * sizeof(char));
    char *output_str = (char *)malloc(200 * sizeof(char));
    int i, j, len, hex_val;

    printf("\n\n\n\n");
    printf("Welcome to the Hexadecimal Converter\n\n");
    printf("Enter a string to convert to hexadecimal:\n");
    scanf("%s", input_str);

    len = strlen(input_str);

    for(i=0, j=0; i<len; i++, j+=2)
    {
        hex_val = 0;

        if(isupper(input_str[i]))
        {
            hex_val += (input_str[i] - 65) * 16;
        }
        else if(islower(input_str[i]))
        {
            hex_val += (input_str[i] - 97) * 16;
        }
        else if(isdigit(input_str[i]))
        {
            hex_val += (input_str[i] - 48) * 16;
        }

        if(isupper(input_str[i]))
        {
            output_str[j] = input_str[i];
            output_str[j+1] = '\0';
        }
        else if(islower(input_str[i]))
        {
            output_str[j] = input_str[i];
            output_str[j+1] = '\0';
        }
        else if(isdigit(input_str[i]))
        {
            output_str[j] = input_str[i];
            output_str[j+1] = '\0';
        }
    }

    printf("\nThe hexadecimal representation of the entered string is:\n");
    printf("%s\n", output_str);

    return 0;
}