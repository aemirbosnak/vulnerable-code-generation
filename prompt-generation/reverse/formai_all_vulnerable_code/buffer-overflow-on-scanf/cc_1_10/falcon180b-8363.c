//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decToBin(int dec) {
    int bin[33]; // Maximum 32 bits + 1 for null terminator
    int i = 0;

    // Iterate until decimal becomes 0
    while (dec > 0) {
        bin[i++] = dec % 2; // Add remainder to binary array
        dec /= 2; // Divide decimal by 2
    }

    // Reverse the binary array
    for (int j = 0; j < i / 2; j++) {
        int temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }

    // Print the binary representation
    printf("Binary representation: ");
    for (int k = 0; k < i; k++) {
        printf("%d", bin[k]);
    }
    printf("\n");
}

int main() {
    int choice, decimal;

    do {
        printf("Enter 1 to convert decimal to binary\n");
        printf("Enter 2 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the decimal number: ");
            scanf("%d", &decimal);
            decToBin(decimal);
            break;

        case 2:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 2);

    return 0;
}