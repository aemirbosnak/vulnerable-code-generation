//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Read the input image
    FILE* infile = fopen("input_image.ppm", "rb");
    if (infile == NULL) {
        printf("Error: Cannot open the input image file\n");
        return 1;
    }
    
    // Read the image header
    char buf[1024];
    int width, height, maxval;
    fgets(buf, sizeof(buf), infile);
    fgets(buf, sizeof(buf), infile);
    sscanf(buf, "%d %d", &width, &height);
    fgets(buf, sizeof(buf), infile);
    sscanf(buf, "%d", &maxval);

    // Allocate memory for the image data
    unsigned char* data = (unsigned char*) malloc(width*height*3*sizeof(unsigned char));
    if (data == NULL) {
        printf("Error: Cannot allocate memory for the image data\n");
        fclose(infile);
        return 1;
    }

    // Read the image data
    fread(data, sizeof(unsigned char), width*height*3, infile);
    fclose(infile);

    // Flip the image horizontally
    unsigned char* temp_row = (unsigned char*) malloc(width*3*sizeof(unsigned char));
    if (temp_row == NULL) {
        printf("Error: Cannot allocate memory for temp_row data\n");
        free(data);
        return 1;
    }

    for (int y = 0; y < height/2; y++) {
        int offset1 = y*width*3;
        int offset2 = (height-1-y)*width*3;
        for (int x = 0; x < width; x++) {
            int i1 = offset1 + x*3;
            int i2 = offset2 + x*3;
            temp_row[0] = data[i1];
            temp_row[1] = data[i1+1];
            temp_row[2] = data[i1+2];
            data[i1] = data[i2];
            data[i1+1] = data[i2+1];
            data[i1+2] = data[i2+2];
            data[i2] = temp_row[0];
            data[i2+1] = temp_row[1];
            data[i2+2] = temp_row[2];
        }
    }

    // Change the brightness and contrast of the image
    float brightness = 0.2; // Increase the brightness by 20%
    float contrast = 1.5; // Increase the contrast by 50%
    for (int y = 0; y < height; y++) {
        int offset = y*width*3;
        for (int x = 0; x < width; x++) {
            int i = offset + x*3;
            float r = (float)data[i]/(float)maxval;
            float g = (float)data[i+1]/(float)maxval;
            float b = (float)data[i+2]/(float)maxval;
            r = (r - 0.5)*contrast + 0.5 + brightness;
            g = (g - 0.5)*contrast + 0.5 + brightness;
            b = (b - 0.5)*contrast + 0.5 + brightness;
            data[i] = (unsigned char) (round(r*maxval));
            data[i+1] = (unsigned char) (round(g*maxval));
            data[i+2] = (unsigned char) (round(b*maxval));
        }
    }

    // Write the output image
    FILE* outfile = fopen("output_image.ppm", "wb");
    if (outfile == NULL) {
        printf("Error: Cannot open the output image file\n");
        free(data);
        free(temp_row);
        return 1;
    }

    fprintf(outfile, "P6\n");
    fprintf(outfile, "%d %d\n", width, height);
    fprintf(outfile, "%d\n", maxval);
    fwrite(data, sizeof(unsigned char), width*height*3, outfile);
    fclose(outfile);
    
    // Free memory
    free(data);
    free(temp_row);

    return 0;
}