//FormAI DATASET v1.0 Category: QR code generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <qrencode.h>

void generate_qr_code(char *string, int size, char *filename) {
    QRcode *qr;

    qr = QRcode_encodeString(string, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);

    FILE *file = fopen(filename, "wb");
    if(!file) {
        printf("error: could not create file '%s'\n", filename);
        QRcode_free(qr);

        return;
    }

    for(int i = 0; i < qr->width; i++) {
        fwrite(qr->data + i * qr->width, 1, qr->width, file);
    }

    fclose(file);
    QRcode_free(qr);

    printf("Successfully generated QR code for '%s' and saved to '%s'\n", string, filename);
}

int main() {
    char string[1000];
    char filename[1000];
    int size;
    
    printf("Welcome to the QR code generator!\n");
    printf("Please enter the string you want to generate a code for: ");
    fgets(string, 1000, stdin);

    printf("Please enter the size of the QR code (in pixels): ");
    scanf("%d", &size);

    printf("Please enter the filename of the output file (with .png extension): ");
    scanf("%s", filename);

    // Remove newline character from string
    string[strlen(string)-1] = '\0';

    // Generate the QR code
    generate_qr_code(string, size, filename);

    return 0;
}