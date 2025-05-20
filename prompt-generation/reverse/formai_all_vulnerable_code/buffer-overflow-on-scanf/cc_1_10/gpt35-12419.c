//FormAI DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>

// Function to convert decimal to binary
int decimalToBinary(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    // Converting binary array to integer
    int binary = 0;
    for (int j = i - 1; j >= 0; j--) {
        binary = binary * 10 + binaryNum[j];
    }
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(long long n)
{
    int decimal = 0, i = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

int main()
{
    char choice;
    printf("Welcome to Binary Converter!\n");
    do {
        printf("\nChoose an option:\n");
        printf("[1] Decimal to Binary\n[2] Binary to Decimal\n");
        scanf(" %c", &choice);

        // Decimal to Binary
        if (choice == '1') {
            int decimal;
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            printf("Binary number of %d: %d\n", decimal, decimalToBinary(decimal));
        }
        // Binary to Decimal
        else if (choice == '2') {
            long long binary;
            printf("Enter a binary number: ");
            scanf("%lld", &binary);
            printf("Decimal number of %lld: %d\n", binary, binaryToDecimal(binary));
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
        // Ask if user wants to convert again
        printf("\nDo you want to convert again? [Y/N]: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}