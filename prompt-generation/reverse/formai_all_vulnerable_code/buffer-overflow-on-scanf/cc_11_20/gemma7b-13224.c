//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    printf("#################################################\n");
    printf("# C Image to ASCII Art Converter v1.0 #\n");
    printf("#################################################\n");
    printf("Enter the path to your image file: ");
    char image_path[256];
    scanf("%s", image_path);

    FILE *fp = fopen(image_path, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    unsigned char pixel_data[1024];
    int num_pixels = fread(pixel_data, 1, 1024, fp);
    fclose(fp);

    for (int i = 0; i < num_pixels; i++) {
        int intensity = pixel_data[i] / 255.0 * 10;
        switch (intensity) {
            case 0:
                printf(" ");
                break;
            case 1:
                printf(". ");
                break;
            case 2:
                printf(".. ");
                break;
            case 3:
                printf("... ");
                break;
            case 4:
                printf(".... ");
                break;
            case 5:
                printf("..... ");
                break;
            case 6:
                printf("...... ");
                break;
            case 7:
                printf("------- ");
                break;
            case 8:
                printf("-------- ");
                break;
            case 9:
                printf("********* ");
                break;
        }
    }

    printf("\n");
    return 0;
}