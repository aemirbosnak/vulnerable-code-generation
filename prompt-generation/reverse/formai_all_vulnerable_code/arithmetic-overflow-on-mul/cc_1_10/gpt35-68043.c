//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert string to binary
char* stringToBinary(char* s) {
    if(s == NULL) return NULL; // return NULL for invalid input

    int len = strlen(s);
    char *binary = malloc(sizeof(char) * (len*8 + 1)); // allocate memory for binary
    binary[0] = '\0'; // initialize binary to empty string

    for(int i = 0; i < len; i++) {
        char ch = s[i];
        for(int j = 7; j >= 0; j--) {
            if(ch & (1 << j)) strcat(binary, "1"); // if bit is 1, append "1"
            else strcat(binary, "0"); // if bit is 0, append "0"
        }
    }

    return binary;
}

// Function to convert binary to string
char* binaryToString(char *binary) {
    if(binary == NULL) return NULL; // return NULL for invalid input

    int len = strlen(binary);
    char *string = malloc(sizeof(char) * (len/8 + 1)); // allocate memory for string
    string[0] = '\0'; // initialize string to empty string

    int i = 0;
    while(binary[i]) {
        char *byte = malloc(sizeof(char) * 9); // allocate memory for byte
        memcpy(byte, &binary[i], 8); // copy next 8 bits
        byte[8] = '\0'; // add null terminator
        int ch = strtol(byte, NULL, 2); // convert byte to integer
        sprintf(string, "%s%c", string, ch); // append to string
        i += 8;
        free(byte); // free dynamic memory
    }

    return string;
}

// Function to embed watermark in image
void digitalWatermarking(char *filename, char *watermark) {
    FILE *inFile = fopen(filename, "rb"); // open input file
    if(inFile == NULL) {
        printf("Unable to open input file");
        return;
    }

    FILE *outFile = fopen("watermarked_image.bmp", "wb"); // open output file
    if(outFile == NULL) {
        printf("Unable to write to output file");
        return;
    }

    unsigned char header[54]; // BMP header is 54 bytes long
    fread(header, sizeof(unsigned char), 54, inFile); // read header from input file
    fwrite(header, sizeof(unsigned char), 54, outFile); // write header to output file

    int width = *(int*)&header[18]; // extract image width from header
    int height = *(int*)&header[22]; // extract image height from header
    int padding = 0;
    if((width * 3) % 4 != 0) padding = 4 - ((width * 3) % 4); // calculate padding needed for each row

    char *binaryWatermark = stringToBinary(watermark); // convert watermark to binary

    int watermarkIndex = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            unsigned char color[3]; // RGB colors are 3 bytes each
            fread(color, sizeof(unsigned char), 3, inFile); // read color from input file

            if(watermarkIndex < strlen(binaryWatermark)) {
                char bit = binaryWatermark[watermarkIndex]; // get next bit from watermark
                watermarkIndex++;

                if(bit == '1') color[0] |= 1; // set least significant bit of color to 1
                else color[0] &= ~1; // set least significant bit of color to 0
            }

            fwrite(color, sizeof(unsigned char), 3, outFile); // write color to output file
        }
        fseek(inFile, padding, SEEK_CUR); // skip padding
        for(int j = 0; j < padding; j++) fwrite("0", sizeof(char), 1, outFile); // add padding to output file
    }

    fclose(inFile); // close input file
    fclose(outFile); // close output file

    printf("Digital watermark inserted successfully");
}

// Function to extract watermark from image
void extractWatermark(char *filename) {
    FILE *inFile = fopen(filename, "rb"); // open input file
    if(inFile == NULL) {
        printf("Unable to open input file");
        return;
    }

    unsigned char header[54]; // BMP header is 54 bytes long
    fread(header, sizeof(unsigned char), 54, inFile); // read header from input file

    int width = *(int*)&header[18]; // extract image width from header
    int height = *(int*)&header[22]; // extract image height from header
    int padding = 0;
    if((width * 3) % 4 != 0) padding = 4 - ((width * 3) % 4); // calculate padding needed for each row

    char *binaryWatermark = malloc(sizeof(char) * (width * height)); // allocate memory for watermark
    int watermarkIndex = 0;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            unsigned char color[3]; // RGB colors are 3 bytes each
            fread(color, sizeof(unsigned char), 3, inFile); // read color from input file

            char bit = (color[0] & 1) ? '1' : '0'; // get least significant bit of color

            binaryWatermark[watermarkIndex] = bit; // store bit in watermark
            watermarkIndex++;
        }
        fseek(inFile, padding, SEEK_CUR); // skip padding
    }
    fclose(inFile); // close input file

    char *watermark = binaryToString(binaryWatermark); // convert binary to string
    printf("Watermark extracted successfully: %s", watermark);

    free(binaryWatermark); // free dynamic memory
    free(watermark); // free dynamic memory
}

int main() {
    char *filename = "sample_image.bmp";
    char *watermark = "This is a digital watermark";

    digitalWatermarking(filename, watermark);
    extractWatermark("watermarked_image.bmp");

    return 0;
}