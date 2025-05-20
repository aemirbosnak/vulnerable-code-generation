//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// Define constants
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_PIXELS 1000000
#define MAX_ASCII_CHARS 70

// Define struct for image data
typedef struct {
    int width;
    int height;
    char pixels[MAX_HEIGHT][MAX_WIDTH];
} ImageData;

// Define struct for ASCII conversion data
typedef struct {
    int num_chars;
    char chars[MAX_ASCII_CHARS];
    int thresholds[MAX_ASCII_CHARS];
} AsciiConversionData;

// Define function for reading image data
void read_image(char* filename, ImageData* data) {
    int fd = open(filename, O_RDONLY);

    // Read image header
    char magic_number[3];
    read(fd, magic_number, 2);
    magic_number[2] = '\0';

    int width, height, maxval;
    scanf("%d %d %d", &width, &height, &maxval);

    // Read image pixels
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int pixel_val;
            read(fd, &pixel_val, 1);
            data->pixels[i][j] = (char)pixel_val;
        }
    }

    close(fd);
    data->width = width;
    data->height = height;
}

// Define function for converting image pixels to ASCII characters
void convert_to_ascii(ImageData* data, AsciiConversionData* conversion_data) {
    char* ascii_chars = "@%#*+=-:. ";
    int num_ascii_chars = strlen(ascii_chars);

    int num_pixels = data->width * data->height;
    int pixel_values[num_pixels];
    int max_pixel = 0;

    // Convert image pixels to grayscale values and record maximum
    for(int i=0; i<data->height; i++) {
        for(int j=0; j<data->width; j++) {
            pixel_values[i*data->width + j] = data->pixels[i][j];
            if(pixel_values[i*data->width + j] > max_pixel) {
                max_pixel = pixel_values[i*data->width + j];
            }
        }
    }

    // Calculate thresholds and corresponding ASCII characters
    int range = max_pixel / (num_ascii_chars - 1);
    for(int i=0; i<num_ascii_chars; i++) {
        conversion_data->chars[i] = ascii_chars[i];
        conversion_data->thresholds[i] = i * range;
    }

    int ascii_values[num_pixels];

    // Assign an ASCII character to each pixel based on its grayscale value
    for(int i=0; i<num_pixels; i++) {
        int pixel_val = pixel_values[i];
        int ascii_val = ((num_ascii_chars - 1) * pixel_val) / max_pixel;
        ascii_values[i] = ascii_val;
    }

    // Determine the most frequent ASCII character and reduce number of unique characters
    int char_frequencies[num_ascii_chars];
    for(int i=0; i<num_ascii_chars; i++) {
        char_frequencies[i] = 0;
    }

    for(int i=0; i<num_pixels; i++) {
        char_frequencies[ascii_values[i]]++;
    }

    int most_frequent_char = 0, max_frequency = 0;
    for(int i=0; i<num_ascii_chars; i++) {
        if(char_frequencies[i] > max_frequency) {
            most_frequent_char = i;
            max_frequency = char_frequencies[i];
        }
    }

    int num_new_chars = 0;
    for(int i=0; i<num_ascii_chars; i++) {
        if(i == most_frequent_char || char_frequencies[i] > 0.1 * max_frequency) {
            conversion_data->thresholds[num_new_chars] = conversion_data->thresholds[i];
            conversion_data->chars[num_new_chars] = conversion_data->chars[i];
            num_new_chars++;
        }
    }

    // Replace old conversion data with new reduced data
    conversion_data->num_chars = num_new_chars;

    // Print ASCII characters to console
    for(int i=0; i<data->height; i++) {
        for(int j=0; j<data->width; j++) {
            int pixel_val = pixel_values[i*data->width + j];
            int ascii_val = 0;

            for(int k=0; k<conversion_data->num_chars; k++) {
                if(pixel_val >= conversion_data->thresholds[k]) {
                    ascii_val = k;
                } else {
                    break;
                }
            }

            printf("%c", conversion_data->chars[ascii_val]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: ./image_to_ascii <input_image>\n");
        return 1;
    }

    char* filename = argv[1];

    ImageData image_data;
    AsciiConversionData ascii_conversion_data;

    read_image(filename, &image_data);
    convert_to_ascii(&image_data, &ascii_conversion_data);

    return 0;
}