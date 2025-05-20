//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc!= 2) {
        printf("Usage: %s <input image>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        printf("Could not open file '%s'\n", argv[1]);
        return 1;
    }

    char buffer[1024];
    fread(buffer, 1, 1024, fp);
    fclose(fp);

    int width = atoi(strtok(buffer, "\n"));
    int height = atoi(strtok(NULL, "\n"));
    int maxWidth = width;
    int maxHeight = height;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int pixel = atoi(strtok(NULL, "\n"));
            if(pixel > maxWidth) maxWidth = pixel;
            if(pixel > maxHeight) maxHeight = pixel;
        }
    }

    FILE *fp2 = fopen(argv[1], "wb");
    if(fp2 == NULL) {
        printf("Could not open file '%s'\n", argv[1]);
        return 1;
    }

    fprintf(fp2, "%d\n%d\n", maxWidth, maxHeight);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int pixel = atoi(strtok(NULL, "\n"));
            if(pixel > maxWidth - 1) pixel = maxWidth - 1;
            if(pixel < 0) pixel = 0;
            fprintf(fp2, "%d\n", pixel);
        }
    }

    fclose(fp2);

    return 0;
}