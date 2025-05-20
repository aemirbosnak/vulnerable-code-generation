//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <imagefile>\n", argv[0]);
        return 0;
    }
 
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open file: %s\n", filename);
        return 0;
    }
 
    fseek(fp, 0L, SEEK_END);
    long int numbytes = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
 
    char *image = (char*) malloc(numbytes);
    if (!image) {
        fclose(fp);
        printf("Memory allocation failed\n");
        return 0;
    }
 
    fread(image, sizeof(char), numbytes, fp);
    fclose(fp);
 
    char *ascii = (char*) calloc(numbytes, sizeof(char));
    if (!ascii) {
        free(image);
        printf("Memory allocation failed\n");
        return 0;
    }
 
    // convert each pixel to an ASCII character
    int i, j;
    int width = 80; // desired width of ASCII art output
    for (i = 0; i < numbytes - 3; i += 3) {
        int R = (int) image[i];
        int G = (int) image[i+1];
        int B = (int) image[i+2];
        int avg = (R + G + B) / 3;
        int index = (i / 3) % width;
        int row = (i / 3) / width;
 
        switch (avg / 16) {
            case 0: ascii[row*width + index] = ' '; break; // black
            case 1: ascii[row*width + index] = '.'; break;
            case 2: ascii[row*width + index] = '-'; break;
            case 3: ascii[row*width + index] = '='; break;
            case 4: ascii[row*width + index] = '+'; break;
            case 5: ascii[row*width + index] = '*'; break;
            case 6: ascii[row*width + index] = '#'; break;
            case 7: ascii[row*width + index] = '@'; break; // white
        }
    }
 
    // print ASCII art to console
    for (i = 0; i < numbytes / 3; i += width) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii[i+j]);
        }
        printf("\n");
    }
 
    free(image);
    free(ascii);
 
    return 0;
}