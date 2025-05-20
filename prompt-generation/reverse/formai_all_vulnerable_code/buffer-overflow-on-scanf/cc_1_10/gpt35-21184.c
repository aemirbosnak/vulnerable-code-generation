//FormAI DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS 64

int main()
{
    int choice;
    unsigned long long int decimal, binary = 0, base = 1, rem;
    char binaryString[BITS + 1];

    do
    {
        printf("1. Decimal to Binary Conversion\n");
        printf("2. Binary to Decimal Conversion\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%llu", &decimal);
                while(decimal > 0)
                {
                    rem = decimal % 2;
                    binary = binary + rem * base;
                    decimal = decimal / 2;
                    base = base * 10;
                }
                printf("Binary equivalent: %llu\n", binary);
                break;

            case 2:
                printf("Enter a binary number (up to %d bits): ", BITS);
                scanf("%s", binaryString);
                int length = strlen(binaryString);
                base = 1;
                for(int i = length - 1; i >= 0; i--)
                {
                    if(binaryString[i] == '1')
                    {
                        binary = binary + base;
                    }
                    base = base * 2;
                }
                printf("Decimal equivalent: %llu\n", binary);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 3);

    return 0;
}