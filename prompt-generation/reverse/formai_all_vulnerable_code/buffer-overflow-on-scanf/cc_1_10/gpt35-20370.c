//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

//define macros
#define BYTE  char  //one byte of information
#define WORD  short //two bytes of information
#define DWORD int   //four bytes of information

//configurable options
#define MAX_MESSAGE_SIZE 1024 //maximum size of message to hide in image
#define MAX_FILENAME_SIZE 64 //maximum length of input/output file names


//function to read message to hide
int read_message(char *filename, BYTE *message, int max_size) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for reading.\n", filename);
        return -1;
    }
    int size = fread(message, sizeof(BYTE), max_size, fp);
    fclose(fp);
    return size;
}

//function to write message to output file
int write_message(char *filename, BYTE *message, int size) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing.\n", filename);
        return -1;
    }
    fwrite(message, sizeof(BYTE), size, fp);
    fclose(fp);
    return 0;
}

//function to hide message in image
int encode(char *image_filename, char *output_filename, char *message_filename) {
    //open image file
    FILE *fp;
    fp = fopen(image_filename, "rb+");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for encoding.\n", image_filename);
        return -1;
    }

    //read header information
    BYTE header[54];
    int header_size = fread(header, sizeof(BYTE), 54, fp);

    //get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = header[28]; //bits per pixel

    //calculate number of pixels in image
    int num_pixels = width * height;
    if (bpp != 24 || num_pixels < MAX_MESSAGE_SIZE * 8) {
        printf("Error: image format not supported.\n");
        fclose(fp);
        return -1;
    }

    //read message to hide
    BYTE message[MAX_MESSAGE_SIZE];
    int size = read_message(message_filename, message, MAX_MESSAGE_SIZE);

    //create copy of header to modify for output file
    BYTE output_header[header_size];
    for (int i = 0; i < header_size; i++) {
        output_header[i] = header[i];
    }

    //calculate size of message in bits
    DWORD message_size = size * 8;

    //update header with message size information
    *(DWORD*)&output_header[34] = message_size;

    //write modified header to output file
    write_message(output_filename, output_header, header_size);

    //iterate over each byte of message and hide in LSB of each color channel for each pixel
    int offset = header_size;
    for (int i = 0; i < size; i++) {
        BYTE byte = message[i];
        for (int j = 0; j < 8; j++) {
            int pixel_index = (i * 8 + j) * 3;
            BYTE pixel[3];
            fseek(fp, offset + pixel_index, SEEK_SET);
            fread(pixel, sizeof(BYTE), 3, fp);

            //hide bit of message in LSB of each color channel
            pixel[0] = (pixel[0] & 0xFE) | ((byte >> j) & 0x01);
            pixel[1] = (pixel[1] & 0xFE) | ((byte >> j) & 0x01);
            pixel[2] = (pixel[2] & 0xFE) | ((byte >> j) & 0x01);

            //write modified pixel to output file
            fseek(fp, offset + pixel_index, SEEK_SET);
            fwrite(pixel, sizeof(BYTE), 3, fp);
        }
    }

    //close input image file
    fclose(fp);

    return 0;
}

//function to extract hidden message from image
int decode(char *image_filename, char *message_filename) {
    //open image file
    FILE *fp;
    fp = fopen(image_filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for decoding.\n", image_filename);
        return -1;
    }

    //read header information
    BYTE header[54];
    int header_size = fread(header, sizeof(BYTE), 54, fp);

    //get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = header[28]; //bits per pixel

    //calculate number of pixels in image
    int num_pixels = width * height;
    if (bpp != 24 || num_pixels < MAX_MESSAGE_SIZE * 8) {
        printf("Error: image format not supported.\n");
        fclose(fp);
        return -1;
    }

    //get message size
    DWORD message_size = *(DWORD*)&header[34];
    int size = message_size / 8;

    //create buffer to hold extracted message
    BYTE message[MAX_MESSAGE_SIZE];

    //iterate over each byte of message and extract from LSB of each color channel for each pixel
    int offset = header_size;
    for (int i = 0; i < size; i++) {
        BYTE byte = 0;
        for (int j = 0; j < 8; j++) {
            int pixel_index = (i * 8 + j) * 3;
            BYTE pixel[3];
            fseek(fp, offset + pixel_index, SEEK_SET);
            fread(pixel, sizeof(BYTE), 3, fp);

            //extract LSB of each color channel and store in byte
            byte |= ((pixel[0] & 0x01) << j);
            byte |= ((pixel[1] & 0x01) << j);
            byte |= ((pixel[2] & 0x01) << j);
        }
        message[i] = byte;
    }

    //write extracted message to output file
    write_message(message_filename, message, size);

    //close input image file
    fclose(fp);

    return 0;
}

//main function
int main() {
    char image_filename[MAX_FILENAME_SIZE];
    char output_filename[MAX_FILENAME_SIZE];
    char message_filename[MAX_FILENAME_SIZE];

    printf("Enter name of image file to encode: ");
    scanf("%s", image_filename);
    printf("Enter name of output file: ");
    scanf("%s", output_filename);
    printf("Enter name of message file to hide: ");
    scanf("%s", message_filename);

    encode(image_filename, output_filename, message_filename);

    printf("Enter name of image file to decode: ");
    scanf("%s", image_filename);
    printf("Enter name of output file for hidden message: ");
    scanf("%s", output_filename);

    decode(image_filename, output_filename);

    return 0;
}