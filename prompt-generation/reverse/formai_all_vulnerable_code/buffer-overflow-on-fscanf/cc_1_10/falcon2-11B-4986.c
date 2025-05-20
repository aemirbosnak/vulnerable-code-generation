//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000

struct Image {
    char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int width;
    int height;
};

struct Image load_image(const char* filename) {
    struct Image image;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fscanf(file, "%d %d", &image.width, &image.height);

    for (int y = 0; y < image.height; y++) {
        fscanf(file, "%s", image.pixels[y]);
    }

    fclose(file);

    return image;
}

void save_image(const char* filename, const struct Image* image) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(file, "%d %d\n", image->width, image->height);

    for (int y = 0; y < image->height; y++) {
        fprintf(file, "%s\n", image->pixels[y]);
    }

    fclose(file);
}

int main() {
    struct Image image;
    struct Image loaded_image = load_image("image.txt");
    printf("Loaded image with dimensions: %dx%d\n", loaded_image.width, loaded_image.height);

    int index = 0;
    for (int y = 0; y < loaded_image.height; y++) {
        for (int x = 0; x < loaded_image.width; x++) {
            if (loaded_image.pixels[y][x] == 'B') {
                loaded_image.pixels[y][x] = 'R';
            } else if (loaded_image.pixels[y][x] == 'G') {
                loaded_image.pixels[y][x] = 'Y';
            } else {
                loaded_image.pixels[y][x] = 'C';
            }
            printf("(%d, %d) => %c\n", x, y, loaded_image.pixels[y][x]);
        }
    }

    save_image("image_edited.txt", &loaded_image);

    return 0;
}