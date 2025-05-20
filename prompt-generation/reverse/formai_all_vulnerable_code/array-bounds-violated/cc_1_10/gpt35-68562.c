//FormAI DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

void compress(char* input, int size, char* output, int* out_size) {
    int freq[256] = {0}, i;
    for(i = 0; i < size; i++) {
        freq[(int)input[i]]++;
    }

    // Validate input
    if (*out_size < (size + sizeof(freq))) {
        *out_size = -1; // Indicate failure
        return;
    }

    // Copy freq array to output
    memcpy(output, freq, sizeof(freq));

    int j = sizeof(freq);
    for(i = 0; i < size; i++) {
        int count = 1;
        while(i + 1 < size && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        output[j++] = input[i];
        char count_str[10];
        sprintf(count_str, "%d", count);
        memcpy(&output[j], count_str, strlen(count_str));
        j += strlen(count_str);
    }

    *out_size = j;
}

void decompress(char* input, int size, char* output, int* out_size) {
    int freq[256] = {0}, i;
    memcpy(freq, input, sizeof(freq));

    int j = sizeof(freq);
    for(i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c : %d\n", i, freq[i]);
        }
    }

    for(i = sizeof(freq); i < size; i++) {
        output[*out_size] = input[i];
        (*out_size)++;
        if (input[i] >= '0' && input[i] <= '9') {
            continue;
        }

        int count = atoi(&input[i + 1]);
        while(count > 1) {
            output[*out_size] = input[i];
            (*out_size)++;
            count--;
        }
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    // Compress string
    char output[MAX_SIZE];
    int out_size = sizeof(output);
    compress(input, strlen(input), output, &out_size);
    if (out_size == -1) {
        printf("Output buffer too small, compression failed\n");
        return 1;
    }

    printf("Compressed size: %d\n", out_size);
    printf("Compressed string: %s\n", output);

    // Decompress string
    char decompressed[MAX_SIZE];
    int out_size2 = 0;
    decompress(output, out_size, decompressed, &out_size2);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}