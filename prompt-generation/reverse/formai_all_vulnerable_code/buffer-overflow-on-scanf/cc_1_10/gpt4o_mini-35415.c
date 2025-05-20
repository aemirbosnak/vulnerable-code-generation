//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to load an image from a PPM file
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("OH NO! Could not open file %s for reading!\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P6") != 0) {
        printf("Surprise! Format not recognized. Only P6 is supported!\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    fgetc(file); // Consume the newline character
    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);

    printf("Image loaded! What a delightful surprise!\n");
    return img;
}

// Function to save an image to a PPM file
void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Oops! Could not open file %s for writing!\n", filename);
        return;
    }
    
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    printf("Image saved! What a surprise success!\n");
}

// Function to apply grayscale effect
void apply_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
    printf("Grayscale effect applied! Amazing, isn't it?\n");
}

// Function to apply a simple invert effect
void apply_invert(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
    printf("Invert effect applied! What a twist!\n");
}

// Function to free the image data
void free_image(Image *img) {
    free(img->data);
    free(img);
    printf("Memory freed! Until next time!\n");
}

int main() {
    char command[256];
    Image *img = NULL;

    while (1) {
        printf("Enter a command (load/save/grayscale/invert/exit): ");
        scanf("%s", command);

        if (strcmp(command, "load") == 0) {
            char filename[256];
            printf("Enter filename to load: ");
            scanf("%s", filename);
            img = load_image(filename);
        } else if (strcmp(command, "save") == 0) {
            if (img == NULL) {
                printf("Surprise! No image loaded yet!\n");
                continue;
            }
            char filename[256];
            printf("Enter filename to save: ");
            scanf("%s", filename);
            save_image(filename, img);
        } else if (strcmp(command, "grayscale") == 0) {
            if (img == NULL) {
                printf("Yikes! No image loaded to process!\n");
                continue;
            }
            apply_grayscale(img);
        } else if (strcmp(command, "invert") == 0) {
            if (img == NULL) {
                printf("Alert! An image is needed to invert!\n");
                continue;
            }
            apply_invert(img);
        } else if (strcmp(command, "exit") == 0) {
            if (img != NULL) {
                free_image(img);
            }
            printf("Exiting the program! What a journey we had!\n");
            break;
        } else {
            printf("Hmm, that command is surprising! Try again.\n");
        }
    }

    return 0;
}