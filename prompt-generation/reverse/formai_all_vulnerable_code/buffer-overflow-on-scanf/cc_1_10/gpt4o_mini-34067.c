//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

#pragma pack(push, 1)
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
    int biXPixPerMeter;
    int biYPixPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void encodeMessage(const char* bmpFile, const char* message) {
    FILE* f = fopen(bmpFile, "r+b");
    if (!f) {
        printf("Alas! Unable to open the banner file.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, f);

    fseek(f, bfh.bfOffBits, SEEK_SET);

    // Convert message length to binary
    int msgLength = strlen(message);
    for (int i = 0; i < msgLength; ++i) {
        BYTE byte;
        fread(&byte, sizeof(BYTE), 1, f);
        byte = (byte & 0xFE) | ((message[i] >> (7 - (i % 8))) & 0x01);
        fseek(f, -1, SEEK_CUR);
        fwrite(&byte, sizeof(BYTE), 1, f);
    }

    // Write end character to mark the end of the message
    BYTE endChar = 0xFF; // This indicates the end of the hidden message
    fwrite(&endChar, sizeof(BYTE), 1, f);

    fclose(f);
    printf("The knight's message has been securely encoded in the banner!\n");
}

void decodeMessage(const char* bmpFile) {
    FILE* f = fopen(bmpFile, "rb");
    if (!f) {
        printf("Alas! Unable to open the banner file.\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, f);

    fseek(f, bfh.bfOffBits, SEEK_SET);

    char message[1024] = {0};
    int index = 0;
    BYTE byte;

    while (fread(&byte, sizeof(BYTE), 1, f) == 1) {
        if (byte == 0xFF) break; // End of message
        message[index] = (message[index] << 1) | (byte & 0x01);
        index += (index % 8 == 7) ? 1 : 0; // Move to next character if we've collected 8 bits
    }

    printf("The knight's message:\n");
    for (int i = 0; i < index; ++i) {
        if (message[i] == '\0') break;
        putchar(message[i]);
    }
    putchar('\n');

    fclose(f);
}

int main() {
    char choice;
    char bmpFile[256];
    char message[256];

    printf("Hark, brave knight! Shall we conceal a message or retrieve one?\n");
    printf("Press 'e' to encode a message, 'd' to decode: ");
    scanf(" %c", &choice);

    if (choice == 'e') {
        printf("Enter the noble banner file path: ");
        scanf("%s", bmpFile);
        printf("Enter thine secret message: ");
        scanf(" %[^\n]", message);
        encodeMessage(bmpFile, message);
    } else if (choice == 'd') {
        printf("Enter the faithful banner file path: ");
        scanf("%s", bmpFile);
        decodeMessage(bmpFile);
    } else {
        printf("Alas! Invalid choice, noble knight.\n");
    }

    return 0;
}