//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_SIZE 64
#define MAX_BIN_SIZE (MAX_NUM_SIZE * 8)

int main(int argc, char *argv[])
{
    char num[MAX_NUM_SIZE];
    char bin[MAX_BIN_SIZE];
    int num_len, bin_len;

    printf("Enter a decimal number: ");
    fgets(num, MAX_NUM_SIZE, stdin);
    num_len = strlen(num);

    if (num_len == 0 || num[0] == '\n')
    {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; i < num_len; i++)
    {
        if (!isdigit(num[i]))
        {
            printf("Invalid input.\n");
            return 1;
        }
    }

    int sign = 1;
    if (num[0] == '-')
    {
        sign = -1;
        strcpy(num, &num[1]);
        num_len--;
    }

    bin_len = 0;
    int temp = 0;
    int power = 1;

    for (int i = num_len - 1; i >= 0; i--)
    {
        temp += (num[i] - '0') * power;
        power *= 10;
    }

    while (temp!= 0)
    {
        bin[bin_len++] = (temp % 2) + '0';
        temp /= 2;
    }

    if (sign == -1)
    {
        bin[0] = '-';
        bin_len++;
    }

    printf("Binary representation: ");
    for (int i = bin_len - 1; i >= 0; i--)
    {
        printf("%c", bin[i]);
    }

    return 0;
}