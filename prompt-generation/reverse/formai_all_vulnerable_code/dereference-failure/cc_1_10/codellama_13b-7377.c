//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
// Compression Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compression Algorithm
void compress(char *src, char *dest) {
    int i, j, k;
    int count = 0;
    int len = strlen(src);

    for (i = 0; i < len; i++) {
        if (src[i] == src[i+1]) {
            count++;
        } else {
            dest[j++] = src[i];
            if (count > 0) {
                dest[j++] = count + '0';
            }
            count = 0;
        }
    }
    dest[j] = '\0';
}

// Decompression Algorithm
void decompress(char *src, char *dest) {
    int i, j, k;
    int count = 0;
    int len = strlen(src);

    for (i = 0; i < len; i++) {
        if (src[i] >= '0' && src[i] <= '9') {
            count = src[i] - '0';
        } else {
            for (k = 0; k < count; k++) {
                dest[j++] = src[i];
            }
            count = 0;
        }
    }
    dest[j] = '\0';
}

int main() {
    char src[100] = "AAABBBCCC";
    char dest[100];

    compress(src, dest);
    printf("Compressed String: %s\n", dest);

    decompress(dest, src);
    printf("Decompressed String: %s\n", src);

    return 0;
}