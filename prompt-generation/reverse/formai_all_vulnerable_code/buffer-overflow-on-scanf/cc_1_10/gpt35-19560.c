//FormAI DATASET v1.0 Category: Image Classification system ; Style: detailed
/**
* A simple image classification system using C programming language.
* This program reads a user-provided image file and provides a classification
* based on the color of the image.
*/

#include <stdio.h>

int main() {

    // Declare variables
    char filename[20];
    FILE *fp;
    unsigned char img_data[640 * 480 * 3];

    // Ask user for image file
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    // Open image file
    fp = fopen(filename, "rb");
    if(!fp) {
        printf("Error opening file\n");
        return 1;
    }

    // Read image data
    fread(img_data, sizeof(unsigned char), 640 * 480 * 3, fp);

    // Close image file
    fclose(fp);

    // Perform classification based on image color
    int red = 0, green = 0, blue = 0;
    for(int i = 0; i < 640 * 480 * 3; i += 3) {
        red += img_data[i];
        green += img_data[i + 1];
        blue += img_data[i + 2];
    }

    if(red > green && red > blue) {
        printf("The image is predominantly red.\n");
    } else if(green > red && green > blue) {
        printf("The image is predominantly green.\n");
    } else if(blue > red && blue > green) {
        printf("The image is predominantly blue.\n");
    } else {
        printf("The image does not have a predominant color.\n");
    }

    return 0;
}