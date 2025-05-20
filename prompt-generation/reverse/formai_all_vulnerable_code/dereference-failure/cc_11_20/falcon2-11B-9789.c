//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: image_to_ascii image_file output_file\n");
        return 1;
    }
    
    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "w");
    
    if (!input_file ||!output_file) {
        printf("Error opening files\n");
        return 1;
    }
    
    fseek(input_file, 0, SEEK_END);
    int image_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    
    unsigned char *image_data = malloc(image_size);
    if (!image_data) {
        printf("Error allocating memory\n");
        return 1;
    }
    
    fread(image_data, 1, image_size, input_file);
    fclose(input_file);
    
    int width = 0, height = 0;
    int x = 0, y = 0;
    char character;
    char *output_line = NULL;
    int line_length = 0;
    
    for (int i = 0; i < image_size; i++) {
        unsigned char pixel = image_data[i];
        if (pixel == 0) {
            if (x == 0) {
                width = i;
                x = 1;
            } else if (x == width) {
                x = 0;
                y++;
                if (y == height) {
                    y = 0;
                    output_line = realloc(output_line, (line_length + 1) * sizeof(char));
                    if (!output_line) {
                        printf("Error reallocating memory\n");
                        return 1;
                    }
                    output_line[line_length++] = '\n';
                }
            }
            continue;
        }
        
        for (int j = 0; j < width; j++) {
            if (pixel & (1 << j)) {
                character = isupper(pixel)? 'A' : 'a';
                output_line = realloc(output_line, (line_length + 1) * sizeof(char));
                if (!output_line) {
                    printf("Error reallocating memory\n");
                    return 1;
                }
                output_line[line_length++] = character;
            }
        }
    }
    
    if (output_line) {
        output_line[line_length++] = '\n';
    }
    
    fwrite(output_line, 1, line_length, output_file);
    fclose(output_file);
    free(image_data);
    return 0;
}