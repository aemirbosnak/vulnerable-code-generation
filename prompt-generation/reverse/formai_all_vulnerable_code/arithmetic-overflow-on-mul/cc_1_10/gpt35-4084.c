//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert integer to binary string
void int_to_bin(int num, char* bin_str) {
    int mask = 1 << 31;
    for (int i = 0; i < 32; i++) {
        if (num & mask) {
            bin_str[i] = '1';
        } else {
            bin_str[i] = '0';
        }
        mask >>= 1;
    }
    bin_str[32] = '\0';
}

// Function to convert binary string to integer
int bin_to_int(char* bin_str) {
    int num = 0;
    for (int i = 31; i >= 0; i--) {
        num <<= 1;
        if (bin_str[i] == '1') {
            num |= 1;
        }
    }
    return num;
}

// Function to hide data in an image
void hide_data(char* image_filename, char* data, char* output_filename) {
    FILE* image_file = fopen(image_filename, "rb");
    FILE* output_file = fopen(output_filename, "wb");
    
    if (image_file == NULL) {
        printf("Error: cannot open image file.\n");
        return;
    } else if (output_file == NULL) {
        printf("Error: cannot create output file.\n");
        return;
    }
    
    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);
    fwrite(header, sizeof(unsigned char), 54, output_file);
    
    // Get image size and calculate number of pixels
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = width * height;
    
    // Convert data to binary string
    char bin_str[33];
    int_to_bin(strlen(data), bin_str);
    
    // Hide data length in the first 4 pixels
    int pixel[4];
    for (int i = 0; i < 4; i++) {
        fread(&pixel[i], sizeof(int), 1, image_file);
        char* pixel_bin_str = (char*)malloc(sizeof(char) * 33);
        int_to_bin(pixel[i], pixel_bin_str);
        pixel_bin_str[31] = bin_str[i];
        pixel[i] = bin_to_int(pixel_bin_str);
        free(pixel_bin_str);
        fwrite(&pixel[i], sizeof(int), 1, output_file);
    }
    
    // Hide data in remaining pixels
    int i = 0;
    for (int j = 0; j < size; j++) {
        if (i == strlen(data)) {
            fwrite(&pixel[j%4], sizeof(int), 1, output_file);
        } else {
            fread(&pixel[j%4], sizeof(int), 1, image_file);
            char* pixel_bin_str = (char*)malloc(sizeof(char) * 33);
            int_to_bin(pixel[j%4], pixel_bin_str);
            pixel_bin_str[31] = data[i];
            pixel[j%4] = bin_to_int(pixel_bin_str);
            free(pixel_bin_str);
            i++;
            fwrite(&pixel[j%4], sizeof(int), 1, output_file);
        }
    }
    
    fclose(image_file);
    fclose(output_file);
    printf("Data successfully hidden in %s.\n", output_filename);
}

// Function to recover hidden data from an image
void recover_data(char* image_filename, char* output_filename) {
    FILE* image_file = fopen(image_filename, "rb");
    FILE* output_file = fopen(output_filename, "wb");
    
    if (image_file == NULL) {
        printf("Error: cannot open image file.\n");
        return;
    } else if (output_file == NULL) {
        printf("Error: cannot create output file.\n");
        return;
    }
    
    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);
    
    // Get image size and calculate number of pixels
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int size = width * height;
    
    // Get length of data hidden in image
    int data_length = 0;
    char bin_str[33];
    int pixel[4];
    for (int i = 0; i < 4; i++) {
        fread(&pixel[i], sizeof(int), 1, image_file);
        char* pixel_bin_str = (char*)malloc(sizeof(char) * 33);
        int_to_bin(pixel[i], pixel_bin_str);
        bin_str[i] = pixel_bin_str[31];
        free(pixel_bin_str);
    }
    data_length = bin_to_int(bin_str);
    
    // Recover hidden data
    char* data = (char*)malloc(sizeof(char) * (data_length+1));
    int i = 0;
    for (int j = 0; j < size; j++) {
        if (i == data_length) {
            break;
        } else {
            fread(&pixel[j%4], sizeof(int), 1, image_file);
            char* pixel_bin_str = (char*)malloc(sizeof(char) * 33);
            int_to_bin(pixel[j%4], pixel_bin_str);
            data[i] = pixel_bin_str[31];
            free(pixel_bin_str);
            i++;
        }
    }
    data[data_length] = '\0';
    fwrite(data, sizeof(char), strlen(data), output_file);
    
    fclose(image_file);
    fclose(output_file);
    printf("Data successfully recovered to %s.\n", output_filename);
}

int main() {
    char data[] = "The quick brown fox jumps over the lazy dog.";
    char image_filename[] = "image.bmp";
    char stego_image_filename[] = "stego_image.bmp";
    char recovered_data_filename[] = "recovered_data.txt";
    
    hide_data(image_filename, data, stego_image_filename);
    recover_data(stego_image_filename, recovered_data_filename);
    
    return 0;
}