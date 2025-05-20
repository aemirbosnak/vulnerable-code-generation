//FormAI DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_HEADER_SIZE 14
#define BMP_HEADER_SIZE 40
#define MAX_IMAGE_SIZE 1024*1024

typedef struct {
    char filetype[3];
    unsigned int filesize;
    short reserved1;
    short reserved2;
    unsigned int data_offset;
} file_header;

typedef struct {
    unsigned int header_size;
    int width;
    int height;
    short num_planes;
    short bpp;
    unsigned int compression_type;
    unsigned int image_size_bytes;
    int x_resolution_ppm;
    int y_resolution_ppm;
    unsigned int num_colors;
    unsigned int num_important_colors;  
} bmp_header;

void hide_message(unsigned char *image_buffer, const char *message) {
    unsigned int message_length = strlen(message);
    unsigned int bit_index = 0;
    
    // Loop through each character in the message
    for (unsigned int i=0; i<message_length; i++) {
        
        // Get the next character from the message
        char current_char = message[i];
        
        // Loop through each bit in the character
        for (int j=7; j>=0; j--) {
            
            // Set the last bit of each color channel to the corresponding bit of the character
            image_buffer[bit_index+2] = (image_buffer[bit_index+2] & 0xFE) | ((current_char >> j) & 0x01);
            image_buffer[bit_index+1] = (image_buffer[bit_index+1] & 0xFE) | ((current_char >> j) & 0x01);
            image_buffer[bit_index] = (image_buffer[bit_index] & 0xFE) | ((current_char >> j) & 0x01);
            
            // Move the bit index forward to the next channel
            bit_index += 3;
        }
    }
}

void extract_message(unsigned char *image_buffer, char *message, const unsigned int max_message_length) {
    unsigned int message_length = 0;
    unsigned int bit_index = 0;
    
    // Loop until we reach the end of the message or the max_message_length
    while (message_length < max_message_length) {
        
        // Get the next character from the message
        char current_char = 0;
        
        // Loop through each bit in the character
        for (int j=7; j>=0; j--) {
            
            // Get the last bit of each color channel and shift it into the corresponding bit of the character
            current_char |= ((image_buffer[bit_index+2] & 0x01) << j);
            current_char |= ((image_buffer[bit_index+1] & 0x01) << j);
            current_char |= ((image_buffer[bit_index] & 0x01) << j);
            
            // Move the bit index forward to the next channel
            bit_index += 3;
        }
        
        // Add the character to the message
        message[message_length] = current_char;
        message_length++;
        
        // Check if we've reached the end of the message
        if (current_char == '\0') {
            break;
        }
    }
    
    // Null-terminate the message string
    message[max_message_length-1] = '\0';
}

void read_bmp(const char *filename, unsigned char **image_buffer, unsigned int *width, unsigned int *height) {
    // Open the BMP file in binary mode
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file %s\n", filename);
        exit(1);
    }
   
    // Read the file header
    file_header fh;
    fread(&fh, FILE_HEADER_SIZE, 1, file);
   
    // Check that the file is a BMP file
    if (memcmp(fh.filetype, "BM", 2) != 0) {
        fprintf(stderr, "Error: %s is not a BMP file\n", filename);
        fclose(file);
        exit(1);
    }
   
    // Read the BMP header
    bmp_header bh;
    fread(&bh, BMP_HEADER_SIZE, 1, file);
   
    // Check that the BMP header is valid
    if (bh.header_size != BMP_HEADER_SIZE || bh.num_planes != 1 || bh.bpp != 24 ||
        bh.compression_type != 0 || bh.num_colors != 0 || bh.num_important_colors != 0) {
        fprintf(stderr, "Error: Invalid BMP header in file %s\n", filename);
        fclose(file);
        exit(1);
    }
   
    // Check that the image size is below the maximum allowed size
    if (bh.width * bh.height > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Error: Image size in file %s exceeds the maximum allowed size\n", filename);
        fclose(file);
        exit(1);
    }
   
    // Calculate the size of the image data in bytes
    unsigned int image_data_size = ((bh.width * 3 + 3) / 4 * 4) * bh.height;
   
    // Allocate memory for the image buffer
    *image_buffer = malloc(image_data_size);
    if (*image_buffer == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for image data in file %s\n", filename);
        fclose(file);
        exit(1);
    }
   
    // Read the image data
    fread(*image_buffer, 1, image_data_size, file);
   
    // Close the file
    fclose(file);
   
    // Store the image width and height
    *width = bh.width;
    *height = bh.height;
}

void write_bmp(const char *filename, unsigned char *image_buffer, const unsigned int width, const unsigned int height) {
    // Calculate the size of the image data in bytes
    unsigned int image_data_size = ((width * 3 + 3) / 4 * 4) * height;
   
    // Open the output BMP file in binary mode
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file %s for writing\n", filename);
        exit(1);
    }
   
    // Write the file header
    file_header fh;
    memset(&fh, 0, FILE_HEADER_SIZE);
    memcpy(fh.filetype, "BM", 2);
    fh.filesize = FILE_HEADER_SIZE + BMP_HEADER_SIZE + image_data_size;
    fh.data_offset = FILE_HEADER_SIZE + BMP_HEADER_SIZE;
    fwrite(&fh, FILE_HEADER_SIZE, 1, file);
   
    // Write the BMP header
    bmp_header bh;
    memset(&bh, 0, BMP_HEADER_SIZE);
    bh.header_size = BMP_HEADER_SIZE;
    bh.width = width;
    bh.height = height;
    bh.num_planes = 1;
    bh.bpp = 24;
    bh.compression_type = 0;
    bh.image_size_bytes = image_data_size;
    fwrite(&bh, BMP_HEADER_SIZE, 1, file);
   
    // Write the image data
    fwrite(image_buffer, 1, image_data_size, file);
   
    // Close the file
    fclose(file);
}

int main() {
    // Read the input image
    unsigned char *image_buffer;
    unsigned int width, height;
    read_bmp("input.bmp", &image_buffer, &width, &height);
    
    // Hide the message in the image
    hide_message(image_buffer, "This is a secret message!");
    
    // Write the steganographed image to disk
    write_bmp("output.bmp", image_buffer, width, height);
    
    // Extract the message from the image and print it to the console
    char message[256];
    extract_message(image_buffer, message, sizeof(message));
    printf("Extracted message: %s\n", message);
    
    // Free the image buffer memory
    free(image_buffer);
    
    return 0;
}