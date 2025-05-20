#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void process_image(char *filename, int filter) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        switch (filter) {
            case 1:
                // Implement gray scale conversion here.
                break;
            case 2:
                // Implement edge detection here.
                break;
            case 3:
                // Implement pixelated effect here.
                break;
            default:
                printf("Error: Invalid filter option.\n");
                return;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: image_filter <image_file> <filter>\n");
        return 1;
    }

    process_image(argv[1], atoi(argv[2]));
    return 0;
}
