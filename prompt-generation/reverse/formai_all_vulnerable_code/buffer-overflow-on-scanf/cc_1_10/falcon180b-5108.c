//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert image to ASCII art
void image_to_ascii(char *filename, int width, int height) {
    FILE *fp;
    unsigned char header[54];
    int i, j, k, count = 0;
    char ascii_art[height][width];

    // Open the image file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Check if the file is a valid BMP image
    fread(header, 1, 54, fp);
    if (header[0]!= 'B' || header[1]!= 'M') {
        printf("Error: Invalid BMP image\n");
        fclose(fp);
        exit(1);
    }

    // Get image dimensions from header
    int image_width = *(int *)&header[18];
    int image_height = *(int *)&header[22];

    // Check if image dimensions are valid
    if (image_width <= 0 || image_height <= 0) {
        printf("Error: Invalid image dimensions\n");
        fclose(fp);
        exit(1);
    }

    // Calculate the number of pixels in the image
    int num_pixels = image_width * image_height;

    // Read the image data from the file
    unsigned char *data = (unsigned char *)malloc(num_pixels * 3);
    fread(data, 1, num_pixels * 3, fp);

    // Convert the image data to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            int r = data[index];
            int g = data[index + 1];
            int b = data[index + 2];

            int brightness = (r + g + b) / 3;
            if (brightness < 128) {
                ascii_art[i][j] = '@';
            } else if (brightness < 192) {
                ascii_art[i][j] = '#';
            } else if (brightness < 224) {
                ascii_art[i][j] = '$';
            } else if (brightness < 240) {
                ascii_art[i][j] = '%';
            } else if (brightness < 248) {
                ascii_art[i][j] = '&';
            } else {
                ascii_art[i][j] = '*';
            }
        }
    }

    // Print the ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    // Free memory and close the file
    free(data);
    fclose(fp);
}

int main() {
    char filename[100];
    int width, height;

    // Get image filename and dimensions from user
    printf("Enter the image filename: ");
    scanf("%s", filename);
    printf("Enter the image width: ");
    scanf("%d", &width);
    printf("Enter the image height: ");
    scanf("%d", &height);

    // Convert image to ASCII art
    image_to_ascii(filename, width, height);

    return 0;
}