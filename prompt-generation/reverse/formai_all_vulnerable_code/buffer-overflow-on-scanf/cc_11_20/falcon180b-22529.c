//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <ctype.h>

int main() {
    // Declare variables
    char hexadecimal[100], binary[100], decimal[100];
    int i, j, k, length;

    // Prompt user to enter a hexadecimal number
    printf("Enter a hexadecimal number: ");

    // Read input from user
    scanf("%s", hexadecimal);

    // Remove any leading or trailing spaces
    hexadecimal[strcspn(hexadecimal, "\n")] = '\0';

    // Check if input is a valid hexadecimal number
    for (i = 0; i < strlen(hexadecimal); i++) {
        if (!isxdigit(hexadecimal[i])) {
            printf("Invalid hexadecimal number.\n");
            return 0;
        }
    }

    // Convert hexadecimal to binary
    length = strlen(hexadecimal);
    for (i = 0, j = 0; i < length; i++) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            binary[j] = hexadecimal[i] - '0';
        }
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            binary[j] = hexadecimal[i] - 'A' + 10;
        }
        else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            binary[j] = hexadecimal[i] - 'a' + 10;
        }
        j++;
    }

    // Convert binary to decimal
    length = strlen(binary);
    for (i = 0, j = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal[j] = '1';
        }
        else {
            decimal[j] = '0';
        }
        j++;
    }

    // Print the results
    printf("Hexadecimal: %s\n", hexadecimal);
    printf("Binary:     %s\n", binary);
    printf("Decimal:   %s\n", decimal);

    return 0;
}