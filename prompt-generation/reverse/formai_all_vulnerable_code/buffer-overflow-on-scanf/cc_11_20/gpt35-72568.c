//FormAI DATASET v1.0 Category: QR code generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the size of the QR code
#define QR_SIZE 10

// define the version of the QR code
#define QR_VERSION 1

// define the mathematical constants for the generator polynomial
#define GEN_POLY_CONST_A 2
#define GEN_POLY_CONST_B 3
#define GEN_POLY_CONST_C 1
#define GEN_POLY_CONST_D 1

/**
 * Generate QR code matrix
 */
int **generateQRCode(unsigned int message) {

    // allocate memory for the QR code matrix
    int **qrCode = (int **) malloc(sizeof(int *) * QR_SIZE);
    for (int i = 0; i < QR_SIZE; i++) {
        qrCode[i] = (int *) malloc(sizeof(int) * QR_SIZE);
    }

    // initialize the QR code matrix to all zeros
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            qrCode[i][j] = 0;
        }
    }

    // generate the data codewords
    int dataCodewords[QR_SIZE * QR_SIZE];
    for (int i = 0; i < QR_SIZE * QR_SIZE; i++) {
        dataCodewords[i] = message % 2;
        message = message / 2;
    }

    // calculate the number of error correction codewords
    int numErrorCorrectionCodewords = 10 * QR_VERSION + 10;
    int numTotalDataCodewords = QR_SIZE * QR_SIZE - numErrorCorrectionCodewords;

    // split the data codewords into blocks for easier processing
    int numBlocks = numTotalDataCodewords / QR_SIZE;
    int dataBlocks[numBlocks][QR_SIZE];
    int dataIndex = 0;
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            dataBlocks[i][j] = dataCodewords[dataIndex];
            dataIndex++;
        }
    }

    // calculate the error correction codewords for each block and combine into single array
    int errorCorrectionCodewords[numErrorCorrectionCodewords];
    for (int i = 0; i < numBlocks; i++) {

        // create a copy of each block plus extra zeros for the error correction codewords
        int block[QR_SIZE + GEN_POLY_CONST_D];
        for (int j = 0; j < QR_SIZE; j++) {
            block[j] = dataBlocks[i][j];
        }
        for (int j = QR_SIZE; j < QR_SIZE + GEN_POLY_CONST_D; j++) {
            block[j] = 0;
        }

        // perform polynomial division to calculate the error correction codewords
        for (int j = 0; j < GEN_POLY_CONST_D; j++) {
            int factor = block[0];
            if (factor == 0) {
                for (int k = 0; k < QR_SIZE + GEN_POLY_CONST_D - 1; k++) {
                    block[k] = block[k + 1];
                }
                block[QR_SIZE + GEN_POLY_CONST_D - 1] = 0;
            } else {
                for (int k = 0; k < QR_SIZE + GEN_POLY_CONST_D - 1; k++) {
                    int curr = block[k];
                    int next = block[k + 1];
                    block[k] = next;
                    block[k + 1] = (curr + factor * GEN_POLY_CONST_A) % 2;
                }
            }
        }

        // combine the error correction codewords with the data codewords for this block
        for (int j = 0; j < GEN_POLY_CONST_D; j++) {
            errorCorrectionCodewords[numBlocks * j + i] = block[QR_SIZE + j];
        }
    }

    // interleave the data codewords and error correction codewords
    int interleavedData[numTotalDataCodewords];
    int interleavedError[numErrorCorrectionCodewords];
    int dataIndexes[numBlocks];
    int errorIndexes[numBlocks];
    for (int i = 0; i < numBlocks; i++) {
        dataIndexes[i] = i;
        errorIndexes[i] = i * GEN_POLY_CONST_D;
    }
    for (int i = 0; i < numTotalDataCodewords; i++) {
        int blockIndex = i % numBlocks;
        if (i / numBlocks < QR_SIZE) {
            interleavedData[i] = dataBlocks[dataIndexes[blockIndex]][i / numBlocks];
        } else {
            interleavedError[i - QR_SIZE * numBlocks] = errorCorrectionCodewords[errorIndexes[blockIndex]];
            errorIndexes[blockIndex]++;
        }
        dataIndexes[blockIndex]++;
    }

    // add the interleaved data and error correction codewords to the QR code matrix
    int dataIdx = 0;
    int errorIdx = 0;
    for (int i = QR_SIZE - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            // even row
            for (int j = 0; j < QR_SIZE; j++) {
                if (qrCode[i][j] == 0 && dataIdx < numTotalDataCodewords) {
                    qrCode[i][j] = interleavedData[dataIdx];
                    dataIdx++;
                } else if (qrCode[i][j] == 0 && errorIdx < numErrorCorrectionCodewords) {
                    qrCode[i][j] = interleavedError[errorIdx];
                    errorIdx++;
                }
            }
        } else {
            // odd row (reverse order)
            for (int j = QR_SIZE - 1; j >= 0; j--) {
                if (qrCode[i][j] == 0 && dataIdx < numTotalDataCodewords) {
                    qrCode[i][j] = interleavedData[dataIdx];
                    dataIdx++;
                } else if (qrCode[i][j] == 0 && errorIdx < numErrorCorrectionCodewords) {
                    qrCode[i][j] = interleavedError[errorIdx];
                    errorIdx++;
                }
            }
        }
    }

    // return the generated QR code matrix
    return qrCode;
}

/**
 * Main function
 */
int main() {

    // get input message
    unsigned int message;
    printf("Enter a message to generate QR code: ");
    scanf("%ud", &message);

    // generate the QR code and print to console
    int **qrCode = generateQRCode(message);
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            printf("%d", qrCode[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < QR_SIZE; i++) {
        free(qrCode[i]);
    }
    free(qrCode);

    // return success
    return 0;
}