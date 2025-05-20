//FormAI DATASET v1.0 Category: Image Editor ; Style: real-life
#include <stdio.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

unsigned char image[MAX_WIDTH][MAX_HEIGHT];

int width, height;

void grayscale() {
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            unsigned char r = image[i][j] >> 16;
            unsigned char g = image[i][j] >> 8;
            unsigned char b = image[i][j];
            unsigned char avg = (r+g+b)/3;
            image[i][j] = (avg << 16) | (avg << 8) | avg;
        }
    }
}

void blur() {
    unsigned char temp[MAX_WIDTH][MAX_HEIGHT];
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            unsigned int count = 0;
            unsigned int r = 0, g = 0, b = 0;
            for(int k = i-1; k <= i+1; k++) {
                for(int l = j-1; l <= j+1; l++) {
                    if(k >= 0 && l >= 0 && k < width && l < height) {
                        count++;
                        r += image[k][l] >> 16;
                        g += image[k][l] >> 8;
                        b += image[k][l];
                    }
                }
            }
            temp[i][j] = ((r/count) << 16) | ((g/count) << 8) | (b/count);
        }
    }
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            image[i][j] = temp[i][j];
        }
    }
}

void rotate(int degrees) {
    unsigned char temp[MAX_WIDTH][MAX_HEIGHT];
    if(degrees == 90) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                temp[j][height-i-1] = image[i][j];
            }
        }
        int temp2 = width;
        width = height;
        height = temp2;
    }
    else if(degrees == 180) {
        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++) {
                temp[i][j] = image[width-i-1][height-j-1];
            }
        }
    }
    else if(degrees == 270) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                temp[width-j-1][i] = image[i][j];
            }
        }
        int temp2 = width;
        width = height;
        height = temp2;
    }
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            image[i][j] = temp[i][j];
        }
    }
}

int main() {
    FILE *file = fopen("image.raw", "rb");
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            fread(&image[i][j], sizeof(unsigned char), 3, file);
        }
    }
    fclose(file);
    int selection = -1;
    while(selection != 0) {
        printf("Please choose an option: \n");
        printf("1: Grayscale\n");
        printf("2: Blur\n");
        printf("3: Rotate 90 degrees\n");
        printf("4: Rotate 180 degrees\n");
        printf("5: Rotate 270 degrees\n");
        printf("0: Save and exit\n");
        scanf("%d", &selection);
        switch(selection) {
            case 1:
                grayscale();
                break;
            case 2:
                blur();
                break;
            case 3:
                rotate(90);
                break;
            case 4:
                rotate(180);
                break;
            case 5:
                rotate(270);
                break;
            case 0:
                file = fopen("image.out", "wb");
                fwrite(&width, sizeof(int), 1, file);
                fwrite(&height, sizeof(int), 1, file);
                for(int i = 0; i < width; i++) {
                    for(int j = 0; j < height; j++) {
                        fwrite(&image[i][j], sizeof(unsigned char), 3, file);
                    }
                }
                fclose(file);
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
    return 0;
}