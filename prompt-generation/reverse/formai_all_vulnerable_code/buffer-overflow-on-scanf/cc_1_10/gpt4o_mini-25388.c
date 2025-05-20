//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offsetData;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

#pragma pack(pop)

void hide_message_in_bmp(const char* bmp_filename, const char* message) {
    FILE* bmp_file = fopen(bmp_filename, "rb+");
    if (!bmp_file) {
        perror("Unable to open BMP file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER file_header;
    fread(&file_header, sizeof(BITMAPFILEHEADER), 1, bmp_file);

    BITMAPINFOHEADER info_header;
    fread(&info_header, sizeof(BITMAPINFOHEADER), 1, bmp_file);

    // Calculate the total number of pixels
    int num_pixels = info_header.width * info_header.height;

    // Prepare and validate the message
    int message_length = strlen(message);
    if (message_length > num_pixels) {
        fprintf(stderr, "Error: Message is too long to hide in the image.\n");
        fclose(bmp_file);
        exit(EXIT_FAILURE);
    }

    // Place the message length as the first byte in the pixel data
    RGB pixel;
    fseek(bmp_file, file_header.offsetData, SEEK_SET);
    for (int i = 0; i < message_length; i++) {
        fread(&pixel, sizeof(RGB), 1, bmp_file);
        pixel.red = (pixel.red & 0xFE) | ((message[i] >> 7) & 1);
        fseek(bmp_file, -sizeof(RGB), SEEK_CUR);
        fwrite(&pixel, sizeof(RGB), 1, bmp_file);
        
        fread(&pixel, sizeof(RGB), 1, bmp_file);
        pixel.green = (pixel.green & 0xFE) | ((message[i] >> 6) & 1);
        fseek(bmp_file, -sizeof(RGB), SEEK_CUR);
        fwrite(&pixel, sizeof(RGB), 1, bmp_file);
        
        fread(&pixel, sizeof(RGB), 1, bmp_file);
        pixel.blue = (pixel.blue & 0xFE) | ((message[i] >> 5) & 1);
        fseek(bmp_file, -sizeof(RGB), SEEK_CUR);
        fwrite(&pixel, sizeof(RGB), 1, bmp_file);
    }

    // Hide a null terminator to signal the end of the message
    char end_message = '\0';
    for (int i = 0; i < 1; i++) {
        fread(&pixel, sizeof(RGB), 1, bmp_file);
        pixel.red = (pixel.red & 0xFE) | ((end_message >> 7) & 1);
        fseek(bmp_file, -sizeof(RGB), SEEK_CUR);
        fwrite(&pixel, sizeof(RGB), 1, bmp_file);
        
        fread(&pixel, sizeof(RGB), 1, bmp_file);
        pixel.green = (pixel.green & 0xFE) | ((end_message >> 6) & 1);
        fseek(bmp_file, -sizeof(RGB), SEEK_CUR);
        fwrite(&pixel, sizeof(RGB), 1, bmp_file);
        
        fread(&pixel, sizeof(RGB), 1, bmp_file);
        pixel.blue = (pixel.blue & 0xFE) | ((end_message >> 5) & 1);
        fseek(bmp_file, -sizeof(RGB), SEEK_CUR);
        fwrite(&pixel, sizeof(RGB), 1, bmp_file);
    }

    fclose(bmp_file);
    printf("Message hidden successfully!\n");
}

void read_message_from_bmp(const char* bmp_filename) {
    FILE* bmp_file = fopen(bmp_filename, "rb");
    if (!bmp_file) {
        perror("Unable to open BMP file");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER file_header;
    fread(&file_header, sizeof(BITMAPFILEHEADER), 1, bmp_file);

    BITMAPINFOHEADER info_header;
    fread(&info_header, sizeof(BITMAPINFOHEADER), 1, bmp_file);

    RGB pixel;
    char message[256] = {0};
    int i = 0;

    fseek(bmp_file, file_header.offsetData, SEEK_SET);
    while (i < 255) {
        fread(&pixel, sizeof(RGB), 1, bmp_file);
        message[i] = (pixel.red & 1) << 7;

        fread(&pixel, sizeof(RGB), 1, bmp_file);
        message[i] |= (pixel.green & 1) << 6;

        fread(&pixel, sizeof(RGB), 1, bmp_file);
        message[i] |= (pixel.blue & 1) << 5;

        if (message[i] == 0) break; // End of message
        i++;
    }

    fclose(bmp_file);
    printf("Hidden message: %s\n", message);
}

int main() {
    char input[256];
    char bmp_file[256];
  
    printf("Enter BMP filename to hide a message: ");
    scanf("%s", bmp_file);
    
    printf("Enter the message to hide: ");
    scanf(" %[^\n]", input);
    
    hide_message_in_bmp(bmp_file, input);
    
    printf("Enter BMP filename to read a hidden message: ");
    scanf("%s", bmp_file);
    
    read_message_from_bmp(bmp_file);
  
    return 0;
}