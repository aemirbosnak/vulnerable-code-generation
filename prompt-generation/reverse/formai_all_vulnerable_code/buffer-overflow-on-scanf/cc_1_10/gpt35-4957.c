//FormAI DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pixel{
    unsigned char r, g, b;
};

typedef struct pixel Pixel;

void read_pixel(FILE *in, Pixel *p);
void write_pixel(FILE *out, Pixel *p);
void copy_pixel(Pixel *src, Pixel *dest);
void gray_scale(Pixel *p);
void blur(unsigned char *input_buffer, unsigned char *output_buffer, int width, int height, int radius);

int main(int argc, char **argv) {
  
    int radius;
    FILE *in, *out;
    Pixel p, q;
    //check if enough arguments are entered i.e. check if the user entered both input and output file name
    if(argc != 3){
        printf("Usage: image_editor [input-file] [output-file]\n");
        exit(EXIT_FAILURE);
    }
    // open input file in read mode
    if((in = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open input file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // open output file in write mode
    if((out = fopen(argv[2], "wb")) == NULL){
        printf("Cannot open output file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    // read radius value from user
    printf("Enter blur radius: ");
    scanf("%d", &radius);

    // read each pixel from input file, grey scale it and save it to output file.
    while(fread(&p, sizeof(Pixel), 1, in)){
        q = p;
        gray_scale(&q);
        write_pixel(out, &q);
    }

    // go back to the beginning of the input file
    rewind(in);

    // read the header bytes from input file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, in);

    // calculate image width and height from header bytes
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    //allocate a buffer for the image
    unsigned char * input_buffer = (unsigned char*) malloc(width * height * 3);
    unsigned char * output_buffer = (unsigned char*) malloc(width * height * 3);

    //read input image buffer
    fread(input_buffer, sizeof(unsigned char), width*height*3, in);

    //apply blur filter
    blur(input_buffer, output_buffer, width, height, radius);

    //write output image buffer
    fwrite(header, sizeof(unsigned char), 54, out);
    fwrite(output_buffer, sizeof(unsigned char), width*height*3, out);

    //free memory
    free(input_buffer);
    free(output_buffer);

    // close input and output files
    fclose(in);
    fclose(out);

    return 0;
}


void read_pixel(FILE *in, Pixel *p){
    p->b = fgetc(in);
    p->g = fgetc(in);
    p->r = fgetc(in);
}

void write_pixel(FILE *out, Pixel *p){
    fputc(p->b, out);
    fputc(p->g, out);
    fputc(p->r, out);
}

void copy_pixel(Pixel *src, Pixel *dest){
    dest->r = src->r;
    dest->g = src->g;
    dest->b = src->b;
}

void gray_scale(Pixel *p){
    unsigned char gray = (unsigned char)(0.299 * p->r + 0.587 * p->g + 0.114 * p->b);
    p->r = p->g = p->b = gray;
}


void blur(unsigned char *input_buffer, unsigned char *output_buffer, int width, int height, int radius){
    int i,j,k,l;
    int r2 = radius * radius;
    int f = (radius * 2) + 1;
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            Pixel avg = {0, 0, 0};
            int num_pixels = 0;
            for(k = -radius; k <= radius; k++){
                for(l = -radius; l <= radius; l++){
                    int x = j + l;
                    int y = i + k;
                    if(x >= 0 && x < width && y >= 0 && y < height){
                        Pixel p = {input_buffer[(y * width + x) * 3], input_buffer[(y * width + x) * 3 + 1], input_buffer[(y * width + x) * 3 + 2]};
                        avg.r += p.r;
                        avg.g += p.g;
                        avg.b += p.b;
                        num_pixels++;
                    }
                }
            }
            avg.r /= num_pixels;
            avg.g /= num_pixels;
            avg.b /= num_pixels;
            output_buffer[(i*width + j)*3] = avg.b;
            output_buffer[(i*width + j)*3 + 1] = avg.g;
            output_buffer[(i*width + j)*3 + 2] = avg.r;
        }
    }
}