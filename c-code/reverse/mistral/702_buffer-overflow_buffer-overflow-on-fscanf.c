#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100

typedef struct {
    int label;
    unsigned char data[3 * MAX_CHAR * MAX_CHAR];
} Image;

void load_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d\n", &image->label);
    for (int i = 0; i < 3 * MAX_CHAR * MAX_CHAR; ++i) {
        fscanf(file, "%hu", &image->data[i]);
    }

    fclose(file);
}

int main() {
    Image images[2];
    char filename[MAX_CHAR];

    printf("Enter image file names (space-separated): ");
    scanf("%s %s", filename, filename + MAX_CHAR);

    load_image(filename, &images[0]);
    load_image(filename + MAX_CHAR, &images[1]);

    // Simple classification algorithm
    int prediction = images[0].label < images[1].label ? images[0].label : images[1].label;

    printf("Predicted label: %d\n", prediction);

    return 0;
}
