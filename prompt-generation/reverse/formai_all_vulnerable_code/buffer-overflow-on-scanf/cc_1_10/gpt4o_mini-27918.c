//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERSIONS 100

// Function declarations
void convertToHex(int decimal);
void displayStatistics(int count, int maxVal, float average);

int main() {
    int decimal, count = 0, maxVal = 0;
    float sum = 0.0;

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");

    while (1) {
        printf("\nPlease enter a decimal number (negative number to exit): ");
        scanf("%d", &decimal);

        if (decimal < 0) {
            break; // Exit condition
        }

        sum += decimal;
        count++;

        if (decimal > maxVal) {
            maxVal = decimal; // Update maximum value
        }

        // Convert and display the hexadecimal value
        convertToHex(decimal);
    }

    // Display statistics if at least one conversion occured
    if (count > 0) {
        float average = sum / count;
        displayStatistics(count, maxVal, average);
    } else {
        printf("No conversions were made.\n");
    }

    printf("Thank you for using the converter! Goodbye!\n");
    return 0;
}

void convertToHex(int decimal) {
    printf("Decimal: %d -> Hexadecimal: %X\n", decimal, decimal);
}

void displayStatistics(int count, int maxVal, float average) {
    printf("\n--- Conversion Statistics ---\n");
    printf("Total conversions: %d\n", count);
    printf("Maximum value converted: %d\n", maxVal);
    printf("Average value entered: %.2f\n", average);
}