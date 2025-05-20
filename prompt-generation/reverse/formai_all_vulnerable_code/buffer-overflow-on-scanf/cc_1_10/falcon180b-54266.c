//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000
#define WHITE '\033[0m'
#define BLACK '\033[30m'
#define RED '\033[31m'
#define GREEN '\033[32m'
#define YELLOW '\033[33m'
#define BLUE '\033[34m'
#define MAGENTA '\033[35m'
#define CYAN '\033[36m'
#define GREY '\033[37m'

void print_ascii(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (image[i][j] == 0)
                printf(BLACK);
            else
                printf(WHITE);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char file_name[50];
    int image[MAX_SIZE][MAX_SIZE], rows, cols;

    printf("Enter the name of the image file: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "rb");

    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Move to the start of the image data
    fread(&rows, sizeof(int), 1, fp);
    fread(&cols, sizeof(int), 1, fp);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fread(&image[i][j], sizeof(int), 1, fp);
        }
    }

    fclose(fp);

    print_ascii(image, rows, cols);

    return 0;
}