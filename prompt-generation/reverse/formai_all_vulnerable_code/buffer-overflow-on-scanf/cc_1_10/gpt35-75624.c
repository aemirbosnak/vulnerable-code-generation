//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 320
#define HEIGHT 240

unsigned char* readBmp(char* fileName);
void writeBmp(unsigned char* img, char* fileName);
void flipVert(unsigned char* img);
void flipHoriz(unsigned char* img);
void adjustBrightness(unsigned char* img, int brightness);
void adjustContrast(unsigned char* img, float contrast);

int main() {
    unsigned char* image = readBmp("image.bmp");
    char command[20];
    int id = 0;
    while(1) {
        printf("Player #%d, enter command: ", id);
        scanf("%s", command);
        if(strcmp(command, "flipv") == 0) {
            flipVert(image);
            writeBmp(image, "flippedVert.bmp");
            printf("Player #%d flipped the image vertically.\n", id);
            id = (id + 1) % 4;
        }
        else if(strcmp(command, "fliph") == 0) {
            flipHoriz(image);
            writeBmp(image, "flippedHoriz.bmp");
            printf("Player #%d flipped the image horizontally.\n", id);
            id = (id + 1) % 4;
        }
        else if(strcmp(command, "bright") == 0) {
            int brightness;
            printf("Enter brightness adjustment (-255 to 255): ");
            scanf("%d", &brightness);
            adjustBrightness(image, brightness);
            writeBmp(image, "adjustedBrightness.bmp");
            printf("Player #%d adjusted the brightness.\n", id);
            id = (id + 1) % 4;
        }
        else if(strcmp(command, "cont") == 0) {
            float contrast;
            printf("Enter contrast adjustment (0.0 to 4.0): ");
            scanf("%f", &contrast);
            adjustContrast(image, contrast);
            writeBmp(image, "adjustedContrast.bmp");
            printf("Player #%d adjusted the contrast.\n", id);
            id = (id + 1) % 4;
        }
        else if(strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command. Try again.\n");
        }
    }
    return 0;
}

unsigned char* readBmp(char* fileName) {
    FILE* file = fopen(fileName, "rb");
    unsigned char* image = malloc(WIDTH * HEIGHT * 3);
    fseek(file, 54, SEEK_SET);
    fread(image, WIDTH * HEIGHT * 3, 1, file);
    fclose(file);
    return image;
}

void writeBmp(unsigned char* img, char* fileName) {
    FILE* file = fopen(fileName, "wb");
    unsigned char info[54] = {0};
    info[0] = 'B';
    info[1] = 'M';
    info[2] = 54;
    info[3] = 0;
    info[4] = 40;
    info[18] = WIDTH;
    info[22] = HEIGHT;
    info[28] = 24;
    fwrite(info, 1, 54, file);
    fwrite(img, WIDTH * HEIGHT * 3, 1, file);
    fclose(file);
}

void flipVert(unsigned char* img) {
    unsigned char temp[WIDTH * 3];
    int row;
    for(row = 0; row < HEIGHT / 2; row++) {
        memcpy(temp, &img[row * WIDTH * 3], WIDTH * 3);
        memcpy(&img[row * WIDTH * 3], &img[(HEIGHT - row - 1) * WIDTH * 3], WIDTH * 3);
        memcpy(&img[(HEIGHT - row - 1) * WIDTH * 3], temp, WIDTH * 3);
    }
}

void flipHoriz(unsigned char* img) {
    int row, col;
    for(row = 0; row < HEIGHT; row++) {
        for(col = 0; col < WIDTH / 2; col++) {
            unsigned char temp[3];
            memcpy(temp, &img[row * WIDTH * 3 + col * 3], 3);
            memcpy(&img[row * WIDTH * 3 + col * 3], &img[row * WIDTH * 3 + (WIDTH - col - 1) * 3], 3);
            memcpy(&img[row * WIDTH * 3 + (WIDTH - col - 1) * 3], temp, 3);
        }
    }
}

void adjustBrightness(unsigned char* img, int brightness) {
    int row, col;
    for(row = 0; row < HEIGHT; row++) {
        for(col = 0; col < WIDTH; col++) {
            int b = img[row * WIDTH * 3 + col * 3];
            int g = img[row * WIDTH * 3 + col * 3 + 1];
            int r = img[row * WIDTH * 3 + col * 3 + 2];
            b += brightness;
            g += brightness;
            r += brightness;
            if(b < 0) b = 0;
            else if(b > 255) b = 255;
            if(g < 0) g = 0;
            else if(g > 255) g = 255;
            if(r < 0) r = 0;
            else if(r > 255) r = 255;
            img[row * WIDTH * 3 + col * 3] = b;
            img[row * WIDTH * 3 + col * 3 + 1] = g;
            img[row * WIDTH * 3 + col * 3 + 2] = r;
        }
    }
}

void adjustContrast(unsigned char* img, float contrast) {
    int row, col;
    for(row = 0; row < HEIGHT; row++) {
        for(col = 0; col < WIDTH; col++) {
            int b = img[row * WIDTH * 3 + col * 3];
            int g = img[row * WIDTH * 3 + col * 3 + 1];
            int r = img[row * WIDTH * 3 + col * 3 + 2];
            b = (b - 128) * contrast + 128;
            g = (g - 128) * contrast + 128;
            r = (r - 128) * contrast + 128;
            if(b < 0) b = 0;
            else if(b > 255) b = 255;
            if(g < 0) g = 0;
            else if(g > 255) g = 255;
            if(r < 0) r = 0;
            else if(r > 255) r = 255;
            img[row * WIDTH * 3 + col * 3] = b;
            img[row * WIDTH * 3 + col * 3 + 1] = g;
            img[row * WIDTH * 3 + col * 3 + 2] = r;
        }
    }
}