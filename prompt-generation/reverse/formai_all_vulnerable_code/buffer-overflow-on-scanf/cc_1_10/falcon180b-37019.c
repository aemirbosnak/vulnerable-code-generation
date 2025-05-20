//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80

void print_image(char* image, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%c", image[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    FILE* fp;
    char filename[50];
    char image[WIDTH * 25];
    int rows, cols;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    rows = ftell(fp) / WIDTH;
    rewind(fp);

    fread(image, 1, rows * WIDTH, fp);
    fclose(fp);

    int i = 0;
    while(i < rows * WIDTH) {
        int count = 0;
        while(i < rows * WIDTH && count < 3) {
            if(image[i]!= 0) {
                printf("%c", '.');
                count++;
            } else {
                printf(" ");
            }
            i++;
        }
        printf("\n");
    }

    return 0;
}