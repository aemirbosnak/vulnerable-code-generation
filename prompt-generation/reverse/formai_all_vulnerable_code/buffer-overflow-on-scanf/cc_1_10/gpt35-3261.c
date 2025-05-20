//FormAI DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define BMP_HEADER_SIZE 54

typedef unsigned char byte; // defining byte type to store unsigned 8-bit values

// Function to get the size of the file
int get_file_size(char *filename) {
    FILE *fp = fopen(filename, "r");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fclose(fp);
    return size;
}

// Function to read the BMP header
void read_bmp_header(FILE *fp, byte bmp_header[]) {
    fread(bmp_header, 1, BMP_HEADER_SIZE, fp);
}

// Function to read the LSB of a byte
byte get_LSB(byte b) {
    return b & 0x01;
}

// Function to hide the data using LSB substitution
void hide_data(byte bmp_image[], int data_size, byte data[]) {
    int bmp_size = get_file_size("input.bmp");
    int capacity = (bmp_size - BMP_HEADER_SIZE) / 8;
    if (capacity < data_size) {
        printf("Error: Not enough capacity in the image to hide the data!\n");
        exit(1);
    }
    int offset = BMP_HEADER_SIZE;
    for (int i = 0; i < data_size; i++) {
        byte d = data[i];
        for (int j = 0; j < 8; j++) {
            byte bit = (d >> j) & 0x01;
            bmp_image[offset] = (bmp_image[offset] & 0xFE) | bit;
            offset++;
        }
    }
}

// Function to extract the data using LSB substitution
byte* extract_data(byte bmp_image[], int data_size) {
    int offset = BMP_HEADER_SIZE;
    byte* data = (byte*)malloc(data_size * sizeof(byte));
    for (int i = 0; i < data_size; i++) {
        byte d = 0;
        for (int j = 0; j < 8; j++) {
            byte bit = get_LSB(bmp_image[offset]);
            d = d | (bit << j);
            offset++;
        }
        data[i] = d;
    }
    return data;
}

// Function to write the BMP image
void write_bmp_image(char *filename, byte bmp_image[]) {
    FILE *outfp = fopen(filename, "w");
    for (int i = 0; i < get_file_size("input.bmp"); i++) {
        fwrite(&bmp_image[i], 1, 1, outfp);
    }
    fclose(outfp);
}

int main() {
    byte bmp_header[BMP_HEADER_SIZE];
    FILE *infp = fopen("input.bmp", "r");
    if (infp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }
    read_bmp_header(infp, bmp_header);
    int data_size;
    printf("Enter the size of the data to be hidden: ");
    scanf("%d", &data_size);
    byte* data = (byte*)malloc(data_size * sizeof(byte));
    printf("Enter the data to be hidden: ");
    getchar();
    fgets((char*)data, data_size, stdin);
    hide_data(bmp_header, data_size, data);
    write_bmp_image("steg_image.bmp", bmp_header);
    byte* extracted_data = extract_data(bmp_header, data_size);
    printf("Extracted data: %s", extracted_data);
    free(extracted_data);
    return 0;
}