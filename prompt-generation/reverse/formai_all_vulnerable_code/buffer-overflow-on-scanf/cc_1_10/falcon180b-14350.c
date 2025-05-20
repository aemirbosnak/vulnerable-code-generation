//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 1000
#define MAX_CLASSES 100
#define IMAGE_WIDTH 32
#define IMAGE_HEIGHT 32

struct image {
    int width;
    int height;
    char *data;
};

struct class {
    char *name;
    int count;
};

int main() {
    struct image *images = malloc(MAX_IMAGES * sizeof(struct image));
    struct class *classes = malloc(MAX_CLASSES * sizeof(struct class));
    int num_images = 0;
    int num_classes = 0;

    while (num_images < MAX_IMAGES && num_classes < MAX_CLASSES) {
        char filename[64];
        sprintf(filename, "image_%d.bin", num_images);
        FILE *fp = fopen(filename, "rb");

        if (fp == NULL) {
            break;
        }

        struct image image;
        image.width = IMAGE_WIDTH;
        image.height = IMAGE_HEIGHT;
        image.data = malloc(image.width * image.height);

        int size = fread(image.data, 1, image.width * image.height, fp);
        fclose(fp);

        if (size!= image.width * image.height) {
            printf("Error reading image file.\n");
            exit(1);
        }

        images[num_images] = image;
        num_images++;
    }

    while (num_classes < MAX_CLASSES) {
        char name[64];
        printf("Enter the name of a class: ");
        scanf("%s", name);

        struct class *class = malloc(sizeof(struct class));
        class->name = strdup(name);
        class->count = 0;

        for (int i = 0; i < num_images; i++) {
            for (int j = 0; j < images[i].width * images[i].height; j++) {
                if (images[i].data[j] == 1) {
                    class->count++;
                }
            }
        }

        classes[num_classes] = *class;
        num_classes++;
    }

    for (int i = 0; i < num_classes; i++) {
        printf("%s: %d\n", classes[i].name, classes[i].count);
    }

    return 0;
}