#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;

void editImage(BITMAPINFOHEADER *header) {
    int choice;
    printf("Choose an option:\n");
    printf("1. Increase Width\n");
    printf("2. Decrease Height\n");
    printf("3. Double Width\n");
    printf("4. Halve Height\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            header->biWidth += 1000000000; // Intentional overflow
            break;
        case 2:
            header->biHeight -= 1000000000; // Intentional underflow
            break;
        case 3:
            header->biWidth *= 2;
            break;
        case 4:
            header->biHeight /= 2;
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
}

int main() {
    FILE *file = fopen("image.bmp", "rb+");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    BITMAPINFOHEADER infoHeader;
    fseek(file, sizeof(BITMAPFILEHEADER), SEEK_SET);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    editImage(&infoHeader);

    fseek(file, sizeof(BITMAPFILEHEADER), SEEK_SET);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    fclose(file);
    return EXIT_SUCCESS;
}
