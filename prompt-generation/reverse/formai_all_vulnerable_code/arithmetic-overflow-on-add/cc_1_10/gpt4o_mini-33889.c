//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to generate a QR code
void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode;
    unsigned char *img_data;
    int width, height;
    FILE *fp;

    // Create the QR code
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Could not generate QR code. Is it too complex?\n");
        return;
    }

    // Get width and height of the QR Code
    width = qrcode->width;
    height = qrcode->width;

    // Allocate memory for the image data (1 byte per pixel)
    img_data = (unsigned char *)malloc(width * height);
    if (!img_data) {
        fprintf(stderr, "Unable to allocate memory for image data\n");
        QRcode_free(qrcode);
        return;
    }

    // Create the image data
    for (int i = 0; i < width * height; i++) {
        img_data[i] = (qrcode->data[i] & 1) ? 0 : 255; // Black (0) or White (255)
    }

    // Open file to write the image
    fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Cannot open file for writing: %s\n", filename);
        free(img_data);
        QRcode_free(qrcode);
        return;
    }

    // Write BMP Header
    fprintf(fp, "BM");
    int row_padded = (width * 3 + 3) & (~3);
    int size = row_padded * height + 54;
    fwrite(&(size), sizeof(size), 1, fp);
    int reserved = 0;
    fwrite(&(reserved), sizeof(reserved), 1, fp);
    int offset = 54; // Header size
    fwrite(&(offset), sizeof(offset), 1, fp);
    
    // DIB Header
    int dib_header_size = 40;
    fwrite(&(dib_header_size), sizeof(dib_header_size), 1, fp);
    fwrite(&(width), sizeof(width), 1, fp);
    fwrite(&(height), sizeof(height), 1, fp);
    
    // Color planes
    short color_planes = 1;
    fwrite(&(color_planes), sizeof(color_planes), 1, fp);
    
    // Bits per pixel
    short bpp = 24; // RGB
    fwrite(&(bpp), sizeof(bpp), 1, fp);
    
    // Compression Method (none)
    int compression = 0;
    fwrite(&(compression), sizeof(compression), 1, fp);
    
    // Image size (0 for uncompressed)
    int image_size = 0;
    fwrite(&(image_size), sizeof(image_size), 1, fp);
    
    // Horizontal resolution
    int h_res = 2835; // 72 DPI
    fwrite(&(h_res), sizeof(h_res), 1, fp);
    
    // Vertical resolution
    int v_res = 2835; // 72 DPI
    fwrite(&(v_res), sizeof(v_res), 1, fp);
    
    // Colors in color table
    int num_colors = 0; // No palette
    fwrite(&(num_colors), sizeof(num_colors), 1, fp);
    
    // Important colors (0 means all)
    int important_colors = 0;
    fwrite(&(important_colors), sizeof(important_colors), 1, fp);
    
    // Write the pixel data
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            // Writing pixel data
            unsigned char color[3] = {img_data[i * width + j], img_data[i * width + j], img_data[i * width + j]};
            fwrite(color, sizeof(unsigned char), 3, fp);
        }
        // Padding
        for (int j = 0; j < (row_padded - (width * 3)); j++) {
            fputc(0, fp);
        }
    }

    // Clean up
    free(img_data);
    fclose(fp);
    QRcode_free(qrcode);
    printf("QR Code generated and saved as %s\n", filename);
}

// Main function
int main() {
    char text[256];
    char filename[256];

    // User input for text
    printf("🔥🚨 SHOCKING QR CODE GENERATOR! 🚨🔥\n");
    printf("Enter the text you want to encode in the QR code: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove the newline character

    // User input for filename
    printf("Enter the filename to save the QR code (e.g., output.bmp): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove the newline character

    // Generate the QR code
    generate_qr_code(text, filename);
    return 0;
}