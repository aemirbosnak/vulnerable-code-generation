#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

void process_image(char* input_path, char* output_path) {
    FILE *input_file = fopen(input_path, "r");
    FILE *output_file = fopen(output_path, "w");

    char buffer[MAX_INPUT];
    gets(buffer);

    // Process the image here (for example, convert to grayscale)

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    process_image(argv[1], argv[2]);

    return 0;
}
