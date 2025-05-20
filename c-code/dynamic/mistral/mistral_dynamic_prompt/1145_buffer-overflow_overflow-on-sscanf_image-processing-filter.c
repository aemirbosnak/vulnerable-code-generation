#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_image(char *input_file, char *output_file, char *filter) {
    FILE *input, *output;
    int width, height, r, g, b, i, j;
    char data[3 * 1024];

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (sscanf(filter, "%d %d", &width, &height) != 2) {
        fprintf(stderr, "Invalid filter format\n");
        exit(1);
    }

    fgets(data, sizeof(data), input);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width * 3; j++) {
            sscanf(data + i * width * 3 + j, "%d %d %d", &r, &g, &b);
            // Your creative buffer overflow exploit here...
            if (j + 4 > sizeof(data)) {
                fprintf(stderr, "Overflow\n");
                exit(1);
            }
            fprintf(output, " %d %d %d", r + 100, g + 100, b + 100);
        }
        fgets(data, sizeof(data), input);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <filter>\n", argv[0]);
        return 1;
    }
    process_image(argv[1], argv[2], argv[3]);
    return 0;
}
