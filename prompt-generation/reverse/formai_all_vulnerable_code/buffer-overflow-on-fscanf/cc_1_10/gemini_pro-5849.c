//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct qr_code {
    int version;
    int size;
    int data_size;
    int error_correction_level;
    char *data;
} qr_code;

qr_code *qr_code_init(int version, int error_correction_level) {
    qr_code *qr = malloc(sizeof(qr_code));
    qr->version = version;
    qr->size = 4 * version + 17;
    qr->data_size = qr->size * qr->size;
    qr->error_correction_level = error_correction_level;
    qr->data = malloc(qr->data_size);
    return qr;
}

void qr_code_free(qr_code *qr) {
    free(qr->data);
    free(qr);
}

bool qr_code_read(qr_code *qr, FILE *fp) {
    if (qr->version == 0) {
        // Read the version number from the file.
        int version;
        if (fscanf(fp, "%d", &version) != 1) {
            return false;
        }
        qr->version = version;
        qr->size = 4 * version + 17;
        qr->data_size = qr->size * qr->size;
        qr->data = malloc(qr->data_size);
    }

    // Read the error correction level from the file.
    int error_correction_level;
    if (fscanf(fp, "%d", &error_correction_level) != 1) {
        return false;
    }
    qr->error_correction_level = error_correction_level;

    // Read the data from the file.
    for (int i = 0; i < qr->data_size; i++) {
        int data;
        if (fscanf(fp, "%d", &data) != 1) {
            return false;
        }
        qr->data[i] = data;
    }

    return true;
}

void qr_code_print(qr_code *qr) {
    for (int i = 0; i < qr->size; i++) {
        for (int j = 0; j < qr->size; j++) {
            printf("%d ", qr->data[i * qr->size + j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    qr_code *qr = qr_code_init(0, 0);
    if (!qr_code_read(qr, fp)) {
        printf("Error reading QR code from file.\n");
        return EXIT_FAILURE;
    }

    qr_code_print(qr);

    qr_code_free(qr);

    fclose(fp);

    return EXIT_SUCCESS;
}