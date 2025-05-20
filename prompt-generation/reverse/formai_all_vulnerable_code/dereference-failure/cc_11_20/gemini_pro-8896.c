//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Knuth's LZW compression algorithm.
 */
int main(int argc, char *argv[])
{
    // Read input file.
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    char *input_str = malloc(1024);
    if (input_str == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    size_t input_len = fread(input_str, 1, 1024, input);
    fclose(input);

    // Create dictionary.
    int dictionary_size = 256;
    char **dictionary = malloc(dictionary_size * sizeof(char *));
    if (dictionary == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < dictionary_size; i++) {
        dictionary[i] = malloc(2);
        if (dictionary[i] == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }
        dictionary[i][0] = i;
        dictionary[i][1] = '\0';
    }

    // Compress input string.
    int output_size = 0;
    int *output = malloc(1024 * sizeof(int));
    if (output == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    int current_index = 0;
    int previous_index = 0;
    for (int i = 0; i < input_len; i++) {
        current_index = -1;
        for (int j = 0; j < dictionary_size; j++) {
            if (strcmp(dictionary[j], input_str + i) == 0) {
                current_index = j;
                break;
            }
        }
        if (current_index == -1) {
            output[output_size++] = previous_index;
            char *new_entry = malloc(strlen(dictionary[previous_index]) + 2);
            if (new_entry == NULL) {
                perror("malloc");
                return EXIT_FAILURE;
            }
            strcpy(new_entry, dictionary[previous_index]);
            new_entry[strlen(new_entry)] = input_str[i];
            new_entry[strlen(new_entry) + 1] = '\0';
            dictionary[dictionary_size++] = new_entry;
        }
        previous_index = current_index;
    }
    output[output_size++] = previous_index;

    // Write output file.
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fwrite(output, sizeof(int), output_size, output_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}