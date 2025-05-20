//FormAI DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Image Puzzle!\n");
    printf("Please enter the number of images you want to classify: ");

    int numImages;
    scanf("%d", &numImages);

    if (numImages <= 0) {
        printf("Invalid number of images!\n");
        return 0;
    }

    printf("Great! Please enter the number of categories: ");

    int numCategories;
    scanf("%d", &numCategories);

    if (numCategories <= 0) {
        printf("Invalid number of categories!\n");
        return 0;
    }

    char** categories = (char**) malloc(numCategories * sizeof(char*));
    for (int i = 0; i < numCategories; i++) {
        categories[i] = (char*) malloc(100 * sizeof(char));
    }

    printf("Awesome! Please enter the names of the categories:\n");

    for (int i = 0; i < numCategories; i++) {
        scanf("%s", categories[i]);
    }

    printf("Let's start sorting the images...\n\n");

    for (int i = 0; i < numImages; i++) {
        printf("Please enter the name of image %d: ", i + 1);

        char* imageName = (char*) malloc(100 * sizeof(char));
        scanf("%s", imageName);

        printf("Now please enter the dimensions of image %d:\n", i + 1);

        int width, height;
        scanf("%d %d", &width, &height);

        if (width <= 0 || height <= 0) {
            printf("Invalid dimensions!\n");
            return 0;
        }

        printf("Great! Now let's classify image %d...\n", i + 1);

        int categoryIndex = 0;
        float maxScore = 0.0;

        for (int j = 0; j < numCategories; j++) {
            float score = (float) rand() / (float) RAND_MAX;

            if (score > maxScore) {
                maxScore = score;
                categoryIndex = j;
            }
        }

        printf("Image %d (%s) belongs to category \"%s\"\n\n", i + 1, imageName, categories[categoryIndex]);
    }

    printf("All images classified successfully!\n");

    for (int i = 0; i < numCategories; i++) {
        free(categories[i]);
    }
    free(categories);

    return 0;
}