//FormAI DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function prototype
void generate_qr(char *data, int size, char *file_path);

// Main function
int main()
{
    // Declare variables
    char data[100];
    int size;
    char file_path[200];

    // Get input from user
    printf("Enter the data to generate QR code: ");
    scanf("%s", data);
    printf("Enter the size of QR code: ");
    scanf("%d", &size);
    printf("Enter the file path to store QR code: ");
    scanf("%s", file_path);

    // Generate QR code
    generate_qr(data, size, file_path);

    // Success message
    printf("QR code generated successfully!\n");

    return 0;
}

// Function to generate QR code
void generate_qr(char *data, int size, char *file_path)
{
    QRcode *qr;

    // Create QR code
    qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Create image file
    FILE *fp = fopen(file_path, "wb");

    // Write QR code to file
    int i, j;
    for (i = 0; i < qr->width; i++) {
        for (j = 0; j < qr->width; j++) {
            int color = qr->data[i * qr->width + j] & 1;
            fprintf(fp, "%c%c%c", color ? 0 : 255, color ? 0 : 255, color ? 0 : 255);
        }
        fprintf(fp, "\n");
    }

    // Free memory
    fclose(fp);
    QRcode_free(qr);
}