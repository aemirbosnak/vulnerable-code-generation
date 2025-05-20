//FormAI DATASET v1.0 Category: QR code generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    char *string = "Hello, world!";
    int version = 0;
    int level = QR_ECLEVEL_M;
    int size = 4;
    int margin = 4;
    int dpi = 72;
    int symmetric = 1;
    int r = -1;
    int g = -1;
    int b = -1;
    int max_size = 1024;
    
    QRcode *code = QRcode_encodeString(string, version, level, QR_MODE_8, symmetric);
    
    if (!code) {
        fprintf(stderr, "QR Code encoding failed.\n");
        return EXIT_FAILURE;
    }
    
    int code_size = code->width;
    unsigned char *bmp = calloc(code_size * code_size * 3, sizeof(unsigned char));
    
    for (int y = 0; y < code_size; y++) {
        for (int x = 0; x < code_size; x++) {
            if (code->data[y * code_size + x] & 1) {
                if (r == -1 && g == -1 && b == -1) {
                    bmp[(y * code_size + x) * 3 + 0] = 0;
                    bmp[(y * code_size + x) * 3 + 1] = 0;
                    bmp[(y * code_size + x) * 3 + 2] = 0;
                } else {
                    bmp[(y * code_size + x) * 3 + 0] = r;
                    bmp[(y * code_size + x) * 3 + 1] = g;
                    bmp[(y * code_size + x) * 3 + 2] = b;
                }
            } else {
                bmp[(y * code_size + x) * 3 + 0] = 255;
                bmp[(y * code_size + x) * 3 + 1] = 255;
                bmp[(y * code_size + x) * 3 + 2] = 255;
            }
        }
    }
    
    QRcode_free(code);
    
    FILE *fp;
    char file_name[100];
    snprintf(file_name, sizeof(file_name), "qrcode.bmp");
    
    fp = fopen(file_name, "wb");
    if (!fp) {
        fprintf(stderr, "Could not open file %s\n", file_name);
        return EXIT_FAILURE;
    }
    
    fprintf(fp, "BM");
    unsigned int file_size = 54 + code_size * code_size * 3;
    fwrite(&file_size, sizeof(unsigned int), 1, fp);
    unsigned int reserved = 0x0000;
    fwrite(&reserved, sizeof(unsigned int), 1, fp);
    fwrite(&reserved, sizeof(unsigned int), 1, fp);
    unsigned int offset = 54;
    fwrite(&offset, sizeof(unsigned int), 1, fp);
    
    unsigned int header_size = 40;
    fwrite(&header_size, sizeof(unsigned int), 1, fp);
    fwrite(&code_size, sizeof(int), 1, fp);
    fwrite(&code_size, sizeof(int), 1, fp);
    unsigned short int planes = 1;
    fwrite(&planes, sizeof(unsigned short int), 1, fp);
    unsigned short int bit_count = 24;
    fwrite(&bit_count, sizeof(unsigned short int), 1, fp);
    unsigned int compression = 0;
    fwrite(&compression, sizeof(unsigned int), 1, fp);
    unsigned int image_size = code_size * code_size * 3;
    fwrite(&image_size, sizeof(unsigned int), 1, fp);
    fwrite(&dpi, sizeof(int), 1, fp);
    fwrite(&dpi, sizeof(int), 1, fp);
    unsigned int colors_used = 0;
    fwrite(&colors_used, sizeof(unsigned int), 1, fp);
    unsigned int colors_important = 0;
    fwrite(&colors_important, sizeof(unsigned int), 1, fp);
    
    fwrite(bmp, sizeof(unsigned char), code_size * code_size * 3, fp);
    
    fclose(fp);
    free(bmp);
    
    printf("QR code successfully generated and saved as %s\n", file_name);
    
    return EXIT_SUCCESS;
}