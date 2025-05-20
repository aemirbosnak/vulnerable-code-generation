//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAGIC_NUMBER 0xabad1dea
#define MAX_LENGTH 1024

void compress(char *input, char *output);
void decompress(char *compressed, char *output);

int main() {
    char input[MAX_LENGTH];
    char compressed[MAX_LENGTH];
    char output[MAX_LENGTH];

    printf("Enter a string to compress: ");
    fgets(input, MAX_LENGTH, stdin);

    compress(input, compressed);
    printf("Compressed string: %s\n", compressed);

    decompress(compressed, output);
    printf("Decompressed string: %s\n", output);

    return 0;
}

void compress(char *input, char *output) {
    int i, j, k;
    int count = 0;
    char temp[2];

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 'a') {
            count++;
            temp[0] = input[i];
            temp[1] = 'a';
            for (j = 1; j < count; j++) {
                output[k] = temp[j];
                k++;
            }
        } else {
            output[k] = input[i];
            k++;
        }
    }
}

void decompress(char *compressed, char *output) {
    int i, j, k;
    int count = 0;
    char temp[2];

    for (i = 0; i < strlen(compressed); i++) {
        if (compressed[i] == 'a') {
            count++;
            temp[0] = compressed[i];
            temp[1] = 'a';
            for (j = 1; j < count; j++) {
                output[k] = temp[j];
                k++;
            }
        } else {
            output[k] = compressed[i];
            k++;
        }
    }
}