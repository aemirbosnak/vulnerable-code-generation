//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>

// Function to get a decimal number as input
int getdec()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    return num;
}

// Function to get a binary number as input
int getbin()
{
    int num;
    printf("Enter a binary number: ");
    scanf("%d", &num);
    return num;
}

// Function to convert a decimal number to binary
void decToBin(int num)
{
    int i = 0;
    int bin[32] = {0};
    while (num > 0) {
        bin[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (i; i >= 0; i--) {
        printf("%d", bin[i]);
    }
}

// Function to convert a binary number to decimal
int binToDec(int num)
{
    int i = 0;
    int dec = 0;
    while (num > 0) {
        dec = dec + (num % 2) * pow(2, i);
        num = num / 2;
        i++;
    }
    return dec;
}

int main()
{
    int num1 = getdec();
    printf("Decimal number: %d\n", num1);
    decToBin(num1);

    int num2 = getbin();
    printf("Binary number: %d\n", num2);
    binToDec(num2);

    return 0;
}