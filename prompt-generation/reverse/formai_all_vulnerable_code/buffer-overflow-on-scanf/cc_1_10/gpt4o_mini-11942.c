//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void print_qr(const QRcode *qrcode) {
    int size = qrcode->width;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            unsigned char mod = qrcode->data[y * size + x] & 1;
            putchar(mod ? '#' : ' ');
        }
        putchar('\n');
    }
}

void generate_qr_code(const char *input) {
    QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode) {
        print_qr(qrcode);
        QRcode_free(qrcode);
    } else {
        fprintf(stderr, "Failed to generate QR Code!\n");
    }
}

void display_menu() {
    printf("=================================\n");
    printf("       QR Code Generator        \n");
    printf("=================================\n");
    printf("1. Generate QR Code\n");
    printf("2. Exit\n");
    printf("=================================\n");
    printf("Choose an option (1-2): ");
}

int main() {
    char input[256];
    int choice;

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number!\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }

        if (choice == 1) {
            printf("Enter text to encode in QR Code: ");
            while (getchar() != '\n'); // clear the input buffer before reading a string
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0; // remove newline character if it exists
            printf("Generating QR Code for: %s\n", input);
            generate_qr_code(input);
        } else if (choice == 2) {
            printf("Exiting the QR Code Generator. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}