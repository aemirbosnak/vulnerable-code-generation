#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *img_data = NULL;
    int img_size = 0;

    // Allocate memory for the image data
    img_data = (int *)malloc(1024 * 1024 * 3);

    // Read the image data from the file
    FILE *fp = fopen("image.jpg", "r");
    fread(img_data, 1024 * 1024 * 3, 1, fp);
    fclose(fp);

    // Apply the out-of-bounds (read) vulnerability
    img_data[1024 * 1024 * 3 - 1] = 255;

    // Free the memory allocated for the image data
    free(img_data);

    return 0;
}
