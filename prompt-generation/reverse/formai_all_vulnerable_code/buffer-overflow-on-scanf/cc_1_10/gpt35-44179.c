//FormAI DATASET v1.0 Category: Image Steganography ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define READ_MODE "rb"
#define WRITE_MODE "wb"
#define MAX_FILE_SIZE 1000000

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

int readImg(char *filename, pixel *array, int *width, int *height) {
    FILE *img = fopen(filename, READ_MODE);
    if(!img) {
        printf("File not found!\n");
        return -1;
    }
    char type[3];
    fgets(type, 3, img);
    if(strcmp(type, "P6") != 0) {
        printf("Incorrect image type!\n");
        return -1;
    }
    fscanf(img, "%d %d\n", width, height);
    int max_color;
    fscanf(img, "%d\n", &max_color);
    if(max_color != 255) {
        printf("Unsupported maximum color!\n");
        return -1;
    }
    fread(array, 1, *width * *height * 3, img);
    fclose(img);
    return (*width) * (*height) * 3;
}

int writeImg(char *filename, pixel *array, int width, int height) {
    FILE *img = fopen(filename, WRITE_MODE);
    if(!img) {
        printf("Error while saving image!\n");
        return -1;
    }
    fprintf(img, "P6\n");
    fprintf(img, "%d %d\n", width, height);
    fprintf(img, "255\n");
    fwrite(array, 1, width * height * 3, img);
    fclose(img);
    return 1;
}

void hideText(char *text, pixel *array, int size) {
    int index = 0;
    int ascii;
    while(text[index]) {
        ascii = (int)text[index];
        for(int i = 0; i < 8; i++) {
            if((ascii >> i) & 1) {
                if((array[size - 1].b & 1) == 0) array[size - 1].b++;
            } else {
                if((array[size - 1].b & 1) == 1) array[size - 1].b--;
            }
            size--;
        }
        index++;
    }
    for(int i = 0; i < 8; i++) {
        if((array[size - 1].b & 1) == 0) array[size - 1].b++;
        else array[size - 1].b--;
        size--;
    }
}

void extractTextFILE(char *filename, char *output) {
    FILE *img = fopen(filename, READ_MODE);
    if(!img) {
        printf("File not found!\n");
        return;
    }
    char type[3];
    fgets(type, 3, img);
    if(strcmp(type, "P6") != 0) {
        printf("Incorrect image type!\n");
        return;
    }
    int width, height;
    fscanf(img, "%d %d\n", &width, &height);
    int max_color;
    fscanf(img, "%d\n", &max_color);
    pixel *array = (pixel*)malloc(width * height * sizeof(pixel));
    fread(array, sizeof(pixel), width * height, img);
    fclose(img);
    int size = width * height * 3;
    int index = 0;
    char c = 0;
    for(int i = 0; i < size; i++) {
        if(i % 8 == 0 && i != 0) {
            if(c == '\0') break;
            output[index] = c;
            c = 0;
            index++;
        }
        if((array[size - i - 1].b & 1) == 1) {
            c |= 1UL << (i % 8);
        }
    }
    output[index] = '\0';
}

int main() {
    printf("Welcome to Steganography!\n");
    printf("Please choose an option:\n");
    printf("1 - Hide text inside an image\n");
    printf("2 - Extract text from an image\n");
    int option;
    scanf("%d", &option);
    if(option == 1) {
        printf("Enter the name of the image file:\n");
        char filename[50];
        scanf("%s", filename);
        int width, height;
        pixel *array = (pixel*)malloc(MAX_FILE_SIZE);
        if(readImg(filename, array, &width, &height) < 0) return -1;
        printf("Enter the text to be hidden:\n");
        char text[MAX_FILE_SIZE];
        scanf(" %[^\n]s", text);
        hideText(text, array, width * height * 3);
        printf("Enter the name of the output file:\n");
        char output[50];
        scanf("%s", output);
        if(writeImg(output, array, width, height) < 0) return -1;
        printf("Text hidden successfully!\n");
    } else if(option == 2) {
        printf("Enter the name of the image file:\n");
        char filename[50];
        scanf("%s", filename);
        char output[MAX_FILE_SIZE];
        extractTextFILE(filename, output);
        printf("Extracted text: %s\n", output);
    } else {
        printf("Invalid option!\n");
    }
    return 0;
}