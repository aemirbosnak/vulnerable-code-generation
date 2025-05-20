#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void process_image(char *input_image_path, char *output_image_path) {
    FILE *input_file = fopen(input_image_path, "r");
    FILE *output_file = fopen(output_image_path, "w");

    char buffer[MAX_INPUT_SIZE];
    char command[100];

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Unable to open files.\n");
        return;
    }

    printf("Processing image...\n");

    while (fgets(buffer, MAX_INPUT_SIZE, input_file)) {
        strcpy(command, "imagetool -filter grayscale ");
        strcat(command, buffer);
        system(command);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Image processing completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image_path> <output_image_path>\n", argv[0]);
        return 1;
    }

    process_image(argv[1], argv[2]);

    return 0;
}
