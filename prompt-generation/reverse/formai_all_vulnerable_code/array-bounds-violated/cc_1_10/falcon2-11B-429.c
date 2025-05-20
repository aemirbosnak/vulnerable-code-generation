//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define BLOCK_SIZE 5

int compress(char *data, char *compressed, int size) {
    int i, j, k, l;
    int count[26] = {0};
    char block[BLOCK_SIZE];

    for(i = 0; i < size; i++) {
        count[data[i] - 'A']++;
    }

    for(i = 0; i < size; i++) {
        if(count[data[i] - 'A'] >= BLOCK_SIZE) {
            for(j = 0; j < BLOCK_SIZE; j++) {
                block[j] = data[i + j];
            }
            for(k = 0; k < BLOCK_SIZE; k++) {
                compressed[k] = 'A' + (block[k] - 'A');
                count[block[k] - 'A']--;
            }
            for(l = 0; l < size - BLOCK_SIZE; l++) {
                compressed[k] = 'A' + (data[l + k] - 'A');
                count[data[l + k] - 'A']--;
            }
            i += BLOCK_SIZE;
        }
    }

    return size - i;
}

int main() {
    char data[MAX_SIZE];
    char compressed[MAX_SIZE];

    printf("Enter a string: ");
    fgets(data, MAX_SIZE, stdin);

    int size = strlen(data);
    int compressed_size = compress(data, compressed, size);

    printf("Compressed string: %s\n", compressed);
    printf("Size of compressed string: %d\n", compressed_size);

    return 0;
}