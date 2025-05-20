//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_CHARS (MAX_WIDTH * MAX_HEIGHT)

void print_ascii_art(char *ascii_art) {
    printf("%s\n", ascii_art);
}

int main() {
    FILE *input_file;
    char input_filename[100];
    char *input_buffer = NULL;
    size_t input_buffer_size = 0;
    char *ascii_art = NULL;
    size_t ascii_art_size = 0;

    // Open input file
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read input file into buffer
    fseek(input_file, 0, SEEK_END);
    input_buffer_size = ftell(input_file);
    rewind(input_file);
    input_buffer = malloc(input_buffer_size + 1);
    if (input_buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(input_file);
        return 1;
    }
    fread(input_buffer, input_buffer_size, 1, input_file);
    fclose(input_file);
    input_buffer[input_buffer_size] = '\0';

    // Convert input buffer to ASCII art
    ascii_art_size = input_buffer_size * 2;
    ascii_art = malloc(ascii_art_size + 1);
    if (ascii_art == NULL) {
        printf("Error allocating memory.\n");
        free(input_buffer);
        return 1;
    }
    ascii_art[0] = '\0';
    for (int i = 0; i < input_buffer_size; i++) {
        char ascii_char = input_buffer[i];
        switch (ascii_char) {
            case '\0':
                strcat(ascii_art, " ");
                break;
            case '\n':
                strcat(ascii_art, "\n");
                break;
            case '\t':
                strcat(ascii_art, "\t");
                break;
            default:
                sprintf(ascii_art + strlen(ascii_art), "%c", ascii_char);
        }
    }

    // Print ASCII art
    print_ascii_art(ascii_art);

    // Free memory
    free(input_buffer);
    free(ascii_art);

    return 0;
}