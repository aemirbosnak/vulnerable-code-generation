//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

//Helper function to convert RGB to grayscale
int rgbToGreyscale(int r, int g, int b) {
    return (0.2126*r + 0.7152*g + 0.0722*b);
}

int main(int argc, char *argv[]) {
    
    //Error checking for correct usage
    if(argc < 2) {
        printf("Usage: ./ascii_converter <filename>\n");
        exit(1);
    }

    //Open image file
    FILE *fp;
    fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    //Read image header
    char buf[1024];
    fgets(buf, 1024, fp);

    //Get width and height from header
    int width, height;
    fscanf(fp, "%d %d", &width, &height);

    //Read maximum value of pixel data
    int max_val;
    fscanf(fp, "%d", &max_val);

    //Allocate memory for pixel data
    int pixel_data[height][width];

    //Read pixel data and convert to grayscale
    int r, g, b;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            fscanf(fp, "%d %d %d", &r, &g, &b);
            pixel_data[i][j] = rgbToGreyscale(r, g, b);
        }
    }

    //Close file
    fclose(fp);

    //Calculate aspect ratio and character height/width
    double aspect_ratio = (double) width / (double) height;
    int char_width = round(WIDTH / aspect_ratio);
    int char_height = round(HEIGHT * aspect_ratio);

    //Calculate pixel width/height of characters
    int pixel_width = round((double) width / (double) char_width);
    int pixel_height = round((double) height / (double) char_height);

    //Initialize array for characters
    char chars[char_height][char_width];

    //Convert pixel data to characters
    for(int i=0; i<char_height; i++) {
        for(int j=0; j<char_width; j++) {
            int sum=0;
            for(int k=i*pixel_height; k<(i+1)*pixel_height; k++) {
                for(int l=j*pixel_width; l<(j+1)*pixel_width; l++) {
                    sum += pixel_data[k][l];
                }
            }
            int avg = round((double) sum / (pixel_width * pixel_height));
            chars[i][j] = " .:-=+*#%@@"[avg/25];
        }
    }

    //Print character array
    for(int i=0; i<char_height; i++) {
        for(int j=0; j<char_width; j++) {
            printf("%c", chars[i][j]);
        }
        printf("\n");
    }

    return 0;
}