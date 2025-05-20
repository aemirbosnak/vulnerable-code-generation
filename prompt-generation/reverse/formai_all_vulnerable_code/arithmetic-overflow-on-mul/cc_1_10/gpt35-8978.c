//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
#include <stdio.h>

int main()
{
    int rows, cols, max_val;
    FILE *input_file, *output_file;

    // open the input file
    input_file = fopen("input.pgm", "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // read the image header
    fscanf(input_file, "P5\n%d %d\n%d\n", &cols, &rows, &max_val);

    // allocate memory for the image data
    unsigned char *image_data = (unsigned char*)malloc(rows * cols * sizeof(unsigned char));

    // read the image data
    fread(image_data, sizeof(unsigned char), rows * cols, input_file);

    // close the input file
    fclose(input_file);

    // perform image processing tasks
    // flip image horizontally
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols/2; j++) {
            unsigned char temp = image_data[i*cols + j];
            image_data[i*cols + j] = image_data[i*cols + cols - j - 1];
            image_data[i*cols + cols - j - 1] = temp;
        }
    }

    // increase contrast by 20%
    for(int i=0; i<rows*cols; i++) {
        unsigned char pixel = image_data[i];
        if(pixel < 128)
            image_data[i] = (unsigned char)(pixel * 0.8);
        else
            image_data[i] = (unsigned char)(pixel * 1.2);
    }

    // write the output file
    output_file = fopen("output.pgm", "wb");
    fprintf(output_file, "P5\n%d %d\n%d\n", cols, rows, max_val);
    fwrite(image_data, sizeof(unsigned char), rows * cols, output_file);

    // close the output file
    fclose(output_file);

    // free allocated memory
    free(image_data);

    return 0;
}