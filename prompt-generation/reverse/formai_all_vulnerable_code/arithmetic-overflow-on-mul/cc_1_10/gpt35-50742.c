//FormAI DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [QR Code Output File] [QR Code Data]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    char *data = argv[2];
    char *temp_file_name = "temp.png";

    QRcode *qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    int margin = 4;
    int size = qr->width > 0 ? qr->width : 1;
    int border = 2;
    int image_size = size + border * 2;

    unsigned char *image_data = calloc(sizeof(char) * (image_size * image_size + 1), sizeof(char));

    if (image_data == NULL) {
        printf("Could not allocate memory for image data.");
        QRcode_free(qr);
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            unsigned char value = qr->data[y * size + x];

            image_data[(y + border) * image_size + (x + border)] = (value & 1) ? 0 : 255;
        }
    }

    QRcode_free(qr);

    FILE *temp_file = fopen(temp_file_name, "wb");

    if (temp_file == NULL) {
        printf("Could not create temporary file '%s'", temp_file_name);
        free(image_data);
        exit(EXIT_FAILURE);
    }

    fwrite(image_data, sizeof(char), image_size * image_size, temp_file);
    fclose(temp_file);
    free(image_data);

    char *command = (char*)malloc(sizeof(char) * (strlen(filename) + strlen(temp_file_name) + 10));
    command[0] = '\0';

    strcat(command, "mv ");
    strcat(command, temp_file_name);
    strcat(command, " ");
    strcat(command, filename);

    system(command);
    free(command);

    printf("QR code created successfully.\n");

    return 0;
}