//FormAI DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>

// function to convert decimal to binary
void decToBin(int dec) {
    int bin[32];
    int i = 0;
    while (dec > 0) {
        bin[i] = dec % 2;
        dec = dec / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
    printf("\n");
}

// function to convert binary to decimal
void binToDec(long long bin) {
    int dec = 0, mult = 1;
    while (bin > 0) {
        dec = dec + mult * (bin % 10);
        bin = bin / 10;
        mult = mult * 2;
    }
    printf("%d\n", dec);
}

int main() {
    int choice, dec;
    long long bin;

    printf("Welcome to the Binary Converter!\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter a decimal number: ");
        scanf("%d", &dec);
        printf("%d in binary is: ", dec);
        decToBin(dec);
    }
    else if (choice == 2) {
        printf("Enter a binary number: ");
        scanf("%lld", &bin);
        printf("%lld in decimal is: ", bin);
        binToDec(bin);
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}