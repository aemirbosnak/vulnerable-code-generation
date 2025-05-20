//FormAI DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_COMMAND_LENGTH 10
#define MAGIC_NUMBER 0xba5eba11

typedef struct {
    unsigned int magic_number;
    unsigned int height;
    unsigned int width;
    unsigned char* pixels;
} image;

/* Function to load image from file */
image* load_image(char* filename) {
    image* img = malloc(sizeof(image));
    if (!img) {
        perror("Error allocating memory for image\n");
        exit(EXIT_FAILURE);
    }
    FILE* fp = fopen(filename, "rb");

    if (!fp) {
        perror("Error loading image from file\n");
        exit(EXIT_FAILURE);
    }

    char* buffer = malloc(MAX_FILENAME_LENGTH);
    if (!buffer) {
        perror("Error allocating memory for buffer\n");
        exit(EXIT_FAILURE);
    }
    fread(buffer, MAX_FILENAME_LENGTH, 1, fp);

    /* Check if this is a valid image file */
    if (strcmp(buffer, "image") != 0) {
        perror("Invalid file format\n");
        exit(EXIT_FAILURE);
    }

    img->magic_number = MAGIC_NUMBER;

    fread(&(img->height), sizeof(img->height), 1, fp);
    fread(&(img->width), sizeof(img->width), 1, fp);

    img->pixels = malloc(img->height * img->width * sizeof(unsigned char));
    if (!img->pixels) {
        perror("Error allocating memory for image pixels\n");
        exit(EXIT_FAILURE);
    }

    fread(img->pixels, img->height, img->width, fp);
    fclose(fp);
    free(buffer);
    return img;
}

/* Function to save image to file */
void save_image(image* img, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error saving image to file\n");
        exit(EXIT_FAILURE);
    }
    /* Check if this is a valid image */
    if (img->magic_number != MAGIC_NUMBER) {
        perror("Invalid image\n");
        exit(EXIT_FAILURE);
    }

    fwrite("image", strlen("image"), 1, fp);    
    fwrite(&(img->height), sizeof(img->height), 1, fp);
    fwrite(&(img->width), sizeof(img->width), 1, fp);

    fwrite(img->pixels, img->height, img->width, fp);
    fclose(fp);
}

/* Function to flip image horizontally */
void flip_horizontal(image* img) {
    unsigned char* temp_row = malloc(img->width * sizeof(unsigned char));
    if (!temp_row) {
        perror("Error allocating memory for temp row\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < img->height; i++) {
        for (unsigned int j = 0; j < img->width / 2; j++) {
            temp_row[j] = img->pixels[i*img->width + j];
            img->pixels[i*img->width + j] = img->pixels[i*img->width + (img->width - j - 1)];
            img->pixels[i*img->width + (img->width - j - 1)] = temp_row[j];
        }
    }

    free(temp_row);
}

/* Function to flip image vertically */
void flip_vertical(image* img) {
    unsigned char* temp_column = malloc(img->height * sizeof(unsigned char));
    if (!temp_column) {
        perror("Error allocating memory for temp column\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < img->width; i++) {
        for (unsigned int j = 0; j < img->height / 2; j++) {
            temp_column[j] = img->pixels[j*img->width + i];
            img->pixels[j*img->width + i] = img->pixels[(img->height - j - 1)*img->width + i];
            img->pixels[(img->height - j - 1)*img->width + i] = temp_column[j];
        }
    }

    free(temp_column);
}

int main() {
    image* img;
    char filename[MAX_FILENAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];

    printf("Enter name of image file to load: ");
    scanf("%s", filename);
    img = load_image(filename);

    printf("Enter command (h for horizontal flip, v for vertical flip): ");
    scanf("%s", command);

    switch (command[0]) {
    case 'h':
        flip_horizontal(img);
        break;
    case 'v':
        flip_vertical(img);
        break;
    default:
        perror("Invalid command\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter name of image file to save: ");
    scanf("%s", filename);
    save_image(img, filename);

    free(img->pixels);
    free(img);
    
    return 0;
}