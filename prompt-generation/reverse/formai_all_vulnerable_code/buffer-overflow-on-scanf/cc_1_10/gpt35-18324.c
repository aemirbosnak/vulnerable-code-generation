//FormAI DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <math.h>

void binaryConverter(int num);
int decimalConverter(int num);

int main() {
    int choice, num;

    printf("Welcome to Binary-Decimal Converter\n\n");
    printf("1 - Convert Binary to Decimal\n");
    printf("2 - Convert Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter Binary number: ");
            scanf("%d", &num);
            binaryConverter(num);
            break;
        case 2:
            printf("Enter Decimal number: ");
            scanf("%d", &num);
            decimalConverter(num);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void binaryConverter(int num) {
    int dec = 0, i = 0, rem;
    while (num != 0) {
        rem = num % 10;
        num /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    printf("Decimal equivalent: %d\n", dec);
}

int decimalConverter(int num) {
    int bin = 0, i = 1, rem;

    while (num != 0) {
        rem = num % 2;
        num /= 2;
        bin += rem * i;
        i *= 10;
    }
    printf("Binary equivalent: %d\n", bin);
    return bin;
}