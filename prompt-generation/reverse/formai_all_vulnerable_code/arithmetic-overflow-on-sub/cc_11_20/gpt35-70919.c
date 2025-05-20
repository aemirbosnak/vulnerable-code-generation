//FormAI DATASET v1.0 Category: QR code generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

static const char ALPHABET[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

// Use Euclidean algorithm to calculate GCD
int calculateGCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return calculateGCD(b, a % b);
    }
}

// Encode text into QR code
void generateQRCode(char *input, int blockSize) {
    // Convert text into ASCII values and store in array
    int textLength = strlen(input);
    int *asciiArray = (int *)malloc(textLength*sizeof(int));
    for (int i = 0; i < textLength; i++) {
        asciiArray[i] = (int)(input[i]);
    }

    // Calculate required number of rows and columns in QR code
    int numBlocks = (textLength % blockSize == 0) ? (textLength / blockSize) : (textLength / blockSize + 1);
    int numRows = numBlocks;
    int numCols = blockSize;

    // Allocate memory for QR code
    char **qrCode = (char **)malloc(numRows*sizeof(char *));
    for (int i = 0; i < numRows; i++) {
        qrCode[i] = (char *)malloc(numCols*sizeof(char));
    }

    // Generate random values for pad characters
    char *padChars = (char *)malloc(numRows*numCols*sizeof(char));
    for (int i = 0; i < numRows*numCols; i++) {
        padChars[i] = ALPHABET[rand() % strlen(ALPHABET)];
    }

    // Convert ASCII array into binary representation
    int *binaryArray = (int *)malloc(textLength*8*sizeof(int));
    for (int i = 0; i < textLength; i++) {
        for (int j = 0; j < 8; j++) {
            binaryArray[i*8 + j] = (asciiArray[i] >> (7 - j)) & 1;
        }
    }

    // Calculate Reed-Solomon error correction codes
    int maxErrorCorrection = 10;
    int numErrorCorrectionBlocks = maxErrorCorrection / 2;
    int totalDataBlocks = numBlocks + numErrorCorrectionBlocks;
    int blockLength = blockSize + maxErrorCorrection;
    int eccBlockLength = (blockLength - blockSize) / 2;
    int *rsGenerator = (int *)malloc(eccBlockLength*sizeof(int));
    int *rsRemainder = (int *)malloc(eccBlockLength*sizeof(int));
    for (int i = 0; i < eccBlockLength; i++) {
        rsGenerator[i] = 1 << (eccBlockLength - 1 - i);
    }
    int *binaryRSBlocks = (int *)malloc(totalDataBlocks*numCols*8*sizeof(int));
    for (int i = 0; i < numBlocks; i++) {
        int *dataBlock = &(binaryArray[i*blockSize*8]);
        int *rsBlock = &(binaryRSBlocks[i*numCols*8]);
        for (int j = 0; j < blockSize*8; j++) {
            rsBlock[j] = dataBlock[j];
        }
        for (int j = blockSize; j < blockLength; j++) {
            int remainderLength = eccBlockLength;
            int *remainder = (int *)malloc((remainderLength+1)*sizeof(int));
            for (int k = 0; k < remainderLength+1; k++) {
                remainder[k] = 0;
            }
            remainder[0] = rsBlock[j-blockSize];
            for (int k = 1; k < remainderLength+1; k++) {
                remainder[k] = rsRemainder[k-1];
            }
            for (int k = 0; k < remainderLength+1; k++) {
                if (remainder[k] != 0) {
                    int factor = calculateGCD(rsGenerator[0], remainder[k]);
                    int quotient = rsGenerator[0] / factor;
                    int scalar = quotient * remainder[k];
                    for (int l = 0; l < eccBlockLength; l++) {
                        remainder[l] = (remainder[l] * quotient) ^ (rsGenerator[l+1] * scalar);
                    }
                } else {
                    for (int l = 0; l < eccBlockLength; l++) {
                        remainder[l] = rsRemainder[l];
                    }
                }
            }
            for (int k = 0; k < eccBlockLength; k++) {
                rsRemainder[k] = remainder[k+1];
                rsBlock[j*8+k] = remainder[k];
            }
            free(remainder);
        }
    }

    // Interleave data and error correction blocks
    int *interleavedBlocks = (int *)malloc(totalDataBlocks*numCols*sizeof(int));
    for (int i = 0; i < numCols; i++) {
        for (int j = 0; j < totalDataBlocks; j++) {
            interleavedBlocks[i*totalDataBlocks+j] = binaryRSBlocks[(j*numCols+i)*8] \
                                                + 2*binaryRSBlocks[(j*numCols+i)*8+1] \
                                                + 4*binaryRSBlocks[(j*numCols+i)*8+2] \
                                                + 8*binaryRSBlocks[(j*numCols+i)*8+3] \
                                                + 16*binaryRSBlocks[(j*numCols+i)*8+4] \
                                                + 32*binaryRSBlocks[(j*numCols+i)*8+5] \
                                                + 64*binaryRSBlocks[(j*numCols+i)*8+6] \
                                                + 128*binaryRSBlocks[(j*numCols+i)*8+7];
        }
    }

    // Generate QR code by adding pad characters and interleaved binary values
    int padIndex = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if ((i == numRows-1) && (j == numCols-1)) {
                qrCode[i][j] = ' ';
            } else if ((j == numCols-1) && (i >= numBlocks)) {
                qrCode[i][j] = ' ';
            } else if ((i >= numBlocks) && (j >= blockLength)) {
                qrCode[i][j] = ' ';
            } else if ((i == numRows-1) && (j == numCols-2)) {
                qrCode[i][j] = '$';
            } else {
                qrCode[i][j] = padChars[padIndex];
                padIndex++;
            }
        }
    }
    int interleavedIndex = 0;
    for (int j = 0; j < numCols; j++) {
        for (int i = 0; i < numRows; i++) {
            if ((i == numRows-1) && (j == numCols-1)) {
                break;
            } else if ((j == numCols-1) && (i >= numBlocks)) {
                continue;
            } else if ((i >= numBlocks) && (j >= blockSize+maxErrorCorrection)) {
                continue;
            } else if ((i == numRows-1) && (j == numCols-2)) {
                continue;
            } else {
                qrCode[i][j] = ALPHABET[interleavedBlocks[interleavedIndex]];
                interleavedIndex++;
            }
        }
    }

    // Print QR code
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%c", qrCode[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free(asciiArray);
    for (int i = 0; i < numRows; i++) {
        free(qrCode[i]);
    }
    free(qrCode);
    free(padChars);
    free(binaryArray);
    free(rsGenerator);
    free(rsRemainder);
    free(binaryRSBlocks);
    free(interleavedBlocks);
}

int main() {
    char input[MAX_LENGTH];
    int blockSize;
    printf("Enter text to encode (max length %d): ", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);
    int len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0'; // Remove trailing newline
    }
    printf("Enter block size: ");
    scanf("%d", &blockSize);
    srand(time(NULL));
    generateQRCode(input, blockSize);
    return 0;
}