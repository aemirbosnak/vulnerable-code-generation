//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_IMAGE_SIZE 1000

struct Class {
    char name[50];
    int count;
};

void read_classes(FILE *fp, struct Class classes[]) {
    int i = 0;
    while (fscanf(fp, "%s %d\n", classes[i].name, &classes[i].count)!= EOF) {
        i++;
    }
}

void read_image(FILE *fp, int *image, int size) {
    int i;
    for (i = 0; i < size; i++) {
        fscanf(fp, "%d", &image[i]);
    }
}

int classify_image(int *image, int size, struct Class classes[]) {
    int i, j, best_score = 0;
    for (i = 0; i < MAX_CLASSES; i++) {
        if (classes[i].count == 0) {
            break;
        }
        int score = 0;
        for (j = 0; j < size; j++) {
            score += image[j] == classes[i].name[j % strlen(classes[i].name)]? 1 : 0;
        }
        if (score > best_score) {
            best_score = score;
        }
    }
    return best_score;
}

int main() {
    FILE *fp;
    fp = fopen("classes.txt", "r");
    if (fp == NULL) {
        printf("Error opening classes file.\n");
        exit(1);
    }
    struct Class classes[MAX_CLASSES];
    read_classes(fp, classes);
    fclose(fp);

    fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }
    int image[MAX_IMAGE_SIZE];
    int size;
    fscanf(fp, "%d", &size);
    read_image(fp, image, size);
    fclose(fp);

    int best_score = classify_image(image, size, classes);
    printf("Best score: %d\n", best_score);

    return 0;
}