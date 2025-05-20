//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Ada Lovelace
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

Image* create_image(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel *)malloc(sizeof(Pixel) * width * height);
    
    for (int i = 0; i < width * height; i++) {
        img->data[i] = (Pixel){0, 0, 0};  // Initialize with black pixels
    }
    return img;
}

void destroy_image(Image *img) {
    free(img->data);
    free(img);
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void fill_image(Image *img, unsigned char r, unsigned char g, unsigned char b) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] = (Pixel){r, g, b};
    }
}

void print_usage() {
    printf("Simple Image Editor\n");
    printf("Usage: image_editor <command> <filename>\n");
    printf("Commands:\n");
    printf("  create <width> <height>    Create a new image\n");
    printf("  save <filename>             Save the image to a file\n");
    printf("  invert                      Invert the image colors\n");
    printf("  fill <r> <g> <b>           Fill the image with a color\n");
    printf("  exit                        Exit the program\n");
}

int main(int argc, char *argv[]) {
    Image *image = NULL;
    char command[50];

    print_usage();
    
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            int width, height;
            scanf("%d %d", &width, &height);
            image = create_image(width, height);
            printf("Image created with dimensions %d x %d.\n", width, height);
        } else if (strcmp(command, "save") == 0) {
            char filename[100];
            scanf("%s", filename);
            if (image) {
                save_image(filename, image);
                printf("Image saved to %s.\n", filename);
            } else {
                printf("No image to save.\n");
            }
        } else if (strcmp(command, "invert") == 0) {
            if (image) {
                invert_colors(image);
                printf("Image colors inverted.\n");
            } else {
                printf("No image to invert.\n");
            }
        } else if (strcmp(command, "fill") == 0) {
            unsigned char r, g, b;
            scanf("%hhu %hhu %hhu", &r, &g, &b);
            if (image) {
                fill_image(image, r, g, b);
                printf("Image filled with color (%hhu, %hhu, %hhu).\n", r, g, b);
            } else {
                printf("No image to fill.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    destroy_image(image);
    return 0;
}