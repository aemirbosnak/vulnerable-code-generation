//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_ART_WIDTH 50

char char_map[] = ".:-=+*#%@&";

void generate_art(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        fprintf(stderr, "Error: could not open input file.\n");
        exit(1);
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        fprintf(stderr, "Error: could not open output file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int line_length = 0;

    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        for (int i = 0; i < strlen(line); i++) {
            int ascii_value = line[i];
            int char_index = ascii_value % 10;
            if (char_index < 0) {
                char_index += 10;
            }
            char_index *= 3;

            if (line_length + 3 > MAX_ART_WIDTH) {
                fprintf(output, "\n");
                line_length = 0;
            }

            fprintf(output, "%c", char_map[char_index]);
            line_length += 3;
        }
    }

    if (line_length > 0) {
        fprintf(output, "\n");
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    generate_art(argv[1], argv[2]);

    return 0;
}