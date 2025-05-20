#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define CHANNEL_MAX 3

void process_image(char* input_file, char* output_file, int* channels) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    char buffer[BUFFER_SIZE];
    int width, height, channel;

    if (input && output) {
        if (sscanf(buffer, "%d %d %d", &width, &height, &channel) == 3) {
            if (channel >= 1 && channel <= CHANNEL_MAX) {
                *channels = channel;
                // Process the image here (dummy implementation)
                for (int i = 0; i < height; i++) {
                    fgets(buffer, BUFFER_SIZE, input);
                    fprintf(output, "%s", buffer);
                }
                fclose(input);
                fclose(output);
            } else {
                fprintf(stderr, "Invalid number of channels. Supported values: 1, 2, or 3.\n");
            }
        } else {
            fprintf(stderr, "Invalid image format.\n");
        }
    } else {
        fprintf(stderr, "Could not open files.\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <number_of_channels>\n", argv[0]);
        return 1;
    }

    process_image(argv[1], argv[2], (int*)&argc);
    return 0;
}
