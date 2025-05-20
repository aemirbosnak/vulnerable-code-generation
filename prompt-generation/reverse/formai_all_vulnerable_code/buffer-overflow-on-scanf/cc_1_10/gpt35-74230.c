//FormAI DATASET v1.0 Category: Image Editor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the dimensions of the image
#define WIDTH 100
#define HEIGHT 100

// Define the maximum length of a command
#define MAX_COMMAND_LENGTH 20

// Define the maximum length of a filename
#define MAX_FILENAME_LENGTH 50

// Define the maximum size of the image data array
#define MAX_IMAGE_SIZE (WIDTH * HEIGHT)

// Define the image data array
unsigned char image_data[MAX_IMAGE_SIZE];

// Define the image filename
char filename[MAX_FILENAME_LENGTH];

// Print the help menu
void print_help() {
    printf("Commands:\n");
    printf("  load <filename>   Load image from file\n");
    printf("  save <filename>   Save image to file\n");
    printf("  invert            Invert colors of image\n");
    printf("  grayscale         Convert image to grayscale\n");
    printf("  blur              Blur image\n");
    printf("  quit              Quit the program\n");
}

// Load image data from file
void load_image_data() {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for reading.\n", filename);
        return;
    }
    fread(image_data, MAX_IMAGE_SIZE, 1, file);
    fclose(file);
}

// Save image data to file
void save_image_data() {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for writing.\n", filename);
        return;
    }
    fwrite(image_data, MAX_IMAGE_SIZE, 1, file);
    fclose(file);
}

// Invert colors of image data
void invert_image_data() {
    int i;
    for (i = 0; i < MAX_IMAGE_SIZE; i++) {
        image_data[i] = 255 - image_data[i];
    }
}

// Convert image data to grayscale
void grayscale_image_data() {
    int i;
    for (i = 0; i < MAX_IMAGE_SIZE; i++) {
        unsigned char r = image_data[i * 3];
        unsigned char g = image_data[i * 3 + 1];
        unsigned char b = image_data[i * 3 + 2];
        unsigned char gray = (r + g + b) / 3;
        image_data[i * 3] = gray;
        image_data[i * 3 + 1] = gray;
        image_data[i * 3 + 2] = gray;
    }
}

// Blur image data
void blur_image_data() {
    int i, j;
    unsigned char* temp_data = malloc(MAX_IMAGE_SIZE);
    memcpy(temp_data, image_data, MAX_IMAGE_SIZE);
    for (i = 1; i < HEIGHT - 1; i++) {
        for (j = 1; j < WIDTH - 1; j++) {
            int index = (i * WIDTH + j) * 3;
            unsigned char r = (
                temp_data[(i - 1) * WIDTH * 3 + (j - 1) * 3] +
                temp_data[(i - 1) * WIDTH * 3 + j * 3] +
                temp_data[(i - 1) * WIDTH * 3 + (j + 1) * 3] +
                temp_data[i * WIDTH * 3 + (j - 1) * 3] +
                temp_data[i * WIDTH * 3 + j * 3] +
                temp_data[i * WIDTH * 3 + (j + 1) * 3] +
                temp_data[(i + 1) * WIDTH * 3 + (j - 1) * 3] +
                temp_data[(i + 1) * WIDTH * 3 + j * 3] +
                temp_data[(i + 1) * WIDTH * 3 + (j + 1) * 3]
            ) / 9;
            unsigned char g = (
                temp_data[(i - 1) * WIDTH * 3 + (j - 1) * 3 + 1] +
                temp_data[(i - 1) * WIDTH * 3 + j * 3 + 1] +
                temp_data[(i - 1) * WIDTH * 3 + (j + 1) * 3 + 1] +
                temp_data[i * WIDTH * 3 + (j - 1) * 3 + 1] +
                temp_data[i * WIDTH * 3 + j * 3 + 1] +
                temp_data[i * WIDTH * 3 + (j + 1) * 3 + 1] +
                temp_data[(i + 1) * WIDTH * 3 + (j - 1) * 3 + 1] +
                temp_data[(i + 1) * WIDTH * 3 + j * 3 + 1] +
                temp_data[(i + 1) * WIDTH * 3 + (j + 1) * 3 + 1]
            ) / 9;
            unsigned char b = (
                temp_data[(i - 1) * WIDTH * 3 + (j - 1) * 3 + 2] +
                temp_data[(i - 1) * WIDTH * 3 + j * 3 + 2] +
                temp_data[(i - 1) * WIDTH * 3 + (j + 1) * 3 + 2] +
                temp_data[i * WIDTH * 3 + (j - 1) * 3 + 2] +
                temp_data[i * WIDTH * 3 + j * 3 + 2] +
                temp_data[i * WIDTH * 3 + (j + 1) * 3 + 2] +
                temp_data[(i + 1) * WIDTH * 3 + (j - 1) * 3 + 2] +
                temp_data[(i + 1) * WIDTH * 3 + j * 3 + 2] +
                temp_data[(i + 1) * WIDTH * 3 + (j + 1) * 3 + 2]
            ) / 9;
            image_data[index] = r;
            image_data[index + 1] = g;
            image_data[index + 2] = b;
        }
    }
    free(temp_data);
}

int main() {
    printf("Image Editor\n");
    printf("-------------\n");
    print_help();
    while (true) {
        printf("> ");
        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);
        if (strcmp(command, "load") == 0) {
            scanf("%s", filename);
            load_image_data();
        }
        else if (strcmp(command, "save") == 0) {
            scanf("%s", filename);
            save_image_data();
        }
        else if (strcmp(command, "invert") == 0) {
            invert_image_data();
        }
        else if (strcmp(command, "grayscale") == 0) {
            grayscale_image_data();
        }
        else if (strcmp(command, "blur") == 0) {
            blur_image_data();
        }
        else if (strcmp(command, "quit") == 0) {
            break;
        }
        else {
            printf("Error: Unknown command '%s'.\n", command);
            print_help();
        }
    }
    return 0;
}