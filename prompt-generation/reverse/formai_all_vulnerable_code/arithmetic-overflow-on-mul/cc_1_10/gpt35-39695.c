//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert the image to ASCII art
char *image_to_ascii(char *image_path, int width, int height) {
    // Open the image file
    FILE *fp = fopen(image_path, "rb");
    if (fp == NULL) {
        printf("Failed to open the image file.\n");
        exit(1);
    }

    // Read the RGB values from the image file
    unsigned char pixel[3];
    size_t count = 0;
    char *ascii = (char *)malloc((width * height * 3 + height) * sizeof(char));
    char *temp = ascii;
    while (fread(pixel, sizeof(unsigned char), 3, fp) == 3) {
        unsigned char gray = (pixel[0] + pixel[1] + pixel[2]) / 3;
        *temp++ = " .:-=+*#%@ "[gray * 10 / 255];
        if (++count % width == 0) *temp++ = '\n';
    }
    *temp = '\0';

    // Close the image file and return the ASCII art
    fclose(fp);
    return ascii;
}

int main() {
    // Get the image path from the user
    char image_path[1024];
    printf("Enter the path to the image: ");
    fgets(image_path, 1024, stdin);
    image_path[strcspn(image_path, "\n")] = '\0';

    // Get the dimensions of the image from the user
    int width, height;
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    // Convert the image to ASCII art
    char *ascii = image_to_ascii(image_path, width, height);

    // Print the ASCII art
    printf("%s", ascii);

    // Free the memory allocated for the ASCII art
    free(ascii);

    return 0;
}