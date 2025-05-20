//FormAI DATASET v1.0 Category: QR code generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <qrencode.h>

#define MAX_INPUT_SIZE 1024
#define MAX_QR_SIZE 200

bool generate_qr_code(char *input_data, char *output_filename) {
    // Generate QR Code using the input data
    QRcode *qr = QRcode_encodeString(input_data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Check if QR Code generation was successful
    if (qr == NULL) {
        fprintf(stderr, "Failed to generate QR Code\n");
        return false;
    }

    // Create output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Failed to create output file\n");
        QRcode_free(qr);
        return false;
    }

    // Write QR Code to output file
    for (int i = 0; i < qr->width; i++) {
        for (int j = 0; j < qr->width; j++) {
            if (qr->data[i * qr->width + j] & 1) {
                fprintf(output_file, "██");
            } else {
                fprintf(output_file, "  ");
            }
        }
        fprintf(output_file, "\n");
    }

    // Free memory and close output file
    fclose(output_file);
    QRcode_free(qr);
    return true;
}

int main(int argc, char *argv[]) {
    char input_data[MAX_INPUT_SIZE], output_filename[MAX_INPUT_SIZE];

    // Read input data from user
    printf("Enter your text / URL: ");
    fgets(input_data, MAX_INPUT_SIZE, stdin);
    input_data[strlen(input_data)-1] = '\0';

    // Read output filename from user
    printf("Enter output file name (without extension): ");
    fgets(output_filename, MAX_INPUT_SIZE, stdin);
    output_filename[strlen(output_filename)-1] = '\0';
    strcat(output_filename, ".txt");

    // Generate QR Code and check if successful
    if (generate_qr_code(input_data, output_filename)) {
        printf("QR Code generated successfully and saved to %s!\n", output_filename);
    } else {
        printf("QR Code generation failed.\n");
    }

    return 0;
}