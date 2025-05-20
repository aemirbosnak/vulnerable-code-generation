//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pixel {
    int r, g, b;
} Pixel;

// function to set the least significant bit of a value to a given bit
int set_lsb(int value, int bit) {
    return (value & ~1) | bit;
}

// function to get the least significant bit of a value
int get_lsb(int value) {
    return value & 1;
}

void digital_watermark(char* image_file_path, char* message_file_path, char* output_file_path) {
    // reading the image file
    FILE* image_file = fopen(image_file_path, "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file \"%s\"\n", image_file_path);
        exit(1);
    }
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = 0;
    int row_size = width * 3;
    while ((row_size + padding) % 4 != 0) {
        padding++;
    }
    int image_size = height * (row_size + padding);
    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);
    fread(image_data, sizeof(unsigned char), image_size, image_file);
    fclose(image_file);

    // reading the message file
    FILE* message_file = fopen(message_file_path, "r");
    if (message_file == NULL) {
        printf("Error: Could not open message file \"%s\"\n", message_file_path);
        exit(1);
    }
    char message[1024];
    fgets(message, 1024, message_file);
    fclose(message_file); 

    // adding the message as a digital watermark to the image
    int message_length = strlen(message);
    int pixel_to_modify = 0;
    for (int i = 0; i < message_length; i++) {        
        int byte_value = (int)message[i];
        for (int j = 0; j < 8; j++) {
            // get the least significant bit of the current byte value
            int bit_value = (byte_value >> j) & 1;

            // get the pixel to modify
            Pixel* pixel = (Pixel*)&image_data[pixel_to_modify];

            // set the least significant bit of the red channel to the bit value
            pixel->r = set_lsb(pixel->r, bit_value);

            // increment the pixel to modify
            pixel_to_modify += 3;

            // if we've reached the end of the row, add the padding
            if (pixel_to_modify % (row_size + padding) == 0) {
                pixel_to_modify += padding;
            }
        }
    }

    // writing the output file
    FILE* output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        printf("Error: Could not create output file \"%s\"\n", output_file_path);
        exit(1);
    }
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(image_data, sizeof(unsigned char), image_size, output_file);
    fclose(output_file);

    printf("Digital watermarking complete. Message added to image file %s.\n", image_file_path);
}

int main() {
    digital_watermark("original.bmp", "message.txt", "watermarked.bmp");
    return 0;
}