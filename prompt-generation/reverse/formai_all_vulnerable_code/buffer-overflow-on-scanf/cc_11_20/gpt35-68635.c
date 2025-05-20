//FormAI DATASET v1.0 Category: QR code generator ; Style: Ada Lovelace
/* A QR code generator in the style of Ada Lovelace */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 500

// Function to generate the QR code
void generate_code(char* data, int size) {

    // Add the necessary QR code header and format information
    char header[MAX_SIZE] = "0100";
    char format_info[MAX_SIZE] = "1010011010";
    strcat(data, "0000"); // Add padding to the data

    // Calculate the error correction code using the Reed-Solomon algorithm
    char ecc[MAX_SIZE] = "11010011101100";
    for (int i = 0; i < strlen(data); i++) {
        char c = data[i];
        for (int j = 0; j < 8; j++) {
            char b = ((c >> (7 - j)) & 0x01) == 1 ? '1' : '0';
            char d = ecc[j];
            if (b == '1' && d == '1' || b == '0' && d == '0') {
                ecc[j] = '0';
            } else {
                ecc[j] = '1';
            }
        }
    }

    // Merge the data, error correction code, and format information into one string
    char merged[MAX_SIZE];
    strcpy(merged, data);
    strcat(merged, ecc);
    strcat(merged, format_info);

    // Add the remainder bits to the string
    while (strlen(merged) % 8 != 0) {
        strcat(merged, "0");
    }

    // Divide the string into 8-bit symbols and convert each symbol to a hex code
    char hex[MAX_SIZE];
    for (int i = 0; i < strlen(merged); i+=8) {
        char symbol[9];
        strncpy(symbol, merged+i, 8);
        symbol[8] = '\0';
        char* end;
        int value = strtol(symbol, &end, 2);
        sprintf(hex+i/4, "%01X", value);
    }

    // Print the QR code as a matrix of hex codes
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 && j >= 0 && j < 6 || j == 0 && i >= 0 && i < 6 || i == 6 && j >= 0 && j < 8 || j == 6 && i >= 0 && i < 8 || i == size - 1 && j >= size - 7 && j < size || j == size - 1 && i >= size - 7 && i < size) {
                printf("  "); // Add quiet zone
            } else {
                int index = (i-8)/4*(size-16)+(j-8)/4;
                printf("%c%c", hex[index*2], hex[index*2+1]); // Print the hex code
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    char data[MAX_SIZE];
    int size;

    printf("Enter data to generate QR code: "); // Prompt user for data
    fgets(data, MAX_SIZE, stdin);

    printf("Enter size of QR code (10 to 50): "); // Prompt user for size
    scanf("%d", &size);

    if (size < 10 || size > 50) { // Check validity of size
        printf("Invalid size.\n");
        exit(1);
    }

    generate_code(data, size); // Generate the QR code

    return 0;
}