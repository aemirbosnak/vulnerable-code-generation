//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, oct, binary[100], count = 0;
    char ch;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Converting number to binary
    while (num)
    {
        int digit = num % 2;
        num /= 2;
        binary[count++] = digit;
    }

    // Printing binary number
    printf("Binary representation: ");
    for (i = count - 1; i >= 0; i--)
    {
        printf("%d ", binary[i]);
    }

    printf("\n");

    // Converting binary to octal
    oct = 0;
    count = 0;
    while (binary[count] != 0)
    {
        int digit = binary[count] % 8;
        binary[count] /= 8;
        oct += digit * pow(2, count);
        count++;
    }

    // Printing octal number
    printf("Octal representation: ");
    while (oct)
    {
        int digit = oct % 8;
        oct /= 8;
        printf("%d ", digit);
    }

    printf("\n");

    // Additional features
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Converting character to binary
    int char_binary = ch - 96;
    printf("Character binary: %d", char_binary);

    return 0;
}