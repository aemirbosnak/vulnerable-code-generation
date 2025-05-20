//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Declare functions before using them
void decimal_to_hexadecimal(int decimal_number);
int hexadecimal_to_decimal(char hexadecimal_number[]);
void print_banner();

int main() {
    print_banner();

    int choice;
    int decimal;
    char hexadecimal[10];

    do {
        printf("\n1. Decimal to Hexadecimal");
        printf("\n2. Hexadecimal to Decimal");
        printf("\n3. Exit");

        printf("\nEnter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimal_to_hexadecimal(decimal);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexadecimal);
                printf("Decimal equivalent is %d", hexadecimal_to_decimal(hexadecimal));
                break;
            case 3:
                printf("\nThank you for using Hexadecimal Converter! Goodbye.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice (1/2/3).\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void decimal_to_hexadecimal(int decimal_number) {
    int remainder, quotient;
    char hexadecimal[100];
    int index = 0;

    while (decimal_number != 0) {
        remainder = decimal_number % 16;

        if (remainder < 10) {
            hexadecimal[index] = remainder + 48;
        } else {
            hexadecimal[index] = remainder + 55;
        }

        index++;
        decimal_number /= 16;
    }

    printf("Hexadecimal equivalent is ");

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }

    printf("\n");
}

int hexadecimal_to_decimal(char hexadecimal_number[]) {
    int decimal = 0;
    int length = 0;

    // Get the length of the hexadecimal number
    while (hexadecimal_number[length] != '\0') {
        length++;
    }

    for (int i = 0; hexadecimal_number[i] != '\0'; i++) {
        // If it's an alphabet character
        if (hexadecimal_number[i] >= 'A' && hexadecimal_number[i] <= 'F') {
            decimal += (hexadecimal_number[i] - 55) * pow(16, length - 1);
            length--;
        }
        // If it's a decimal character
        else if (hexadecimal_number[i] >= '0' && hexadecimal_number[i] <= '9') {
            decimal += (hexadecimal_number[i] - 48) * pow(16, length - 1);
            length--;
        }
    }

    return decimal;
}

void print_banner() {
    printf("██╗  ██╗ █████╗ ██████╗ ██████╗ ██╗   ██╗███████╗██████╗  █████╗ ██████╗ ██████╗ ██╗  ██╗\n");
    printf("██║  ██║██╔══██╗██╔══██╗██╔══██╗██║   ██║██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║ ██╔╝\n");
    printf("███████║███████║██████╔╝██║  ██║██║   ██║█████╗  ██████╔╝███████║██████╔╝██║  ██║█████╔╝ \n");
    printf("██╔══██║██╔══██║██╔══██╗██║  ██║██║   ██║██╔══╝  ██╔══██╗██╔══██║██╔══██╗██║  ██║██╔═██╗ \n");
    printf("██║  ██║██║  ██║██║  ██║██████╔╝╚██████╔╝███████╗██║  ██║██║  ██║██║  ██║██████╔╝██║  ██╗\n");
    printf("╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝\n");
    printf("By Mind-Bending Programmer\n\n");
}