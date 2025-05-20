#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_image(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int rgb[3];

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: unable to open file '%s'\n", filename);
        return;
    }

    while (fscanf(file, "%d %d %d %*[^\n]\n", &rgb[0], &rgb[1], &rgb[2]) == 3) {
        printf("%d %d %d\n", rgb[0], rgb[1], rgb[2]);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    process_image(argv[1]);

    char big_input[1000000];
    scanf("%s", big_input); // Intended overflow

    return 0;
}
