//FormAI DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

char* compress(char* input_string, int compression_factor) {
    int original_length = strlen(input_string);
    int compressed_length = (original_length/compression_factor) + 1;
    char* compressed_string = malloc(compressed_length);
    if (compressed_string == NULL) {
        return NULL;
    }
    int compressed_index = 0;
    for (int i = 0; i < original_length; i += compression_factor) {
        int char_counts[256] = {0};
        int max_count = 0;
        char most_common_char;
        for (int j = 0; j < compression_factor; j++) {
            if (i+j < original_length) {
                char c = input_string[i+j];
                char_counts[c]++;
                if (char_counts[c] > max_count) {
                    max_count = char_counts[c];
                    most_common_char = c;
                }
            }
        }
        compressed_string[compressed_index] = most_common_char;
        compressed_index++;
    }
    return compressed_string;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./compression <input-file> <compression-factor>\n");
        return 1;
    }
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    int compression_factor;
    if (sscanf(argv[2], "%d", &compression_factor) != 1 || compression_factor < 1) {
        printf("Error: Invalid compression factor.\n");
        return 1;
    }
    char* input_string = malloc(MAX_STRING_LENGTH);
    if (input_string == NULL) {
        printf("Error: Memory allocation error.\n");
        return 1;
    }
    fgets(input_string, MAX_STRING_LENGTH, input_file);
    fclose(input_file);
    char* compressed_string = compress(input_string, compression_factor);
    if (compressed_string == NULL) {
        printf("Error: Memory allocation error.\n");
        return 1;
    }
    printf("Original string: %s\n", input_string);
    printf("Compressed string: %s\n", compressed_string);
    free(input_string);
    free(compressed_string);
    return 0;
}