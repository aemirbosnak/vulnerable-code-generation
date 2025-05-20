//FormAI DATASET v1.0 Category: Image Editor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void grayscale(unsigned char *image, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = i*width + j;
            unsigned char gray = (image[index*3] + image[index*3+1] + image[index*3+2])/3; // compute gray value
            image[index*3] = gray;
            image[index*3+1] = gray;
            image[index*3+2] = gray; // assign gray value to RGB
        }
    }
}

void flip(unsigned char *image, int width, int height) {
    int halfway = height/2;
    for(int i=0; i<halfway; i++) {
        for(int j=0; j<width; j++) {
            int index1 = i*width + j;
            int index2 = (height-i-1)*width + j;
            // swap pixel values
            unsigned char tempR = image[index1*3];
            unsigned char tempG = image[index1*3+1];
            unsigned char tempB = image[index1*3+2];
            image[index1*3] = image[index2*3];
            image[index1*3+1] = image[index2*3+1];
            image[index1*3+2] = image[index2*3+2];
            image[index2*3] = tempR;
            image[index2*3+1] = tempG;
            image[index2*3+2] = tempB;
        }
    }
}

void invert(unsigned char *image, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = i*width + j;
            image[index*3] = 255 - image[index*3];
            image[index*3+1] = 255 - image[index*3+1];
            image[index*3+2] = 255 - image[index*3+2]; // invert RGB values
        }
    }
}

int main() {
    char filename[MAX_LEN];
    printf("Enter image filename: ");
    scanf("%s", filename); // get input from user
    FILE *infile = fopen(filename, "rb");
    if(infile == NULL) {
        printf("Unable to open file '%s'\n", filename);
        return 1;
    }
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, infile); // read BMP header
    
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    int bitdepth = *(int*)&header[28];
    if(bitdepth != 24) { // check if image is 24-bit RGB
        printf("Error: unsupported bit depth %d\n", bitdepth);
        return 1;
    }
    
    int imagesize = *(int*)&header[34];
    unsigned char *image = (unsigned char*)malloc(imagesize);
    fread(image, sizeof(unsigned char), imagesize, infile); // read pixel data
    
    fclose(infile);
    
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Convert to grayscale\n");
        printf("2. Flip image vertically\n");
        printf("3. Invert colors\n");
        printf("4. Save and exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                grayscale(image, width, height);
                printf("Grayscale conversion complete.\n");
                break;
            case 2:
                flip(image, width, height);
                printf("Vertical flip complete.\n");
                break;
            case 3:
                invert(image, width, height);
                printf("Color inversion complete.\n");
                break;
            case 4:
                printf("Enter output filename: ");
                char outfilename[MAX_LEN];
                scanf("%s", outfilename);
                FILE *outfile = fopen(outfilename, "wb");
                if(outfile == NULL) {
                    printf("Unable to create file '%s'\n", outfilename);
                    return 1;
                }
                fwrite(header, sizeof(unsigned char), 54, outfile); // write BMP header
                fwrite(image, sizeof(unsigned char), imagesize, outfile); // write pixel data
                fclose(outfile);
                printf("Image saved as '%s'.\n", outfilename);
                free(image);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}