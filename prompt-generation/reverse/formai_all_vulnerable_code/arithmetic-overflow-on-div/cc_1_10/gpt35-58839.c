//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to map pixel value to ASCII character
char PixelToASCII(int pixel_val){
    char ascii_val;
    switch (pixel_val){
        case 0 ... 25:  ascii_val = '@'; break;
        case 26 ... 50: ascii_val = '#'; break;
        case 51 ... 75: ascii_val = '$'; break;
        case 76 ... 100: ascii_val = '%'; break;
        case 101 ... 125: ascii_val = '&'; break;
        case 126 ... 150: ascii_val = 'X'; break;
        case 151 ... 175: ascii_val = 'A'; break;
        case 176 ... 200: ascii_val = 'S'; break;
        case 201 ... 225: ascii_val = 'O'; break;
        case 226 ... 255: ascii_val = '.'; break;
        default: ascii_val = ' ';
    }
    return ascii_val;
}

int main(){

    // Open input and output files
    FILE* input_file = fopen("input_image.bmp", "rb");
    if(input_file == NULL){
        printf("ERROR: Could not open input file\n");
        return -1;
    }
    FILE* output_file = fopen("output_ascii.txt", "w");
    if(output_file == NULL){
        printf("ERROR: Could not open output file\n");
        return -1;
    }

    // Read image header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);

    // Get image width and height information
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Get image data size and compute row padding
    int img_size = width * height * 3;
    int row_pad = (img_size / height) - width * 3;

    // Allocate memory for image data array
    unsigned char* img_data = (unsigned char*) malloc(sizeof(unsigned char)*img_size);

    // Read image data into array
    fread(img_data, sizeof(unsigned char), img_size, input_file);

    // Loop through each pixel in image data array and convert to ASCII character
    for(int i=0; i<img_size; i+=3){
        int pixel_val = (int)(0.3*img_data[i] + 0.59*img_data[i+1] + 0.11*img_data[i+2]);
        char ascii_val = PixelToASCII(pixel_val);
        fprintf(output_file, "%c", ascii_val);
        if((i+3)%width == 0){
            fprintf(output_file, "\n");
            i += row_pad;
        }
    }

    // Free dynamically allocated memory
    free(img_data);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}