//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PIXEL_SIZE 3 //size of each pixel in bytes
#define MAX_PIXEL_VALUE 255 //maximum value of a pixel

//function to get the ASCII character that represents the grayscale value
char get_char(int value){
    char c;
    if(value >= 230){
        c = '@';
    } else if(value >= 200){
        c = 'M';
    } else if(value >= 180){
        c = '#';
    } else if(value >= 160){
        c = 'X';
    } else if(value >= 130){
        c = 'D';
    } else if(value >= 100){
        c = 'O';
    } else if(value >= 70){
        c = '*';
    } else if(value >= 50){
        c = 'o';
    } else if(value >= 30){
        c = ':';
    } else {
        c = '.';
    }
    return c;
}

int main(int argc, char **argv){
    if(argc != 3){
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if(!input_file){
        perror(argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if(!output_file){
        perror(argv[2]);
        fclose(input_file);
        return 1;
    }

    //get image size
    fseek(input_file, 0, SEEK_END);
    long size = ftell(input_file);
    rewind(input_file);
    int width = 0, height = 0;
    bool read_width = true;
    char c;
    while(ftell(input_file) < size){
        c = fgetc(input_file);
        if(c == ' ' && read_width){
            read_width = false;
        } else if(c == '\n'){
            read_width = true;
            height++;
        } else if(read_width){
            width = width * 10 + c - '0';
        }
    }
    rewind(input_file);

    //allocate memory for image data
    unsigned char *pixels = (unsigned char*) malloc(width * height * PIXEL_SIZE);
    if(!pixels){
        perror("Error allocating memory");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    //read the image data from the input file
    int i = 0;
    while(ftell(input_file) < size){
        c = fgetc(input_file);
        if(c == '\n'){
            continue;
        }
        pixels[i++] = c;
    }

    //convert the image to ASCII art
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            //get the grayscale value of the pixel
            int value = (int) pixels[(y * width + x) * PIXEL_SIZE];
            //get the ASCII character that represents the grayscale value
            char c = get_char(value);
            //write the character to the output file
            fprintf(output_file, "%c%c", c, c);
        }
        fprintf(output_file, "\n");
    }

    //free memory and close files
    free(pixels);
    fclose(input_file);
    fclose(output_file);

    return 0;
}