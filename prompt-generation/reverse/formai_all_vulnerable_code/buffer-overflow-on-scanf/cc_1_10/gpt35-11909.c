//FormAI DATASET v1.0 Category: Image compression ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 1000000 // maximum number of pixels possible in an image
#define MAX_COLOR 256 // maximum pixel color value

// struct to hold pixel data
typedef struct Pixel {
    int red;
    int green;
    int blue;
} Pixel;

int main() {

    // read input file name
    char file_name[100];
    printf("Enter the name of the input file: ");
    scanf("%s", file_name);

    // read output file name
    char output_file_name[100];
    printf("\nEnter the name of the output file (without extension): ");
    scanf("%s", output_file_name);
    strcat(output_file_name, ".cmp");

    // open input file
    FILE *input_file = fopen(file_name, "r");
    if(input_file == NULL) {
        printf("\nError: Could not open input file!\n");
        return -1;
    }

    // read image data
    Pixel pixels[MAX_PIXELS];
    int num_pixels = 0;
    int red, green, blue;
    while(fscanf(input_file, "%d %d %d", &red, &green, &blue) != EOF) {
        if(num_pixels == MAX_PIXELS) {
            printf("\nError: Image has too many pixels!\n");
            fclose(input_file);
            return -1;
        }
        Pixel p = {red, green, blue};
        pixels[num_pixels++] = p;
    }
    fclose(input_file);

    // open output file
    FILE *output_file = fopen(output_file_name, "wb");
    if(output_file == NULL) {
        printf("\nError: Could not create output file!\n");
        return -1;
    }

    // write number of pixels to output file
    fwrite(&num_pixels, sizeof(int), 1, output_file);

    // write pixel data to output file
    int i, j;
    unsigned char r, g, b;
    for(i = 0; i < num_pixels; i++) {
        r = (unsigned char)((double)pixels[i].red / MAX_COLOR * 255);
        g = (unsigned char)((double)pixels[i].green / MAX_COLOR * 255);
        b = (unsigned char)((double)pixels[i].blue / MAX_COLOR * 255);
        fwrite(&r, sizeof(unsigned char), 1, output_file);
        fwrite(&g, sizeof(unsigned char), 1, output_file);
        fwrite(&b, sizeof(unsigned char), 1, output_file);
    }
    fclose(output_file);

    printf("\nImage compression complete!\n");

    return 0;
}