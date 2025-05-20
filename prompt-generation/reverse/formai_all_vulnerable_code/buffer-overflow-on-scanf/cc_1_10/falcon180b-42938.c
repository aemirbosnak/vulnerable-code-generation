//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char input_string[MAX_SIZE];
    char output_string[MAX_SIZE];
    int i, j;
    int num_bits;
    int bit_position;
    int bit_value;
    int num_bytes;
    int byte_position;
    int byte_value;
    int flag;

    // Prompt user to enter input string
    printf("Enter input string: ");
    fgets(input_string, MAX_SIZE, stdin);

    // Remove newline character from input string
    input_string[strcspn(input_string, "\n")] = '\0';

    // Prompt user to enter number of bits to extract
    printf("Enter number of bits to extract: ");
    scanf("%d", &num_bits);

    // Check if input string is empty
    if (input_string[0] == '\0') {
        printf("Error: Input string is empty.\n");
        exit(1);
    }

    // Check if number of bits to extract is greater than or equal to string length
    if (num_bits >= strlen(input_string)) {
        printf("Error: Number of bits to extract is greater than or equal to string length.\n");
        exit(1);
    }

    // Initialize output string
    output_string[0] = '\0';

    // Extract specified number of bits from input string
    for (i = 0, bit_position = 0; i < strlen(input_string); i++) {
        flag = 0;
        for (j = 0; j < 8; j++) {
            if ((input_string[i] >> (7 - j)) & 1) {
                // Check if bit position exceeds output string length
                if (bit_position >= num_bits) {
                    break;
                }
                // Append bit to output string
                strcat(output_string, "1");
                bit_position++;
            } else {
                // Append 0 to output string
                strcat(output_string, "0");
            }
        }
    }

    // Pad output string with 0's if necessary
    num_bytes = (num_bits + 7) / 8;
    if (strlen(output_string) < num_bytes) {
        for (i = strlen(output_string); i < num_bytes; i++) {
            strcat(output_string, "0");
        }
    }

    // Convert output string to integer
    sscanf(output_string, "%d", &byte_value);

    // Convert integer to byte array
    byte_position = 0;
    for (i = 0; i < num_bytes; i++) {
        output_string[byte_position++] = byte_value & 0xff;
        byte_value >>= 8;
    }

    // Print output string
    printf("Output string: %s\n", output_string);

    return 0;
}