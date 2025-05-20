//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//function to convert image to greyscale
void greyscale(unsigned char *image, int width, int height){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int index = i * width + j;
            int R = *(image + 3*index);
            int G = *(image + 3*index + 1);
            int B = *(image + 3*index + 2);
            int grey = 0.2989 * R + 0.5870 * G + 0.1140 * B;
            *(image + 3*index) = grey;
            *(image + 3*index + 1) = grey;
            *(image + 3*index + 2) = grey;
        }
    }
}

//function to print ascii art representation of image
void print_ascii(unsigned char *image, int width, int height){
    int scale_factor = 3;
    float aspect_ratio = (float) width/height;
    int ascii_width = (int) round(scale_factor * aspect_ratio * width);
    int ascii_height = scale_factor * height;
    int index = 0;
    char ascii_chars[11] = "@B%8WM#*oahkbdpqwmZO0Q$Lc?v]ij1tnwiroluxzj](/7|<\-. ";
    for(int i=0;i<ascii_height;i++){
        for(int j=0;j<ascii_width;j++){
            int grey = *(image + index);
            int ascii_index = (int) round(grey/25.5);
            char ascii_char = ascii_chars[ascii_index];
            putchar(ascii_char);
            index += scale_factor;
        }
        putchar('\n');
    }
}

int main(){
    char filename[] = "example.jpg";
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error in opening file\n");
        exit(1);
    }
    //determine size of file
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //allocate memory to load image
    unsigned char *image = (unsigned char*)malloc(sizeof(unsigned char)*filesize);
    if(image == NULL){
        printf("Error in allocating memory\n");
        exit(1);
    }
    fread(image, sizeof(unsigned char), filesize, fp);
    fclose(fp);
    int width, height;
    if(image[0]=='B' && image[1]=='M'){
        int pixel_offset = *(int*)&image[10];
        width = *(int*)&image[18];
        height = *(int*)&image[22];
        unsigned char *pixel_data = &image[pixel_offset];
        greyscale(pixel_data, width, height);
        print_ascii(pixel_data, width, height);
    }
    else{
        printf("Invalid file format\n");
        exit(1);
    }
    free(image);
    return 0;
}