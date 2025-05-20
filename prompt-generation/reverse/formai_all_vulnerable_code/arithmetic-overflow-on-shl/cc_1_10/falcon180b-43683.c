//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000000

void print_binary(int num, int length)
{
    char buffer[length + 1];
    memset(buffer, '0', length);
    buffer[length] = '\0';
    int i = 0;
    while (num!= 0)
    {
        if (num & 1)
        {
            buffer[i] = '1';
        }
        else
        {
            buffer[i] = '0';
        }
        num >>= 1;
        i++;
    }
    printf("%s\n", buffer);
}

int main()
{
    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);

    int length = strlen(input);
    if (length == 0)
    {
        printf("Error: Input is empty.\n");
        return 1;
    }

    if (input[0]!= '0' && input[0]!= '1')
    {
        printf("Error: Input is not a binary number.\n");
        return 1;
    }

    int num = 0;
    int i = 0;
    while (i < length)
    {
        if (input[i] == '1')
        {
            num += 1 << i;
        }
        i++;
    }

    print_binary(num, length);

    return 0;
}