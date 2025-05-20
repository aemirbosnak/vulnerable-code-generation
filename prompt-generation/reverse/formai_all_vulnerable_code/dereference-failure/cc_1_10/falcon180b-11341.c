//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 1000
#define MAX_CLASSES 10

typedef struct {
    int id;
    char name[50];
} Image;

typedef struct {
    int id;
    char name[50];
    int num_images;
    Image *images;
} Class;

int main() {
    int num_images, num_classes;
    Image *images = NULL;
    Class *classes = NULL;

    printf("Welcome to the Happy Image Classification System!\n");
    printf("Please enter the number of images you would like to classify: ");
    scanf("%d", &num_images);

    images = (Image *)malloc(num_images * sizeof(Image));
    if (!images) {
        printf("Error: could not allocate memory for images.\n");
        exit(1);
    }

    printf("Please enter the number of classes you would like to use: ");
    scanf("%d", &num_classes);

    classes = (Class *)malloc(num_classes * sizeof(Class));
    if (!classes) {
        printf("Error: could not allocate memory for classes.\n");
        exit(1);
    }

    printf("Please enter the ID and name for each class (press enter after each):\n");
    for (int i = 0; i < num_classes; i++) {
        scanf("%d", &classes[i].id);
        scanf("%s", classes[i].name);
    }

    printf("Please enter the ID and name for each image (press enter after each):\n");
    for (int i = 0; i < num_images; i++) {
        scanf("%d", &images[i].id);
        scanf("%s", images[i].name);
    }

    printf("Please enter the number of images for each class (press enter after each):\n");
    for (int i = 0; i < num_classes; i++) {
        scanf("%d", &classes[i].num_images);
        classes[i].images = (Image *)malloc(classes[i].num_images * sizeof(Image));
        if (!classes[i].images) {
            printf("Error: could not allocate memory for images in class %s.\n", classes[i].name);
            exit(1);
        }
        printf("Please enter the ID and name for each image in class %s (press enter after each):\n", classes[i].name);
        for (int j = 0; j < classes[i].num_images; j++) {
            scanf("%d", &classes[i].images[j].id);
            scanf("%s", classes[i].images[j].name);
        }
    }

    printf("Classification complete! Thank you for using the Happy Image Classification System!\n");

    return 0;
}