//FormAI DATASET v1.0 Category: QR code reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QR_SIZE 21
#define QR_POSITION(i,j) ((i)*QR_SIZE+(j))

#define QR_SYMBOL_BLACK '1'
#define QR_SYMBOL_WHITE '0'

typedef struct QRCode {
    char *data;
    int size;
} QRCode;

typedef struct QRReader {
    char *buffer;
    int buffer_size;
    int buffer_pos;
    QRCode qrcode;
} QRReader;

bool read_qrcode(QRReader *reader) {
    int i, j;
    char symbol;
    int row, col;
    int black_count = 0, white_count = 0;

    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            symbol = reader->buffer[QR_POSITION(i,j)];

            if (symbol == QR_SYMBOL_BLACK) {
                black_count++;
                row += i;
                col += j;
            } else if (symbol == QR_SYMBOL_WHITE) {
                white_count++;
            } else {
                printf("Error: invalid symbol %c at %d,%d\n", symbol, i, j);
                return false;
            }
        }
    }

    if (black_count == 0 || white_count == 0) {
        printf("Error: invalid QR code (not enough black or white symbols)\n");
        return false;
    }

    if ((row % black_count) != 0 || (col % black_count) != 0) {
        printf("Error: invalid QR code (black symbols not aligned)\n");
        return false;
    }

    reader->qrcode.size = black_count/3;
    reader->qrcode.data = (char*)malloc(reader->qrcode.size * reader->qrcode.size);

    for (i = 0; i < reader->qrcode.size; i++) {
        for (j = 0; j < reader->qrcode.size; j++) {
            symbol = reader->buffer[QR_POSITION(3*i+1, 3*j+1)];
            reader->qrcode.data[reader->qrcode.size*i+j] = symbol;
        }
    }

    return true;
}

int main() {
    QRReader reader;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    reader.buffer = (char*)malloc(QR_SIZE*QR_SIZE);
    reader.buffer_size = QR_SIZE*QR_SIZE;
    reader.buffer_pos = 0;

    while ((read = getline(&line, &len, stdin)) != -1) {
        if ((reader.buffer_pos + read-1) > reader.buffer_size) {
            printf("Error: input too large for buffer\n");
            return EXIT_FAILURE;
        }

        strncpy(&reader.buffer[reader.buffer_pos], line, read);
        reader.buffer_pos += read-1;
    }

    if (!read_qrcode(&reader)) {
        return EXIT_FAILURE;
    }

    printf("QR code size: %d\n", reader.qrcode.size);
    printf("QR code data:\n");

    for (int i = 0; i < reader.qrcode.size; i++) {
        for (int j = 0; j < reader.qrcode.size; j++) {
            printf("%c ", reader.qrcode.data[reader.qrcode.size*i+j]);
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}