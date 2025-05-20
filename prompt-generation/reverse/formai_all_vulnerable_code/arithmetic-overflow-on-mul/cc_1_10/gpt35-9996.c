//FormAI DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_COMMAND_LEN 50

struct image {
    int width;
    int height;
    int* pixels;
};

void read_image_file(const char* filename, struct image* img) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    // Read the width and height from the image file
    fread(&(img->width), sizeof(int), 1, fp);
    fread(&(img->height), sizeof(int), 1, fp);
    // Allocate memory for the pixels
    img->pixels = (int*) malloc(img->width * img->height * sizeof(int));
    if (!img->pixels) {
        fprintf(stderr, "Error: Failed to allocate memory for image pixels\n");
        exit(1);
    }
    // Read the pixels from the image file
    fread(img->pixels, sizeof(int), img->width * img->height, fp);
    // Close the file
    fclose(fp);
}

void save_image_file(const char* filename, struct image* img) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    // Write the width and height to the image file
    fwrite(&(img->width), sizeof(int), 1, fp);
    fwrite(&(img->height), sizeof(int), 1, fp);
    // Write the pixels to the image file
    fwrite(img->pixels, sizeof(int), img->width * img->height, fp);
    // Close the file
    fclose(fp);
}

void grayscale(struct image* img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            int index = i * img->width + j;
            int red = (img->pixels[index] >> 16) & 0xFF;
            int green = (img->pixels[index] >> 8) & 0xFF;
            int blue = img->pixels[index] & 0xFF;
            int gray = (red + green + blue) / 3;
            img->pixels[index] = (gray << 16) | (gray << 8) | gray;
        }
    }
}

void mirror(struct image* img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width / 2; j++) {
            int index1 = i * img->width + j;
            int index2 = i * img->width + (img->width - j - 1);
            int temp = img->pixels[index1];
            img->pixels[index1] = img->pixels[index2];
            img->pixels[index2] = temp;
        }
    }
}

void process_command(const char* command, struct image* img) {
    if (strcmp(command, "grayscale") == 0) {
        grayscale(img);
    } else if (strcmp(command, "mirror") == 0) {
        mirror(img);
    } else {
        fprintf(stderr, "Error: Unknown command '%s'\n", command);
        exit(1);
    }
}

int main() {
    // Read the image filename from standard input
    char filename[MAX_FILENAME_LEN];
    printf("Enter the image filename: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    // Remove the newline character from the end of the filename string
    filename[strcspn(filename, "\n")] = '\0';
    // Read the image file into memory
    struct image img;
    read_image_file(filename, &img);
    // Process commands until the user types "quit"
    char command[MAX_COMMAND_LEN];
    while (1) {
        printf("Enter a command (grayscale, mirror, or quit): ");
        fgets(command, MAX_COMMAND_LEN, stdin);
        // Remove the newline character from the end of the command string
        command[strcspn(command, "\n")] = '\0';
        if (strcmp(command, "quit") == 0) {
            break;
        } else {
            process_command(command, &img);
        }
    }
    // Save the modified image to a new file
    char output_filename[MAX_FILENAME_LEN];
    printf("Enter the output filename: ");
    fgets(output_filename, MAX_FILENAME_LEN, stdin);
    // Remove the newline character from the end of the output filename string
    output_filename[strcspn(output_filename, "\n")] = '\0';
    save_image_file(output_filename, &img);
    // Free the memory used by the image pixels
    free(img.pixels);
    return 0;
}