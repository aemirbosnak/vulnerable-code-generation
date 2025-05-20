//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

char ascii_chars[] = {'M', 'N', 'X', 'D', 'K', 'O', 'G', 'I', 'E', 'H', 'A', 'B', 'W', 'P', 'Q', 'F', 'S', 'U', 'Z', 'J', 'Y', 'C', 'V', 'L', 'R', 'T', ' ', '.', ',', ':', ';', '+', '*', '?', '%', 'S', '#', '@'};

int gray_scale_converter(int r, int g, int b){
    int gray = 0.299*r + 0.587*g + 0.114*b;
    return gray;
}

int get_ascii_char(int shade){
    int num_chars = sizeof(ascii_chars)/sizeof(char);
    int char_idx = (shade * (num_chars - 1))/255;
    return ascii_chars[char_idx];
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Please provide path to the image file to convert to ASCII art.\n");
        return 1;
    }
    
    char *img_path = argv[1];
    FILE *img_file = fopen(img_path, "r");
    
    if(img_file == NULL){
        printf("Error opening image file. Please check the path and try again.\n");
        return 1;
    }
    
    // Read header of image
    char header[16];
    fgets(header, 16, img_file);
    
    // Read image width, height, and maximum shade value
    int img_width = 0;
    int img_height = 0;
    int max_shade = 0;
    fscanf(img_file, "%d %d\n%d\n", &img_width, &img_height, &max_shade);
    
    // Ensure image is not too large
    if(img_width > MAX_WIDTH || img_height > MAX_HEIGHT){
        printf("Image dimensions too large. Please choose an image with dimensions no larger than %d x %d.\n", MAX_WIDTH, MAX_HEIGHT);
        return 1;
    }
    
    // Calculate the ratio to scale down to a max of 80 characters wide
    float aspect_ratio = (float) img_width/img_height;
    int new_width = 80;
    int new_height = (int) (new_width/aspect_ratio * 0.6);
    
    // Allocate memory for the image data
    int img_data[img_height][img_width];
    char ascii_data[new_height][new_width];
    
    // Read in the pixels and convert to grayscale
    for(int i = 0; i < img_height; i++){
        for(int j = 0; j < img_width; j++){
            int r = 0;
            int g = 0;
            int b = 0;
            fscanf(img_file, "%d %d %d", &r, &g, &b);
            int gray = gray_scale_converter(r, g, b);
            img_data[i][j] = gray;
        }
    }
    
    // Scale down the image and convert to ASCII
    float height_ratio = (float) img_height/new_height;
    float width_ratio = (float) img_width/new_width;
    for(int i = 0; i < new_height; i++){
        for(int j = 0; j < new_width; j++){
            int pixel_sum = 0;
            for(int k = 0; k < height_ratio; k++){
                for(int l = 0; l < width_ratio; l++){
                    int y = (int) (i*height_ratio + k);
                    int x = (int) (j*width_ratio + l);
                    pixel_sum += img_data[y][x];
                }
            }
            int average_shade = pixel_sum/(height_ratio*width_ratio);
            char ascii_char = get_ascii_char(average_shade);
            ascii_data[i][j] = ascii_char;
        }
    }
    
    // Output the ASCII art to the console
    for(int i = 0; i < new_height; i++){
        for(int j = 0; j < new_width; j++){
            char pixel = ascii_data[i][j];
            printf("%c", pixel);
        }
        printf("\n");
    }
    
    fclose(img_file);
    return 0;
}