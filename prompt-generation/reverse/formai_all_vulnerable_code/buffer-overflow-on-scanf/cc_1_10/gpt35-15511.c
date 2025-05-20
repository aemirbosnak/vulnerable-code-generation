//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_to_hex_recursive(int num)
{
    if (num == 0)
    {
        return;
    }
    
    convert_to_hex_recursive(num / 16);
    
    int rem = num % 16;
    char hex_val;
    if (rem < 10)
    {
        hex_val = rem + '0';
    }
    else
    {
        hex_val = rem - 10 + 'A';
    }
    
    printf("%c", hex_val);
}

void convert_to_color_code(int red, int green, int blue)
{
    printf("Hexadecimal color code: #");
    convert_to_hex_recursive(red);
    convert_to_hex_recursive(green);
    convert_to_hex_recursive(blue);
    printf("\n");
}

int main()
{
    int red, green, blue;
    printf("Enter red value (0-255): ");
    scanf("%d", &red);
    printf("Enter green value (0-255): ");
    scanf("%d", &green);
    printf("Enter blue value (0-255): ");
    scanf("%d", &blue);
    
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
    {
        printf("Invalid input values!\n");
        return 1;
    }
    
    convert_to_color_code(red, green, blue);
    
    return 0;
}