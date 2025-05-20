#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char* input, int length) {
    if (input == NULL || length <= 0) {
        return;
    }

    char* output = (char*)malloc(length);
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    output[0] = input[0];
    int count = 1;

    for (int i = 1; i < length; i++) {
        if (input[i] == output[count - 1]) {
            count++;
        } else {
            output[count++] = input[i];
        }
    }

    output[count] = '\0';
    printf("Compressed: %s\n", output);

    free(output);
}

void decompress(char* input, int length) {
    if (input == NULL || length <= 0) {
        return;
    }

    char* output = (char*)malloc(length * 2);
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    int write_index = 0;
    int repeat_count = 0;
    char current_char = input[0];

    for (int i = 0; i < length; i++) {
        if (isdigit(input[i])) {
            repeat_count = repeat_count * 10 + (input[i] - '0');
        } else {
            while (repeat_count > 0) {
                output[write_index++] = current_char;
                repeat_count--;
            }
            current_char = input[i];
            repeat_count = 0;
        }
    }

    if (repeat_count > 0) {
        while (repeat_count > 0) {
            output[write_index++] = current_char;
            repeat_count--;
        }
    }

    output[write_index] = '\0';
    printf("Decompressed: %s\n", output);

    free(output);
}

int main() {
    char data[] = "aabbccdd";
    int len = strlen(data);

    printf("Original: %s\n", data);
    compress(data, len);
    decompress(data, len);

    // Deliberate null pointer dereference vulnerability
    char* ptr = NULL;
    *ptr = 'X'; // This will cause segmentation fault

    return 0;
}
