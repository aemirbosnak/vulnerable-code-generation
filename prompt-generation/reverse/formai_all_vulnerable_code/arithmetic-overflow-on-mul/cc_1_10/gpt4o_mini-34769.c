//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: active
#include <stdio.h>
#include <qrencode.h>

void generate_qr_code(const char *input_text) {
    QRcode *qrcode;
    unsigned char *qrcode_image;
    int width, size;

    // Generate the QR code
    qrcode = QRcode_encodeString(input_text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR Code for input: %s\n", input_text);
        return;
    }

    // Prepare image for display
    size = qrcode->width;
    width = size + 2; // Adding border
    qrcode_image = (unsigned char *)malloc(width * width);
    
    // Create the image
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            qrcode_image[(y + 1) * width + (x + 1)] = (qrcode->data[y * size + x] & 1) ? 1 : 0;
        }
    }

    // Print the QR code in a simple terminal format
    printf("Generated QR Code for: \"%s\"\n\n", input_text);
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            if (qrcode_image[y * width + x] == 1) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Clean up
    QRcode_free(qrcode);
    free(qrcode_image);
}

int main() {
    char input_text[256];

    printf("Welcome to the QR Code Generator!\n");
    printf("Please enter the text or URL to encode into a QR code: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Remove newline character from input
    size_t length = strlen(input_text);
    if (length > 0 && input_text[length - 1] == '\n') {
        input_text[length - 1] = '\0';
    }

    generate_qr_code(input_text);

    printf("\nThank you for using the QR Code Generator! Have a great day!\n");
    return 0;
}