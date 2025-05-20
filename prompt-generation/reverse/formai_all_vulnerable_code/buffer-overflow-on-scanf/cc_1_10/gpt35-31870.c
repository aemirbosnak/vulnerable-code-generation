//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_REPEATS 255

/**
 * Compresses a given input string using RLE (Run-Length Encoding).
 *
 * @param input The input string to be compressed.
 * @param output The output buffer that will contain the compressed output.
 * @param length The length of the input string.
 *
 * @returns The length of the compressed output.
 */
int compress_rle(char* input, char* output, int length) {
    int i, j, count;
    char current_char;
    
    i = 0;
    j = 0;
    count = 0;
    current_char = input[i];
    
    while (i < length) {
        if (input[i] == current_char) {
            count++;
            if (count == MAX_REPEATS) {
                output[j++] = current_char;
                output[j++] = (char) count;
                count = 0;
            }
        } else {
            output[j++] = current_char;
            output[j++] = (char) count;
            current_char = input[i];
            count = 1;
        }
        i++;
    }
    
    output[j++] = current_char;
    output[j++] = (char) count;
    
    return j;
}

int main() {
    char input[BUFFER_SIZE], output[BUFFER_SIZE];
    int length, compressed_length;
    
    printf("Enter the input string: ");
    scanf("%[^\n]", input);
    getchar();  // consume newline character
    
    length = strlen(input);
    compressed_length = compress_rle(input, output, length);
    
    printf("The compressed output is: ");
    for (int i = 0; i < compressed_length; i++) {
        printf("%c", output[i]);
    }
    printf("\n");
    
    return 0;
}