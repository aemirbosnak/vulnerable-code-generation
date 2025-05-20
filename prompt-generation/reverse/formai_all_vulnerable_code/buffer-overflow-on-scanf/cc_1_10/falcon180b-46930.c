//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 1000
#define MAX_CLASSES 100
#define MAX_FEATURES 1000

struct image {
    char name[100];
    int label;
    int *features;
    int num_features;
};

struct class {
    char name[100];
    int num_images;
    struct image *images;
};

void read_images(struct image *images, int num_images) {
    for (int i = 0; i < num_images; i++) {
        printf("Enter image name: ");
        scanf("%s", images[i].name);
        printf("Enter image label: ");
        scanf("%d", &images[i].label);
        printf("Enter number of features: ");
        scanf("%d", &images[i].num_features);
        images[i].features = (int *)malloc(images[i].num_features * sizeof(int));
        for (int j = 0; j < images[i].num_features; j++) {
            printf("Enter feature %d: ", j+1);
            scanf("%d", &images[i].features[j]);
        }
    }
}

void read_classes(struct class *classes, int num_classes) {
    for (int i = 0; i < num_classes; i++) {
        printf("Enter class name: ");
        scanf("%s", classes[i].name);
        printf("Enter number of images: ");
        scanf("%d", &classes[i].num_images);
        classes[i].images = (struct image *)malloc(classes[i].num_images * sizeof(struct image));
    }
}

void classify_image(struct class *classes, int num_classes, struct image *image) {
    int best_score = -1;
    int best_class = -1;
    for (int i = 0; i < num_classes; i++) {
        int score = 0;
        for (int j = 0; j < image->num_features; j++) {
            int feature_index = -1;
            for (int k = 0; k < classes[i].images[0].num_features; k++) {
                if (classes[i].images[0].features[k] == image->features[j]) {
                    feature_index = k;
                    break;
                }
            }
            if (feature_index == -1) {
                continue;
            }
            score += classes[i].images[0].features[feature_index];
        }
        if (score > best_score) {
            best_score = score;
            best_class = i;
        }
    }
    printf("Classified as %s with score %d\n", classes[best_class].name, best_score);
}

int main() {
    int num_images, num_classes;
    printf("Enter number of images: ");
    scanf("%d", &num_images);
    printf("Enter number of classes: ");
    scanf("%d", &num_classes);

    struct image images[MAX_IMAGES];
    read_images(images, num_images);

    struct class classes[MAX_CLASSES];
    read_classes(classes, num_classes);

    printf("Enter image to classify: ");
    scanf("%s", images[0].name);
    classify_image(classes, num_classes, &images[0]);

    return 0;
}