//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

#define ERR_NO_QR_CODE "-1"
#define ERR_INVALID_QR_CODE "-2"
#define ERR_UNSUPPORTED_QR_CODE "-3"

typedef struct QRCode {
    uint8_t *data;
    size_t size;
} QRCode;

QRCode *read_qr_code(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        if (strcmp(line, ERR_NO_QR_CODE) == 0) {
            return NULL;
        } else if (strcmp(line, ERR_INVALID_QR_CODE) == 0) {
            return NULL;
        } else if (strcmp(line, ERR_UNSUPPORTED_QR_CODE) == 0) {
            return NULL;
        } else {
            QRCode *qr_code = malloc(sizeof(QRCode));
            qr_code->size = strlen(line);
            qr_code->data = malloc(qr_code->size + 1);
            strcpy(qr_code->data, line);
            return qr_code;
        }
    }
    return NULL;
}

void free_qr_code(QRCode *qr_code) {
    free(qr_code->data);
    free(qr_code);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <qr_code_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    QRCode *qr_code = read_qr_code(fp);
    if (qr_code == NULL) {
        fprintf(stderr, "Error: could not read QR code from file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("QR code data: %s\n", qr_code->data);

    free_qr_code(qr_code);
    fclose(fp);

    return EXIT_SUCCESS;
}