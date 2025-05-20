//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decimal_to_hexadecimal(int n) {
    int quotient = n / 16;
    int remainder = n % 16;
    if (n == 0) {
        return;
    }
    decimal_to_hexadecimal(quotient);
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", remainder + 55);
    }
}

// Function to convert hexadecimal to decimal
int hexadecimal_to_decimal(char hexadecimal[]) {
    int decimal = 0, place_value = 1;
    for (int i = 0; hexadecimal[i] != '\0'; i++) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * place_value;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 55) * place_value;
        }
        place_value *= 16;
    }
    return decimal;
}

int main() {
    int option, decimal_number;
    char hexadecimal_number[30];
    printf("Choose your conversion:\n");
    printf("1. Decimal to Hexadecimal Conversion\n");
    printf("2. Hexadecimal to Decimal Conversion\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("Enter the Decimal Number: ");
        scanf("%d", &decimal_number);
        printf("The Hexadecimal Conversion is: ");
        decimal_to_hexadecimal(decimal_number);
    } else if (option == 2) {
        printf("Enter the Hexadecimal Number: ");
        scanf("%s", hexadecimal_number);
        printf("The Decimal Conversion is: %d", hexadecimal_to_decimal(hexadecimal_number));
    } else {
        printf("Invalid Option Selected.");
    }
    return 0;
}