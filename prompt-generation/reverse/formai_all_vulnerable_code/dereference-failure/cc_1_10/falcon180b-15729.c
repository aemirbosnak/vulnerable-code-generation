//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QR_SIZE 10000
#define MAX_INPUT_SIZE 10000

struct qr_code {
    int size;
    char *data;
};

struct qr_code *create_qr_code(char *input_data) {
    struct qr_code *qrcode = (struct qr_code *)malloc(sizeof(struct qr_code));
    if (!qrcode) {
        printf("Error: Could not allocate memory for QR code.\n");
        exit(1);
    }

    qrcode->size = strlen(input_data);
    if (qrcode->size > MAX_QR_SIZE) {
        printf("Error: Input data too long. Maximum QR code size is %d characters.\n", MAX_QR_SIZE);
        exit(1);
    }

    qrcode->data = (char *)malloc(qrcode->size + 1);
    if (!qrcode->data) {
        printf("Error: Could not allocate memory for QR code data.\n");
        exit(1);
    }

    strcpy(qrcode->data, input_data);

    return qrcode;
}

void print_qr_code(struct qr_code *qrcode) {
    int i, j;
    for (i = 0; i < qrcode->size; i++) {
        if (isalpha(qrcode->data[i])) {
            printf("%c", tolower(qrcode->data[i]));
        } else {
            printf("%c", qrcode->data[i]);
        }
    }
}

int main() {
    char input_data[MAX_INPUT_SIZE];
    printf("Enter input data for QR code: ");
    fgets(input_data, MAX_INPUT_SIZE, stdin);
    input_data[strcspn(input_data, "\n")] = '\0'; // Remove newline character

    struct qr_code *qrcode = create_qr_code(input_data);
    if (qrcode) {
        print_qr_code(qrcode);
        printf("\n");
        free(qrcode->data);
        free(qrcode);
    }

    return 0;
}