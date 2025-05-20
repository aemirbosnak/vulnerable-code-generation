#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 100

void process_image(char* filename) {
    char buffer[MAX_BUFFER];
    FILE *file = fopen(filename, "r");

    if (file) {
        printf("Reading image: %s\n", filename);
        fgets(buffer, MAX_BUFFER, file);
        fclose(file);

        printf("Processed image data:\n%s", buffer);
    } else {
        printf("Error: Could not open file: %s\n", filename);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: image_filter <filename>\n");
        return 1;
    }

    process_image(argv[1]);
    return 0;
}
