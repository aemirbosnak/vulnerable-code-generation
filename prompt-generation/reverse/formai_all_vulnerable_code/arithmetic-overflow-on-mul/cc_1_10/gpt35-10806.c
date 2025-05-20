//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to read in a file into a buffer
char* read_file(const char* file_name) {
    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", file_name);
        return NULL;
    }
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = (char*)malloc(size + 1);
    memset(buffer, '\0', size + 1);
    fread(buffer, 1, size, fp);
    fclose(fp);
    return buffer;
}

// function to write a buffer to a file
void write_file(const char* file_name, char* buffer, size_t size) {
    FILE* fp = fopen(file_name, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", file_name);
        return;
    }
    
    fwrite(buffer, 1, size, fp);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input_file output_file operation\n", argv[0]);
        fprintf(stderr, "Operations:\n");
        fprintf(stderr, "  invert  - inverts the colors of the image\n");
        fprintf(stderr, "  gray    - converts the image to grayscale\n");
        exit(1);
    }
    
    char* input_file_name = argv[1];
    char* output_file_name = argv[2];
    char* operation = argv[3];
    
    char* input_buffer = read_file(input_file_name);
    if (input_buffer == NULL) {
        exit(1);
    }
    
    // determine the size of the image
    int width = input_buffer[18] * 256 + input_buffer[19];
    int height = input_buffer[22] * 256 + input_buffer[23];
    int bpp = input_buffer[28];  // bytes per pixel
    
    char* output_buffer = (char*)malloc(width * height * bpp + 54);
    memset(output_buffer, '\0', width * height * bpp + 54);
    memcpy(output_buffer, input_buffer, 54);  // copy the header
    
    // perform the specified operation on the image
    if (strcmp(operation, "invert") == 0) {
        for (int i = 54; i < width * height * bpp + 54; i++) {
            output_buffer[i] = 255 - input_buffer[i];
        }
    } else if (strcmp(operation, "gray") == 0) {
        for (int i = 54; i < width * height * bpp + 54; i += bpp) {
            int gray_value = (input_buffer[i] + input_buffer[i + 1] + input_buffer[i + 2]) / 3;
            output_buffer[i] = gray_value;
            output_buffer[i + 1] = gray_value;
            output_buffer[i + 2] = gray_value;
        }
    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        exit(1);
    }
    
    write_file(output_file_name, output_buffer, width * height * bpp + 54);
    
    free(input_buffer);
    free(output_buffer);
    
    return 0;
}