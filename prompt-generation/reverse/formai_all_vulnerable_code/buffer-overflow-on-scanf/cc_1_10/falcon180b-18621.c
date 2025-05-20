//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to classify images recursively
void classifyImage(char* imageName, int level) {
    FILE* fp;
    char ch;
    int i = 0;

    // Open the image file
    fp = fopen(imageName, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    // Read the first character of the image file
    ch = fgetc(fp);

    // Check if the character is a digit
    if (isdigit(ch)) {
        // If it is a digit, increment the counter
        i++;
    }

    // Close the file
    fclose(fp);

    // If the level is 0, print the classification
    if (level == 0) {
        if (i == 0) {
            printf("%s is a non-image file.\n", imageName);
        } else {
            printf("%s is an image file.\n", imageName);
        }
    } else {
        // Otherwise, recursively classify the image
        classifyImage(imageName, level - 1);
    }
}

int main() {
    char imageName[100];

    // Get the name of the image file from the user
    printf("Enter the name of the image file: ");
    scanf("%s", imageName);

    // Classify the image recursively
    classifyImage(imageName, 3);

    return 0;
}