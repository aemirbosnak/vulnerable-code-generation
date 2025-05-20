//FormAI DATASET v1.0 Category: QR code reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_QR_CODE_LENGTH 1000

/**
 * This program reads a QR code from a file and converts it into a binary representation.
 * The QR code is read in as a string of characters. Each character can have a value of
 * anything between 0-255. The binary representation of this input is a sequence of bits
 * of length 8 (one byte) each. We read the string in as a sequence of ASCII characters
 * and convert each character to its corresponding bit sequence. The binary sequence is
 * then written to another file.
 */

// Converts a string of hexadecimal characters to its decimal representation
int hex_to_dec(char c)
{
    if (isdigit(c))
        return c - '0';
    else
        return tolower(c) - 'a' + 10;
}

// Reads a QR code from a file and returns its binary representation
void read_file(char* filename)
{
    FILE* file;
    char* qr_code = (char*) malloc(MAX_QR_CODE_LENGTH * sizeof(char));
    char* binary = (char*) malloc(MAX_QR_CODE_LENGTH * 8 * sizeof(char));
    char hex[3];
    hex[2] = '\0';
    int bit_count = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("ERROR: Unable to open file %s\n", filename);
        exit(1);
    }
    
    if (fgets(qr_code, MAX_QR_CODE_LENGTH, file) == NULL) {
        printf("ERROR: Could not read the QR code from file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < strlen(qr_code); i += 2) {
        hex[0] = qr_code[i];
        hex[1] = qr_code[i+1];
        int decimal = hex_to_dec(hex[0]) * 16 + hex_to_dec(hex[1]);
        for (int j = 7; j >= 0; j--) {
            binary[bit_count++] = ((decimal >> j) & 1) + '0';
        }
    }

    fclose(file);

    // write the binary sequence to a new file called "binary.txt"
    FILE* output = fopen("binary.txt", "w");
    if (output == NULL) {
        printf("ERROR: Unable to open file binary.txt\n");
        exit(1);
    }

    fprintf(output, "%s", binary);

    fclose(output);
    free(qr_code);
    free(binary);
}

int main()
{
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter filename containing QR code: ");
    scanf("%s", filename);

    read_file(filename);

    printf("Conversion to binary is complete. The result is stored in binary.txt\n");

    return 0;
}