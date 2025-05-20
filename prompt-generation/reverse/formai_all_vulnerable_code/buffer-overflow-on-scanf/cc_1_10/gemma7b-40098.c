//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, choice, oct, bin, decimal;
    char binary[100];

    printf("Welcome to the Binary Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the decimal number: ");
            scanf("%d", &num);
            bin = num;
            i = 0;
            while (bin)
            {
                oct = bin % 2;
                binary[i++] = oct + 48;
                bin /= 2;
            }
            binary[i] = '\0';
            printf("The binary equivalent is: %s\n", binary);
            break;

        case 2:
            printf("Enter the binary number: ");
            scanf("%s", binary);
            decimal = 0;
            i = 0;
            while (binary[i] != '\0')
            {
                bin = binary[i] - 48;
                decimal += bin * pow(2, i);
                i++;
            }
            printf("The decimal equivalent is: %d\n", decimal);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}