//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXWIDTH 80
#define MAXHEIGHT 80

void draw_pixel(int color);
void generate_ascii_art(int img[MAXWIDTH][MAXHEIGHT], int width, int height);
void print_medieval_style(int color);

int main(){
    const char* filename = "medieval_example.pgm"; //replace with your input filename
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: could not open file %s", filename);
        return 1;
    }

    //read the image data
    char buffer[20];
    int max_col_val, width, height;
    fgets(buffer, 20, fp); //skip the first line
    fgets(buffer, 20, fp); //read the width and height
    sscanf(buffer, "%d %d", &width, &height);
    int img[MAXWIDTH][MAXHEIGHT];

    fgets(buffer, 20, fp); //skip the max color value
    max_col_val = atoi(fgets(buffer, 20, fp));
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            img[j][i] = (int)fgetc(fp);
        }
    }
    fclose(fp);

    //generate the ascii art
    generate_ascii_art(img, width, height);

    return 0;
}

void generate_ascii_art(int img[MAXWIDTH][MAXHEIGHT], int width, int height){
    int char_height = 8;
    int char_width = 6;
    int scale_factor = 255/95; //255 is max color value for PGM, 95 is the number of ASCII characters we can use
    char ascii_art[MAXHEIGHT*char_height][MAXWIDTH*char_width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int color = img[j][i] / scale_factor;
            print_medieval_style(color);
        }
        printf("\n");
    }
}

void print_medieval_style(int color){
    const char* palette = "@#&$%@**=+-:;,. ";
    printf("\033[0;3%dm%c", color, palette[color]);
}

void draw_pixel(int color){
    const char* palette = "@#&$%@**=+-:;,. ";
    printf("%c", palette[color]);
}