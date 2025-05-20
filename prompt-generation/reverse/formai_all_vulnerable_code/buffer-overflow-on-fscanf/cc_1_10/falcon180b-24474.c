//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CLASSES 10
#define MAX_IMAGES 100

typedef struct {
    char name[20];
    int num_classes;
    int classes[MAX_CLASSES];
} dataset;

typedef struct {
    int id;
    dataset *ds;
} image;

dataset *load_dataset(char *filename) {
    FILE *fp = fopen(filename, "r");
    dataset *ds = (dataset*)malloc(sizeof(dataset));
    if (fp == NULL) {
        printf("Error: %s not found\n", filename);
        exit(1);
    }
    fscanf(fp, "%s %d", ds->name, &ds->num_classes);
    for (int i = 0; i < ds->num_classes; i++) {
        fscanf(fp, "%d", &ds->classes[i]);
    }
    fclose(fp);
    return ds;
}

image *load_image(char *filename, dataset *ds) {
    FILE *fp = fopen(filename, "r");
    image *im = (image*)malloc(sizeof(image));
    if (fp == NULL) {
        printf("Error: %s not found\n", filename);
        exit(1);
    }
    fscanf(fp, "%d", &im->id);
    fclose(fp);
    return im;
}

void classify_image(image *im, dataset *ds) {
    int max_score = 0;
    int max_class = 0;
    for (int i = 0; i < ds->num_classes; i++) {
        int score = 0;
        for (int j = 0; j < im->ds->num_classes; j++) {
            if (im->ds->classes[j] == ds->classes[i]) {
                score++;
            }
        }
        if (score > max_score) {
            max_score = score;
            max_class = i;
        }
    }
    printf("Image %d classified as %s with score %d\n", im->id, ds->classes[max_class], max_score);
}

int main() {
    dataset *ds1 = load_dataset("dataset1.txt");
    dataset *ds2 = load_dataset("dataset2.txt");
    image *im1 = load_image("image1.txt", ds1);
    image *im2 = load_image("image2.txt", ds2);
    classify_image(im1, ds1);
    classify_image(im2, ds2);
    return 0;
}