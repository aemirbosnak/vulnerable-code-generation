//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void convert_hex_to_int(char *hex_number)
{
    int int_value = 0;
    int i = 0;

    while (hex_number[i] != '\0')
    {
        int digit = hex_number[i] - 'a' + 10;
        int_value = int_value * 16 + digit;
        i++;
    }

    printf("Integer value: %d\n", int_value);
}

void convert_int_to_hex(int int_value)
{
    char *hex_number = malloc(10);
    int i = 0;

    while (int_value > 0)
    {
        int digit = int_value % 16;
        hex_number[i] = 'a' + digit - 10;
        int_value /= 16;
        i++;
    }

    hex_number[i] = '\0';
    printf("Hexadecimal number: %s\n", hex_number);
}

int main()
{
    int choice;
    char hex_number[20];
    int int_value;

    printf("Select an option:\n");
    printf("1. Convert hex to int\n");
    printf("2. Convert int to hex\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex_number);
            convert_hex_to_int(hex_number);
            break;
        case 2:
            printf("Enter an integer value: ");
            scanf("%d", &int_value);
            convert_int_to_hex(int_value);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}