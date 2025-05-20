//FormAI DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>

// Function to convert decimal to binary
void decimal_to_binary(unsigned int num) {
    int binary_num[32] = {0};
    int i = 0;
    while (num > 0) {
        binary_num[i] = num % 2;
        num /= 2;
        i++;
    }
    // Print binary number in reverse order
    printf("Binary Number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary_num[j]);
    }
    printf("\n");
}

// Function to convert binary to decimal
void binary_to_decimal(unsigned long long num) {
    unsigned int decimal_num = 0;
    int power = 0;
    while (num > 0) {
        int bit = num % 10;
        decimal_num += bit * pow(2, power);
        power++;
        num /= 10;
    }
    printf("Decimal Number: %d\n", decimal_num);
}

int main() {
    unsigned int num1;
    unsigned long long num2;
    int choice;

    printf("Welcome to the Binary Converter!\n");

    do {
        printf("\nWhat would you like to convert?\n");
        printf("1 - Decimal to Binary\n2 - Binary to Decimal\n3 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &num1);
                decimal_to_binary(num1);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%llu", &num2);
                binary_to_decimal(num2);
                break;
            case 3:
                printf("Thank you for using the Binary Converter!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}