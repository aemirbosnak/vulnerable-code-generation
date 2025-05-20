//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_IMAGE_SIZE 1920*1080

// Load image data from file
void load_image(char* filename, unsigned char* image_data, int* width, int* height) {
    FILE* image_file = fopen(filename, "rb");
    if (image_file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, image_file);

    *width = *(int*)&info[18];
    *height = *(int*)&info[22];

    int size = (*width)*(*height)*3;
    fread(image_data, sizeof(unsigned char), size, image_file);

    fclose(image_file);
}

// Save image data to file
void save_image(char* filename, unsigned char* image_data, int width, int height) {
    FILE* image_file = fopen(filename, "wb");
    if (image_file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    unsigned char info[54] = {
        0x42, 0x4d,             // BM
        0x36, 0x00, 0x0c, 0x00, // Size
        0x00, 0x00,             // Reserved
        0x00, 0x00,             // Reserved
        0x36, 0x00, 0x00, 0x00, // Offset
        0x28, 0x00, 0x00, 0x00, // Info header size
        0x00, 0x00, 0x00, 0x02, // Width
        0x00, 0x00, 0x00, 0x02, // Height
        0x01, 0x00,             // Planes
        0x18, 0x00,             // Bits per pixel
        0x00, 0x00, 0x00, 0x00, // Compression
        0x00, 0x00, 0x00, 0x00, // Image size
        0x00, 0x00, 0x00, 0x00, // X resolution
        0x00, 0x00, 0x00, 0x00, // Y resolution
        0x00, 0x00, 0x00, 0x00, // Number of colors
        0x00, 0x00, 0x00, 0x00, // Important colors
    };
    *(int*)&info[2] = 54 + width*height*3;
    *(int*)&info[18] = width;
    *(int*)&info[22] = height;
    fwrite(info, sizeof(unsigned char), 54, image_file);

    int size = width*height*3;
    fwrite(image_data, sizeof(unsigned char), size, image_file);

    fclose(image_file);
}

// Flip the image horizontally
void flip_horizontal(unsigned char* image_data, int width, int height) {
    int row_size = width * 3;
    int halfway_point = width / 2;
    unsigned char temp;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < halfway_point; col++) {
            for (int color = 0; color < 3; color++) {
                temp = image_data[row*row_size + col*3 + color];
                image_data[row*row_size + col*3 + color] = image_data[row*row_size + (width - col - 1)*3 + color];
                image_data[row*row_size + (width - col - 1)*3 + color] = temp;
            }
        }
    }
}

// Adjust the brightness of the image by a certain percentage (-100 to 100)
void adjust_brightness(unsigned char* image_data, int width, int height, int brightness_percent) {
    float brightness_factor = 1.0 + brightness_percent / 100.0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            for (int color = 0; color < 3; color++) {
                int new_value = (int)(image_data[row*width*3 + col*3 + color] * brightness_factor);
                if (new_value > 255) new_value = 255;
                if (new_value < 0) new_value = 0;
                image_data[row*width*3 + col*3 + color] = (unsigned char)new_value;
            }
        }
    }
}

int main() {
    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    int input_width, input_height;
    unsigned char input_image[MAX_IMAGE_SIZE];

    printf("Enter input image filename: ");
    scanf("%s", input_filename);

    load_image(input_filename, input_image, &input_width, &input_height);

    // Flip the image horizontally
    flip_horizontal(input_image, input_width, input_height);

    // Adjust the brightness of the image
    adjust_brightness(input_image, input_width, input_height, 25);

    // Save the modified image
    sprintf(output_filename, "%s_artistic.bmp", input_filename);
    save_image(output_filename, input_image, input_width, input_height);

    printf("Saved modified image to %s\n", output_filename);

    return 0;
}