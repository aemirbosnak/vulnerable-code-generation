//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

char hex_map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                  'A', 'B', 'C', 'D', 'E', 'F'};

int main()
{
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a hexadecimal string to translate into Alien:\n");

    char hex_input[100];
    scanf("%s", hex_input);

    printf("Your Alien translation is:\n");
    for(int i=0; i<strlen(hex_input); i++)
    {
        char hex_char = hex_input[i];
        // Convert hex char to binary
        char binary_str[5];
        for(int j=0; j<4; j++)
        {
            int bit = (hex_char >> j) & 1;
            if(bit == 0)
            {
                binary_str[3-j] = 'X';
            }
            else
            {
                binary_str[3-j] = 'O';
            }
        }
        binary_str[4] = '\0';

        // Convert binary string to Alien symbol
        int binary_val = 0;
        for(int j=0; j<strlen(binary_str); j++)
        {
            if(binary_str[j] == 'O')
            {
                binary_val |= (1 << (3-j));
            }
        }
        char alien_char = hex_map[binary_val];

        // Print Alien symbol
        printf("%c", alien_char);
    }
    printf("\n");

    return 0;
}