//FormAI DATASET v1.0 Category: QR code reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Define the maximum size of the QR code */
#define MAX_QR_SIZE 256

/* Define the QR code data structure */
typedef struct qr_code {
    uint16_t version;
    char ec_level;
    uint8_t modules[MAX_QR_SIZE][MAX_QR_SIZE];
} qr_code_t;

/* Function that reads a QR code from a file */
qr_code_t read_qr_code(const char* file_name) {
    qr_code_t qr_code;

    /* Open the file for reading */
    FILE* file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    /* Read the version and error correction level */
    fscanf(file, "%hu %c", &qr_code.version, &qr_code.ec_level);

    /* Read the QR code modules */
    for (int row = 0; row < qr_code.version * 4 + 17; row++) {
        for (int col = 0; col < qr_code.version * 4 + 17; col++) {
            /* Read the value and store in the modules array */
            fscanf(file, "%hhu", &qr_code.modules[row][col]);
        }
    }

    /* Close the file */
    fclose(file);

    return qr_code;
}

/* Function that prints a QR code to the console */
void print_qr_code(qr_code_t qr_code) {
    /* Step 1: Print the version and error correction level */
    printf("Version: %hu\n", qr_code.version);
    printf("Error correction level: %c\n", qr_code.ec_level);

    /* Step 2: Print the QR code modules */
    for (int row = 0; row < qr_code.version * 4 + 17; row++) {
        for (int col = 0; col < qr_code.version * 4 + 17; col++) {
            /* Determine the character to print based on the module value */
            char c = qr_code.modules[row][col] ? '#' : ' ';

            /* Print the character */
            printf("%c", c);
        }

        /* Print a newline character at the end of each row */
        printf("\n");
    }
}

/* Main function */
int main(int argc, char** argv) {
    /* Check if a filename was specified */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Read the QR code from the file */
    qr_code_t qr_code = read_qr_code(argv[1]);

    /* Print the QR code to the console */
    print_qr_code(qr_code);

    return 0;
}