//FormAI DATASET v1.0 Category: Image Classification system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LABELS 10
#define MAX_STR_LEN 100

typedef struct image {
    int pixels[10][10];
    char label[MAX_LABELS][MAX_STR_LEN];
} Image;

Image getNextImage() {
    Image img;
    printf("Enter image pixels (comma separated): ");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d,", &(img.pixels[i][j]));
        }
    }
    printf("Enter labels for the image (comma separated): ");
    char* labels = malloc(MAX_LABELS * MAX_STR_LEN * sizeof(char));
    scanf("%s", labels);
    char* token = strtok(labels, ",");
    int i = 0;
    while (token != NULL && i < MAX_LABELS) {
        strcpy(img.label[i++], token);
        token = strtok(NULL, ",");
    }
    free(labels);
    return img;
}

int classifyImage(Image img) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (img.pixels[i][j] > 128) {
                sum += 1;
            }
        }
    }
    return sum >= 50 ? 1 : 0;
}

int main() {
    printf("Welcome to the Image Classification System!\n");
    printf("Please enter at least two images to start classifying.\n");

    Image imgs[2];
    imgs[0] = getNextImage();
    imgs[1] = getNextImage();

    printf("Classifying first image...\n");
    int class1 = classifyImage(imgs[0]);
    printf("Classifying second image...\n");
    int class2 = classifyImage(imgs[1]);

    if (class1 == class2) {
        printf("Both images are classified as %d\n", class1);
        printf("Haha, looks like we need more training data!\n");
    } else {
        printf("The first image is classified as %d\n", class1);
        printf("The second image is classified as %d\n", class2);
        printf("Great success! Our image classification system is working!\n");
    }
    return 0;
}