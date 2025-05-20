//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f_in, *f_out;
    int i, j, width, height, maxval;
    unsigned char *image, *p_in, *p_out;

    f_in = fopen("input.pgm","rb");
    if(f_in == NULL){
        printf("File not found!");
        return 0;
    }

    //read header of pgm file
    char buffer[100];
    fgets(buffer, sizeof(buffer), f_in);
    fgets(buffer, sizeof(buffer), f_in);
    sscanf(buffer, "%d %d", &width, &height);
    fgets(buffer, sizeof(buffer), f_in);
    sscanf(buffer, "%d", &maxval);

    //allocate memory for image data
    image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if(image == NULL){
        printf("Memory allocation error!");
        return 1;
    }

    //read image data
    fread(image, sizeof(unsigned char), width * height, f_in);
    fclose(f_in);

    //allocate memory for output image data
    unsigned char *output_image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if(output_image == NULL){
        printf("Memory allocation error!");
        return 1;
    }
    p_in = image;
    p_out = output_image;

    //flip image horizontally
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            p_out[i*width+j] = p_in[i*width+(width-j-1)];
        }
    }

    //increase contrast
    float factor = 1.5;
    for(i=0; i<width*height; i++){
        output_image[i] = (unsigned char)(factor * (output_image[i] - maxval/2) + maxval/2);
    }

    //save output image
    f_out = fopen("output.pgm","wb");
    fprintf(f_out,"P5\n%d %d\n%d\n",width,height,maxval);
    fwrite(output_image, sizeof(unsigned char), width*height, f_out);
    fclose(f_out);

    free(image);
    free(output_image);
    return 0;
}