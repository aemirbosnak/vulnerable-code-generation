#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_image(char *filename) {
    int width, height;
    FILE *file = fopen(filename, "r");
    char buffer[10];

    if (file) {
        fscanf(file, "%d %d", &width, &height);
        fgets(buffer, sizeof(buffer), file);
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_filename>\n", argv[0]);
        return 1;
    }
    read_image(argv[1]);
    return 0;
}
