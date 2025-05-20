//FormAI DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to swap two characters in a string
void swapChars(char* str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

// function to randomly shuffle the characters in a string
void shuffleChars(char* str) {
    srand(time(NULL));
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        int j = rand() % (len - i) + i;
        swapChars(str, i, j);
    }
}

int main() {
    char imageName[100];
    printf("Enter name of image file: ");
    scanf("%s", imageName);

    printf("Processing image %s...\n", imageName);

    // open image file
    FILE* fp = fopen(imageName, "rb");
    if (!fp) {
        printf("Error: could not open file %s\n", imageName);
        return 1;
    }

    // read image data
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* imageData = malloc(size);
    fread(imageData, size, 1, fp);
    fclose(fp);

    printf("Image size: %ld bytes\n", size);

    // randomly shuffle the image data
    shuffleChars(imageData);

    // save the new image as a new file
    char newImageName[100];
    printf("Enter new name for shuffled image: ");
    scanf("%s", newImageName);
    FILE* newFp = fopen(newImageName, "wb");
    fwrite(imageData, size, 1, newFp);
    fclose(newFp);

    printf("Shuffled image saved as %s\n", newImageName);

    free(imageData);

    return 0;
}