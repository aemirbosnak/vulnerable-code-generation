//FormAI DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <string.h>

int binary_to_decimal(char binary[])
{
    int result = 0;

    // Iterate through the binary string
    for (int i = 0; i < strlen(binary); i++)
    {
        // If the current character is a 1, add the corresponding power of 2 to the result
        if (binary[i] == '1')
        {
            result += 1 << (strlen(binary) - 1 - i);
        }
    }

    return result;
}

void decimal_to_binary(int decimal)
{
    char binary[32] = {'\0'}; // Initialize binary string with null characters

    // Convert decimal to binary
    int index = 0;
    while (decimal > 0)
    {
        binary[index++] = decimal % 2 + '0';
        decimal /= 2;
    }

    // Reverse the binary string
    for (int i = 0, j = strlen(binary) - 1; i < j; i++, j--)
    {
        char temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }

    printf("%s\n", binary);
}

int main()
{
    int choice;

    do
    {
        printf("Binary Converter\n");
        printf("----------------\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                char binary[32];
                printf("Enter binary number: ");
                scanf("%s", binary);

                int decimal = binary_to_decimal(binary);
                printf("%s in decimal is %d\n", binary, decimal);

                break;
            }
            case 2:
            {
                int decimal;
                printf("Enter decimal number: ");
                scanf("%d", &decimal);

                printf("%d in binary is ", decimal);
                decimal_to_binary(decimal);

                break;
            }
            case 3:
            {
                printf("Goodbye!\n");

                break;
            }
            default:
            {
                printf("Invalid choice. Please try again.\n");

                break;
            }
        }

        printf("\n");
    }
    while (choice != 3);

    return 0;
}