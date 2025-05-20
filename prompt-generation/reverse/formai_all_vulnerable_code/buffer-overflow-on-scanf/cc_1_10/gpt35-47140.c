//FormAI DATASET v1.0 Category: QR code generator ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QR_WIDTH 21 // QR code width
#define QR_HEIGHT 21 // QR code height
#define ERROR_CODE -1 // error code for unsuccessful operation

// function to generate the QR code
int generate_qr_code(char *data, char *qr_code[QR_HEIGHT]) {
    int data_length = strlen(data); // length of input data
    int encoding_length = data_length + 2; // length of encoded data
    char *encoding = (char *) calloc(encoding_length, sizeof(char)); // memory allocation for encoded data
    if (encoding == NULL) {
        printf("Error: Could not allocate memory for encoded data.\n");
        return ERROR_CODE;
    }
    encoding[0] = '0'; // encoding mode
    encoding[1] = '1'; // character count indicator
    strcat(encoding, data); // append the input data to the encoded data

    // fill the QR code array with spaces
    for (int i = 0; i < QR_HEIGHT; i++) {
        for (int j = 0; j < QR_WIDTH; j++) {
            qr_code[i][j] = ' ';
        }
    }

    // fill the quiet zone with black squares
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < QR_WIDTH; j++) {
            qr_code[i][j] = 'X';
            qr_code[QR_HEIGHT - i - 1][j] = 'X';
            qr_code[j][i] = 'X';
            qr_code[j][QR_WIDTH - i - 1] = 'X';
        }
    }

    // fill the alignment patterns with black squares
    qr_code[3][3] = 'X';
    qr_code[3][QR_WIDTH - 4] = 'X';
    qr_code[QR_HEIGHT - 4][3] = 'X';
    qr_code[QR_HEIGHT - 4][QR_WIDTH - 4] = 'X';

    // fill the timing patterns with black and white squares
    for (int i = 8; i < QR_WIDTH - 8; i += 2) {
        qr_code[6][i] = 'X';
        qr_code[i][6] = 'X';
        qr_code[QR_HEIGHT - 7][i] = 'X';
        qr_code[i][QR_WIDTH - 7] = 'X';
    }
    for (int i = 9; i < QR_WIDTH - 8; i += 2) {
        qr_code[6][i] = ' ';
        qr_code[i][6] = ' ';
        qr_code[QR_HEIGHT - 7][i] = ' ';
        qr_code[i][QR_WIDTH - 7] = ' ';
    }

    // fill the format information with black and white squares
    for (int i = 0; i < 7; i++) {
        qr_code[8][i] = 'X';
        qr_code[i][8] = 'X';
        qr_code[QR_HEIGHT - 1 - i][8] = 'X';
        qr_code[8][QR_WIDTH - 1 - i] = 'X';
        qr_code[QR_HEIGHT - 8][i] = 'X';
        qr_code[i][QR_WIDTH - 8] = 'X';
    }
    qr_code[7][8] = ' ';
    qr_code[8][7] = ' ';
    qr_code[QR_HEIGHT - 8][8] = ' ';
    qr_code[8][QR_WIDTH - 8] = ' ';

    // fill the version information with black and white squares
    if (QR_WIDTH >= 25) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                qr_code[QR_HEIGHT - 11 + j][8 + i] = 'X';
                qr_code[8 + i][QR_WIDTH - 11 + j] = 'X';
            }
        }
    }

    // fill the encoded data with black and white squares
    int row = QR_HEIGHT - 1; // starting from the bottom-left corner
    int col = QR_WIDTH - 1;
    int bit = 0; // starting from the most significant bit of the first byte
    while (encoding_length > 0) {
        if (qr_code[row][col] == ' ') {
            qr_code[row][col] = (encoding[0] >> (7 - bit)) & 1 ? 'X' : ' ';
            bit++;
            if (bit == 8) {
                bit = 0;
                encoding++;
                encoding_length--;
            }
        }
        if (row % 2 == 0) { // scan the rows from right to left
            col--;
            if (col == 6) { // skip the timing pattern at column 6
                col--;
            }
        } else { // scan the rows from left to right
            col++;
            if (col == QR_WIDTH) { // reach the right boundary
                row--;
                col--;
                if (col == 6) { // skip the timing pattern at column 6
                    col--;
                }
            }
        }
    }

    return 0; // return 0 for successful operation
}

// function to print the QR code
void print_qr_code(char *qr_code[QR_HEIGHT]) {
    for (int i = 0; i < QR_HEIGHT; i++) {
        for (int j = 0; j < QR_WIDTH; j++) {
            printf("%c", qr_code[i][j]);
        }
        printf("\n");
    }
}

// main function
int main() {
    char data[1024]; // buffer for input data
    printf("Enter the data to be encoded: ");
    scanf("%s", data); // read input data from stdin
    char *qr_code[QR_HEIGHT]; // declare the QR code array
    for (int i = 0; i < QR_HEIGHT; i++) { // memory allocation for each row of the array
        qr_code[i] = (char *) calloc(QR_WIDTH, sizeof(char));
        if (qr_code[i] == NULL) {
            printf("Error: Could not allocate memory for QR code.\n");
            return ERROR_CODE;
        }
    }
    int result = generate_qr_code(data, qr_code); // generate the QR code
    if (result == 0) { // print the QR code if successful
        print_qr_code(qr_code);
    }
    for (int i = 0; i < QR_HEIGHT; i++) { // free the memory allocated for each row
        free(qr_code[i]);
    }
    free(qr_code); // free the memory allocated for the QR code array
    return result; // return the result of generate_qr_code()
}