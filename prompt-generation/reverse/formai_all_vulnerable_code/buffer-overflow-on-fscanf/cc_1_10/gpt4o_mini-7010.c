//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 100
#define IMAGE_NAME_LENGTH 50
#define CLASS_NAME_LENGTH 20

typedef struct {
    char name[IMAGE_NAME_LENGTH];
    char class[CLASS_NAME_LENGTH];
    int pixel_sum;
} Image;

Image images[MAX_IMAGES];
int image_count = 0;

void load_images(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open image list");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s %d", images[image_count].name, images[image_count].class, &images[image_count].pixel_sum) != EOF) {
        image_count++;
        if (image_count >= MAX_IMAGES) {
            break;
        }
    }

    fclose(file);
}

void classify_images(int threshold) {
    printf("Classifying images with pixel sum threshold: %d\n", threshold);
    for (int i = 0; i < image_count; i++) {
        if (images[i].pixel_sum > threshold) {
            printf("Image %s classified as %s (Pixel Sum: %d)\n", images[i].name, images[i].class, images[i].pixel_sum);
        } else {
            printf("Image %s does not meet the threshold\n", images[i].name);
        }
    }
}

void print_image_summary() {
    printf("Total images loaded: %d\n", image_count);
    for (int i = 0; i < image_count; i++) {
        printf("Image: %s, Class: %s, Pixel Sum: %d\n",
               images[i].name, images[i].class, images[i].pixel_sum);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image_list.txt> <threshold>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_images(argv[1]);
    int threshold = atoi(argv[2]);

    print_image_summary();
    classify_images(threshold);

    return EXIT_SUCCESS;
}