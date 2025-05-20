//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <string.h>

// Function to convert decimal to binary
void decToBin(int dec, char* bin) {
    int i = 0, j = 0;
    while (dec > 0) {
        bin[i++] = dec % 2 + '0';
        dec /= 2;
    }
    while (i < strlen(bin)) {
        bin[i++] = '0';
    }
    for (i = 0; i < strlen(bin) / 2; i++) {
        char temp = bin[i];
        bin[i] = bin[strlen(bin) - i - 1];
        bin[strlen(bin) - i - 1] = temp;
    }
}

// Function to convert binary to decimal
int binToDec(char* bin) {
    int dec = 0, i = 0;
    while (bin[i]!= '\0') {
        dec = dec * 2 + bin[i] - '0';
        i++;
    }
    return dec;
}

int main() {
    char input[100];
    int choice, decimal;
    printf("Enter a decimal number: ");
    scanf("%s", input);
    decimal = strtol(input, NULL, 10);
    printf("Enter your choice:\n1. Convert decimal to binary\n2. Convert binary to decimal\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Binary equivalent: ");
            decToBin(decimal, input);
            printf("%s\n", input);
            break;
        case 2:
            printf("Decimal equivalent: %d\n", binToDec(input));
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}