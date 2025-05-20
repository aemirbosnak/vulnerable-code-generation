//FormAI DATASET v1.0 Category: Image Classification system ; Style: mind-bending
#include <stdio.h>

void welcome_message() {
    printf("Welcome to the C Image Classification system!\n");
    printf("Please input the filename of the image you would like to classify:\n");
}

void classify_image(char *filename) {
    printf("Classifying image %s...\n", filename);
    printf("Analyzing pixel data...\n");
    printf("Identifying shapes and objects...\n");
    printf("Cross-referencing with our image database...\n");
    printf("Determining classification...\n");
    printf("The image %s has been classified as a ", filename);
    // Here is where we will randomly generate a classification for the image
    int rand_num = rand() % 3;
    switch(rand_num) {
        case 0:
            printf("cat!\n");
            break;
        case 1:
            printf("house!\n");
            break;
        case 2:
            printf("tree!\n");
            break;
        default:
            printf("unknown object...\n");
    }
}

int main() {
    printf("Initializing C Image Classification system...\n");
    printf("Loading image database...\n");
    printf("Checking system resources...\n");
    printf("All systems ready!\n");

    while(1) {
        welcome_message();
        char filename[100];
        scanf("%s", filename);
        classify_image(filename);

        printf("Would you like to classify another image? (y/n)\n");
        char response;
        scanf("%c", &response);
        if(response != 'y') {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}