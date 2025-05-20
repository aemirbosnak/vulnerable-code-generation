//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int biXPelsPerMeter;        
    int biYPelsPerMeter;        
    unsigned int biClrUsed;     
    unsigned int biClrImportant; 
} BITMAPINFOHEADER;
#pragma pack(pop)

void hideMessageInBMP(const char *bmpFile, const char *message);
void extractMessageFromBMP(const char *bmpFile);
int isSpaceAvailable(const BITMAPINFOHEADER *biHeader, const char *message);

int main() {
    int choice;
    char bmpFile[256];
    char message[1024];

    printf("Welcome to BMP Steganography!\n");
    printf("Choose an option:\n");
    printf("1. Hide a message in a BMP image\n");
    printf("2. Extract a message from a BMP image\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // consume newline character

    printf("Enter the BMP file name: ");
    fgets(bmpFile, sizeof(bmpFile), stdin);
    bmpFile[strcspn(bmpFile, "\n")] = '\0'; // remove newline

    if (choice == 1) {
        printf("Enter the secret message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0'; // remove newline
        hideMessageInBMP(bmpFile, message);
    } else if (choice == 2) {
        extractMessageFromBMP(bmpFile);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

void hideMessageInBMP(const char *bmpFile, const char *message) {
    FILE *fp = fopen(bmpFile, "rb+");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, fp);

    if (bih.biBitCount != 24) {
        printf("Only 24-bit BMP images are supported.\n");
        fclose(fp);
        return;
    }

    if (!isSpaceAvailable(&bih, message)) {
        printf("Not enough space to hide the message!\n");
        fclose(fp);
        return;
    }

    fseek(fp, bfh.bfOffBits, SEEK_SET);
    
    // Transform the message into binary 
    for (size_t i = 0; i <= strlen(message); i++) {
        unsigned char byte = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, fp);
            // Modify the least significant bit
            pixel[0] = (pixel[0] & 0xFE) | ((byte >> (7 - j)) & 0x01);
            fwrite(pixel, sizeof(unsigned char), 3, fp);
        }
    }

    printf("Message hidden successfully in %s!\n", bmpFile);
    fclose(fp);
}

void extractMessageFromBMP(const char *bmpFile) {
    FILE *fp = fopen(bmpFile, "rb");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, fp);

    if (bih.biBitCount != 24) {
        printf("Only 24-bit BMP images are supported.\n");
        fclose(fp);
        return;
    }

    fseek(fp, bfh.bfOffBits, SEEK_SET);
    
    char message[1024] = {0};
    size_t msgIndex = 0;

    while (msgIndex < sizeof(message) - 1) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, fp);

        // Read the least significant bit
        unsigned char bit = pixel[0] & 0x01;

        // Append to message
        if (msgIndex % 8 == 0 && msgIndex > 0) {
            message[msgIndex / 8] = '\0'; // terminate string
            break;
        }

        if (msgIndex % 8 == 0) {
            message[msgIndex / 8] = 0; // new byte
        }
        message[msgIndex / 8] |= (bit << (7 - (msgIndex % 8)));
        msgIndex++;
    }

    printf("Extracted message: %s\n", message);
    fclose(fp);
}

int isSpaceAvailable(const BITMAPINFOHEADER *biHeader, const char *message) {
    int imageSize = biHeader->biWidth * biHeader->biHeight * 3; // pixel count
    int messageSize = strlen(message) + 1; // account for null terminator
    return imageSize * 8 >= messageSize;
}