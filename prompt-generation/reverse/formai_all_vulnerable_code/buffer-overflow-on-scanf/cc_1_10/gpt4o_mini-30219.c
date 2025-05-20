//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define VERSION 1
#define ERROR_CORRECTION_LEVEL QR_ECLEVEL_L
#define SIZE 10

void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(text, VERSION, ERROR_CORRECTION_LEVEL, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code.\n");
        return;
    }

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Unable to open file for writing: %s\n", filename);
        QRcode_free(qrcode);
        return;
    }

    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            unsigned char byte = (qrcode->data[y * qrcode->width + x] & 1) ? 0 : 255;
            fwrite(&byte, 1, 1, fp);
        }
    }
    fclose(fp);
    QRcode_free(qrcode);
}

void display_qr_code(const char *text) {
    QRcode *qrcode = QRcode_encodeString(text, VERSION, ERROR_CORRECTION_LEVEL, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code.\n");
        return;
    }

    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            if (qrcode->data[y * qrcode->width + x] & 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    QRcode_free(qrcode);
}

void print_menu() {
    printf("QR Code Generator Menu:\n");
    printf("1. Generate QR Code\n");
    printf("2. Display QR Code\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

void handle_user_input() {
    int choice;
    char text[256];
    char filename[256];

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // Clear the newline character left in the input buffer

        switch (choice) {
            case 1:
                printf("Enter the text to encode: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character

                printf("Enter the output filename (without extension): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                strcat(filename, ".png");

                generate_qr_code(text, filename);
                printf("QR Code generated and saved as %s\n", filename);
                break;

            case 2:
                printf("Enter the text to display in QR code: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character

                printf("Displaying QR Code for: %s\n", text);
                display_qr_code(text);
                break;

            case 0:
                printf("Exiting program.\n");
                return;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the QR Code Generator!\n");
    handle_user_input();
    return 0;
}