//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

/* The height and the width of the image file */
#define IMG_HEIGHT 100
#define IMG_WIDTH 100

void print_ascii_art(char img[IMG_HEIGHT][IMG_WIDTH]) {
    for(int i=0; i<IMG_HEIGHT; i++) { // Looping through each row
        for(int j=0; j<IMG_WIDTH; j++) { // Looping through each column
            /* The character to print based on the intensity of the pixel */
            char c = img[i][j] < 64 ? '@' :
                     img[i][j] < 128 ? '#' :
                     img[i][j] < 192 ? '+' : '.';
            
            printf("%c", c); // Printing the character
        }
        printf("\n"); // Moving to the next line
    }
}

int main() {
    FILE *fptr;
    char filename[100];
    printf("Enter the name of the image file (example: img.pgm): ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    /* Ignoring the first three lines of the PGM file */
    char magic_num[3];
    fgets(magic_num, sizeof magic_num, fptr);
    char dimensions[12];
    fgets(dimensions, sizeof dimensions, fptr);
    int max_val;
    fscanf(fptr, "%d", &max_val);
    /* Allocating memory for the image array */
    char img[IMG_HEIGHT][IMG_WIDTH];
    for(int i=0; i<IMG_HEIGHT; i++) {
        for(int j=0; j<IMG_WIDTH; j++) {
            /* Storing the pixel intensity in the image array */
            fscanf(fptr, "%hhu", &img[i][j]);
        }
    }

    /* Calling the function to print the ASCII art */
    print_ascii_art(img);

    return 0;
}