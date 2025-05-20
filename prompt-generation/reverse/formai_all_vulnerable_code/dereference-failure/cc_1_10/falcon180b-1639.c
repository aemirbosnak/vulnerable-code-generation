//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define BLACK '0'
#define WHITE '1'

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image* load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    char *data = malloc(size);
    fread(data, size, 1, fp);
    fclose(fp);

    Image *image = malloc(sizeof(Image));
    image->width = atoi(strtok(filename, "."));
    image->height = atoi(strtok(NULL, "."));
    image->data = data;

    return image;
}

void save_ascii_art(const char *filename, char *data) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Could not create file '%s'.\n", filename);
        exit(1);
    }

    fwrite(data, strlen(data), 1, fp);
    fclose(fp);
}

void image_to_ascii_art(Image *image, char *ascii_art) {
    int width = image->width;
    int height = image->height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int pixel = *(image->data + y * width + x) / 16;
            ascii_art[y * MAX_WIDTH + x] = pixel? WHITE : BLACK;
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    char *ascii_art = malloc(image->width * image->height);

    image_to_ascii_art(image, ascii_art);

    char output_filename[strlen(argv[1]) + 5];
    sprintf(output_filename, "%s.txt", argv[1]);

    save_ascii_art(output_filename, ascii_art);

    printf("ASCII art saved to '%s'.\n", output_filename);

    return 0;
}