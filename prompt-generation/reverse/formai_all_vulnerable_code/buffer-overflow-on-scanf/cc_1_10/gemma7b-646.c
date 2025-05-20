//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num, oct, binary;
    char choice;

    printf("Welcome to the Binary Converter!\n");
    printf("Would you like to convert from:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");

    scanf("%c", &choice);

    switch (choice)
    {
        case '1':
            printf("Enter the decimal number: ");
            scanf("%d", &num);
            oct = num / 8;
            binary = num % 8;
            printf("The binary equivalent is: ");
            while (oct)
            {
                printf("%d ", oct % 2);
                oct /= 2;
            }
            printf("%d", binary);
            break;

        case '2':
            printf("Enter the binary number: ");
            scanf("%d", &num);
            binary = num % 2;
            oct = num / 2;
            printf("The decimal equivalent is: ");
            while (oct)
            {
                printf("%d ", oct % 10);
                oct /= 10;
            }
            printf("%d", binary);
            break;

        default:
            printf("Invalid choice.\n");
    }

    printf("\nThank you for using the Binary Converter!\n");
    return;
}