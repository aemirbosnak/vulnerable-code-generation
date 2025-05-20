//FormAI DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert decimal to binary */
void decToBin(int n)
{
    int binaryNum[1000];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    /* Print the binary array in reverse order */
    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
    printf("\n");
}

/* Function to convert binary to decimal */
void binToDec(char* binaryNum)
{
    int decimalNum = 0;
    int len = strlen(binaryNum);

    for (int i = 0; i < len; i++) {
        if (binaryNum[i] == '1')
            decimalNum += (int)pow(2, len - 1 - i);
    }

    /* Print the decimal number */
    printf("Decimal equivalent: %d\n", decimalNum);
}

int main()
{
    int choice;
    printf("Welcome to Binary Converter 2077!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Please enter a decimal number: ");
            int decNum;
            scanf("%d", &decNum);
            decToBin(decNum);
            break;
        case 2:
            printf("Please enter a binary number: ");
            char binNum[1000];
            scanf("%s", binNum);
            binToDec(binNum);
            break;
        case 3:
            printf("Thank you for using Binary Converter 2077!\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (1);

    return 0;
}