//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct {
    char *str;
    int len;
} string_t;

string_t *compress(string_t *input) {
    string_t *output = malloc(sizeof(string_t));
    output->str = malloc(input->len + 1);
    output->len = 0;

    int i = 0;
    int j = 0;
    while (i < input->len) {
        char c = input->str[i];
        int count = 1;
        i++;
        while (i < input->len && input->str[i] == c) {
            count++;
            i++;
        }
        output->str[j++] = c;
        output->str[j++] = (char) count;
    }
    output->str[j] = '\0';
    output->len = j;

    return output;
}

string_t *decompress(string_t *input) {
    string_t *output = malloc(sizeof(string_t));
    output->str = malloc(MAX_STR_LEN);
    output->len = 0;

    int i = 0;
    int j = 0;
    while (i < input->len) {
        char c = input->str[i++];
        int count = (int) input->str[i++];
        for (int k = 0; k < count; k++) {
            output->str[j++] = c;
        }
    }
    output->str[j] = '\0';
    output->len = j;

    return output;
}

int main() {
    string_t *input = malloc(sizeof(string_t));
    input->str = malloc(MAX_STR_LEN);
    input->len = 0;

    printf("Enter a string to compress: ");
    scanf("%s", input->str);

    string_t *compressed = compress(input);

    printf("Compressed string: %s\n", compressed->str);

    string_t *decompressed = decompress(compressed);

    printf("Decompressed string: %s\n", decompressed->str);

    free(input->str);
    free(input);
    free(compressed->str);
    free(compressed);
    free(decompressed->str);
    free(decompressed);

    return 0;
}