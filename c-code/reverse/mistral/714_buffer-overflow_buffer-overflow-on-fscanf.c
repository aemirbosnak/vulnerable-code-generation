#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void read_pgm(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE];
    char magic_number[3];
    int width, height, max_value;

    fgets(magic_number, sizeof(magic_number), file);
    fscanf(file, "%d %d", &width, &height);
    fscanf(file, "%d", &max_value);

    // Buffer overflow vulnerability: insufficient size for fscanf input
    char data[width * height];
    fread(data, 1, width * height * (max_value + 1), file);

    // Rest of the code omitted for brevity
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pgm_image_file>\n", argv[0]);
        return 1;
    }

    read_pgm(argv[1]);

    return 0;
}
