//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>

void printHex(int number) {
    // Array to hold hexadecimal representation
    char hex[100];
    int i = 0;
    
    // Handle zero case explicitly
    if (number == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    // Conversion process
    while (number != 0) {
        int temp = number % 16; // Getting the remainder
        if (temp < 10) {
            hex[i] = temp + '0'; // Convert to ASCII
        } else {
            hex[i] = temp - 10 + 'A'; // Convert to ASCII (A-F)
        }
        number /= 16; // Divide the number by 16
        i++;
    }

    // Print hex in reverse order
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]); // Print characters in reverse order
    }
    printf("\n");
}

void menu() {
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("-------------------------------------------------\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("-------------------------------------------------\n");
}

int main() {
    int choice, number;

    do {
        menu(); // Display the menu
        printf("Enter your choice: ");
        scanf("%d", &choice); // User chooses an option

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number); // Read the decimal number
                printHex(number); // Convert and print hexadecimal
                break;
            case 2:
                printf("Goodbye, and stay coded!\n");
                break;
            default:
                printf("Invalid choice! Please choose 1 or 2.\n");
                break;
        }

        printf("\n"); // For better visual separation
    } while (choice != 2); // Loop until the user chooses to exit

    return 0;
}