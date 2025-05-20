#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VAL 255

void adjustBrightnessContrast(char *filename, int brightness, double contrast) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char header[1024];
    fgets(header, sizeof(header), file);
    if (strncmp(header, "P2", 2)) {
        fprintf(stderr, "Unsupported format\n");
        fclose(file);
        return;
    }

    int width, height, max_val;
    fscanf(file, "%d %d %d", &width, &height, &max_val);

    if (max_val != MAX_VAL) {
        fprintf(stderr, "Unsupported max value\n");
        fclose(file);
        return;
    }

    int *image = malloc(width * height * sizeof(int));
    for (int i = 0; i < width * height; i++) {
        fscanf(file, "%d", &image[i]);
    }
    fclose(file);

    for (int i = 0; i < width * height; i++) {
        int new_val = (int)(image[i] * contrast + brightness);
        if (new_val > MAX_VAL) {
            new_val = MAX_VAL;
        } else if (new_val < 0) {
            new_val = 0;
        }
        printf("%d ", new_val);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    free(image);
}

int main() {
    char filename[256];
    int brightness;
    double contrast;

    printf("Enter the PGM file name: ");
    scanf("%s", filename);
    printf("Enter the brightness adjustment: ");
    scanf("%d", &brightness);
    printf("Enter the contrast adjustment: ");
    scanf("%lf", &contrast);

    adjustBrightnessContrast(filename, brightness, contrast);

    return 0;
}
