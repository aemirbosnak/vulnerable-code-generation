#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    FILE *file;
    char filename[256];
    unsigned char image_data[1024];

    printf("Enter the PGM image file name: ");
    scanf("%s", filename);

    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Intentionally introduce a buffer overflow vulnerability
    fscanf(file, "%*s %d %d %*d\n%*c", &image_data[1024], &image_data[1025]);

    fclose(file);
    return 0;
}
