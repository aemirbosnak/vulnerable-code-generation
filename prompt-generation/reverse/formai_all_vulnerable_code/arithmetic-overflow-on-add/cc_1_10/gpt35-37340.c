//FormAI DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

char* extract_data(const byte* img, int img_size) {

    // Reading data size from the header
    const int data_size_offset = 54;
    const int data_size = *((int*) (img + data_size_offset));

    // Allocating memory for extracted data
    char* extracted_data = malloc((data_size + 1) * sizeof(char));
    memset(extracted_data, 0, data_size + 1);

    // Extracting data from image
    const int data_offset = 58;
    byte mask = 1;
    byte current_byte = 0;
    int bit_count = 0;
    int data_pos = 0;
    for (int i = data_offset; i < img_size; ++i) {
        byte pixel = *(img + i);
        current_byte |= (pixel & mask) << bit_count;
        bit_count++;

        // If full byte was read, save it as data and reset byte data
        if (bit_count == 8) {
            extracted_data[data_pos] = current_byte;
            data_pos++;
            current_byte = 0;
            bit_count = 0;
        }

        // Stop condition - if all data was read
        if (data_pos == data_size) {
            break;
        }
    }

    return extracted_data;
}

void save_data(byte* img_data, int img_size, const char* data, int data_size) {

    // Writing data size to the header
    const int data_size_offset = 54;
    *((int*) (img_data + data_size_offset)) = data_size;

    // Extracting data from image
    const int data_offset = 58;
    byte mask = 1;
    byte current_byte = 0;
    int bit_count = 0;
    int data_pos = 0;
    for (int i = data_offset; i < img_size; ++i) {
        byte pixel = *(img_data + i);

        // Cleaing least significant bit
        pixel &= ~mask;

        // If bit is set in data, turning on LSB
        if ((data[data_pos] >> bit_count) & 1) {
            pixel |= (mask);
        }

        *(img_data + i) = pixel;
        bit_count++;

        // If full byte was written to data, move to the next byte of data
        if (bit_count == 8) {
            bit_count = 0;
            data_pos++;
        }

        // Stop condition - if all data was saved
        if (data_pos == data_size) {
            break;
        }
    }

}

int main(int argc, char** argv) {

    char* img_filename = "image.bmp";
    int data_size = 100;
    char data[] = "This is a secret message. Can you find it?";

    // Reading raw image data from file
    FILE* img_file = fopen(img_filename, "rb");
    fseek(img_file, 0, SEEK_END);
    int img_size = ftell(img_file);
    byte* img_data = malloc(img_size * sizeof(byte));
    fseek(img_file, 0, SEEK_SET);
    fread(img_data, sizeof(byte), img_size, img_file);
    fclose(img_file);

    // Extracting data from image
    char* extracted_data = extract_data(img_data, img_size);
    printf("Extracted data: %s\n", extracted_data);
    free(extracted_data);

    // Saving data to image
    save_data(img_data, img_size, data, data_size);

    // Saving modified image to file
    char* modified_img_filename = "modified_image.bmp";
    FILE* modified_img_file = fopen(modified_img_filename, "wb");
    fwrite(img_data, sizeof(byte), img_size, modified_img_file);
    fclose(modified_img_file);

    return EXIT_SUCCESS;
}