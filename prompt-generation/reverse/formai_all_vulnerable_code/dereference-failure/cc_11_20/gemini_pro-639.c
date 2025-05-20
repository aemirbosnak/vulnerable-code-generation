//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_VERSION 1
#define QR_SIZE 21

// The following arrays define the Reed-Solomon error correction codes for QR codes.
const int RS_ECC_CODEWORDS[4] = {7, 10, 13, 15};
const int RS_ECC_BLOCKS[4] = {1, 1, 1, 1};
const int RS_ECC_DATA_CODEWORDS[4] = {19, 16, 13, 9};

// The following arrays define the data capacity of QR codes.
const int QR_DATA_CAPACITY[4] = {17, 32, 53, 78};

// The following arrays define the pattern for the finder patterns.
const int FINDER_PATTERN[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

// The following arrays define the pattern for the alignment patterns.
const int ALIGNMENT_PATTERN[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

// The following arrays define the pattern for the timing patterns.
const int TIMING_PATTERN[7][7] = {
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1}
};

// The following function generates a QR code.
void generate_qr_code(const char *data, int data_length) {
    // Calculate the version of the QR code.
    int version = 1;
    while (QR_DATA_CAPACITY[version] < data_length) {
        version++;
    }

    // Calculate the size of the QR code.
    int size = QR_SIZE + (version * 4);

    // Create the QR code matrix.
    int qr_code[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            qr_code[i][j] = 0;
        }
    }

    // Add the finder patterns.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            qr_code[i][j] = FINDER_PATTERN[i][j];
            qr_code[i][size - 1 - j] = FINDER_PATTERN[i][j];
            qr_code[size - 1 - i][j] = FINDER_PATTERN[i][j];
            qr_code[size - 1 - i][size - 1 - j] = FINDER_PATTERN[i][j];
        }
    }

    // Add the alignment patterns.
    if (version >= 2) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                qr_code[i][6 + (j * 3)] = ALIGNMENT_PATTERN[i][j];
                qr_code[i][size - 1 - (6 + (j * 3))] = ALIGNMENT_PATTERN[i][j];
                qr_code[size - 1 - i][6 + (j * 3)] = ALIGNMENT_PATTERN[i][j];
                qr_code[size - 1 - i][size - 1 - (6 + (j * 3))] = ALIGNMENT_PATTERN[i][j];
            }
        }
    }

    // Add the timing patterns.
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            qr_code[6 + (i * 3)][j] = TIMING_PATTERN[i][j];
            qr_code[size - 1 - (6 + (i * 3))][j] = TIMING_PATTERN[i][j];
            qr_code[j][6 + (i * 3)] = TIMING_PATTERN[i][j];
            qr_code[j][size - 1 - (6 + (i * 3))] = TIMING_PATTERN[i][j];
        }
    }

    // Add the data.
    int data_index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i >= 9 && i <= size - 9 && j >= 9 && j <= size - 9) {
                if ((i + j) % 2 == 0) {
                    qr_code[i][j] = (data[data_index] >> 7) & 1;
                    data_index++;
                } else {
                    qr_code[i][j] = (data[data_index] >> 6) & 1;
                    data_index++;
                }
            }
        }
    }

    // Add the error correction codes.
    int ecc_codewords = RS_ECC_CODEWORDS[version - 1];
    int ecc_blocks = RS_ECC_BLOCKS[version - 1];
    int ecc_data_codewords = RS_ECC_DATA_CODEWORDS[version - 1];
    int ecc_index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i >= 9 && i <= size - 9 && j >= 9 && j <= size - 9) {
                if ((i + j) % 2 == 0) {
                    qr_code[i][j] |= ((data[data_index] >> 5) & 1) << ecc_index;
                    ecc_index++;
                    if (ecc_index == ecc_codewords) {
                        ecc_index = 0;
                        data_index++;
                    }
                } else {
                    qr_code[i][j] |= ((data[data_index] >> 4) & 1) << ecc_index;
                    ecc_index++;
                    if (ecc_index == ecc_codewords) {
                        ecc_index = 0;
                        data_index++;
                    }
                }
            }
        }
    }

    // Print the QR code.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qr_code[i][j]) {
                printf("█");
            } else {
                printf("░");
            }
        }
        printf("\n");
    }
}

// The main function.
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s data\n", argv[0]);
        return 1;
    }

    const char *data = argv[1];
    int data_length = strlen(data);

    generate_qr_code(data, data_length);

    return 0;
}