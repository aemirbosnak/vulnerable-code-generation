//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 14
#define ASCII_LENGTH 95

char ascii_chars[ASCII_LENGTH][CHAR_HEIGHT][CHAR_WIDTH+1]; // array to hold the ascii characters

void load_ascii_chars() {
    FILE *fp = fopen("asciichars.txt", "r"); // file containing the ascii characters
    if (fp == NULL) {
        printf("Error: ascii chars file not found\n");
        exit(1);
    }

    int index = 0, row = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            row++;
            continue;
        }
        if (row == CHAR_HEIGHT) {
            row = 0;
            index++;
            continue;
        }
        ascii_chars[index][row][strlen(ascii_chars[index][row])] = c;
    }

    fclose(fp);
}

char get_ascii_char(int avg_color) {
    float interval = 255.0 / ASCII_LENGTH;
    return ascii_chars[(int) (avg_color/interval)][0][0]; // return the corresponding ascii char based on the average color
}

int main(int argc, char const *argv[]) {
    srand(time(NULL)); // seed the random generator
    char filename[100];
    printf("Enter the filename of the image to convert to ascii: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb"); // open the image file
    if (fp == NULL) {
        printf("Error: image file not found\n");
        exit(1);
    }

    char header[54];
    fread(header, sizeof(unsigned char), 54, fp); // read the header of the bmp file

    int width = *(int*)(header + 18); // extract the width of the image
    int height = *(int*)(header + 22); // extract the height of the image
    int row_size = (width*3 + 3) & (~3); // calculate the row size by rounding up to the nearest multiple of 4
    unsigned char img_data[MAX_HEIGHT][MAX_WIDTH*3]; // array to hold the image data in bytes
    int pixel_count = 0;
    for (int i = height-1; i >= 0; i--) { // read the image data row by row and store it as bytes in img_data
        fread(img_data[i], sizeof(unsigned char), row_size, fp);
        for (int j = 0; j < width*3; j+=3) { // count the number of pixels in the image
            if (img_data[i][j] != 0 || img_data[i][j+1] != 0 || img_data[i][j+2] != 0)
                pixel_count++;
        }
    }
    fclose(fp);

    load_ascii_chars(); // load the ascii characters into memory

    int scale = CHAR_WIDTH; // set the scaling factor for the ascii art (each ascii character will represent scale*scale pixels in the image)
    int num_rows = (height + scale - 1) / scale; // calculate the number of rows in the ascii art
    int num_cols = (width + scale - 1) / scale; // calculate the number of columns in the ascii art
    char ascii_art[MAX_HEIGHT][MAX_WIDTH]; // array to hold the ascii art

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            int r_start = i*scale;
            int c_start = j*scale;
            int r_end = (i+1)*scale < height ? (i+1)*scale : height;
            int c_end = (j+1)*scale < width ? (j+1)*scale : width;
            int pixel_sum = 0;
            for (int r = r_start; r < r_end; r++) {
                for (int c = c_start; c < c_end; c+=3) {
                    pixel_sum += img_data[r][c] + img_data[r][c+1] + img_data[r][c+2]; // calculate the total brightness of the pixels in the current block
                }
            }
            int avg_color = pixel_sum / (scale*scale*3); // calculate the average color of the current block
            ascii_art[i][j] = get_ascii_char(avg_color); // get the ascii char for the average color and store it in ascii_art
        }
    }

    printf("\n\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%c", ascii_art[i][j]); // print the ascii art
        }
        printf("\n");
    }
    printf("\n\n");

    float pixel_ratio = (float) pixel_count / (height*width); // calculate the ratio of non-black pixels in the image
    float char_ratio = (float) num_rows*num_cols / ASCII_LENGTH; // calculate the ratio of ascii characters used in the ascii art
    printf("Non-black pixel ratio: %.2f%%\n", pixel_ratio*100);
    printf("ASCII character ratio: %.2f%%\n", char_ratio*100);

    return 0;
}