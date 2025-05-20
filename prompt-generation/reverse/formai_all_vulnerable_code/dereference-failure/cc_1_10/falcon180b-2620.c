//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGES 1000
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_LABELS 1000

typedef struct {
    char *filename;
    int width;
    int height;
    int label;
} IMAGE;

IMAGE images[MAX_IMAGES];
int num_images = 0;

void load_images() {
    FILE *fp = fopen("images.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *filename = strtok(line, " ");
        int width = atoi(strtok(NULL, " "));
        int height = atoi(strtok(NULL, " "));
        int label = atoi(strtok(NULL, " "));
        if (num_images >= MAX_IMAGES) {
            printf("Error: Maximum number of images reached.\n");
            exit(1);
        }
        images[num_images++] = (IMAGE) {
           .filename = filename,
           .width = width,
           .height = height,
           .label = label
        };
    }
    fclose(fp);
}

void classify_image(IMAGE *image) {
    int i;
    double distances[MAX_IMAGES];
    for (i = 0; i < num_images; i++) {
        if (i == image - images)
            continue;
        double width_diff = fabs(images[i].width - image->width);
        double height_diff = fabs(images[i].height - image->height);
        double distance = sqrt(width_diff * width_diff + height_diff * height_diff);
        distances[i] = distance;
    }
    int min_index = 0;
    for (i = 1; i < num_images; i++) {
        if (distances[i] < distances[min_index])
            min_index = i;
    }
    image->label = images[min_index].label;
}

int main() {
    load_images();
    char filename[256];
    printf("Enter filename: ");
    scanf("%s", filename);
    int i;
    for (i = 0; i < num_images; i++) {
        if (strcmp(filename, images[i].filename) == 0) {
            classify_image(&images[i]);
            printf("Classified as %d\n", images[i].label);
            return 0;
        }
    }
    printf("Image not found.\n");
    return 1;
}