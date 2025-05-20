//FormAI DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the data using our unique algorithm
int compress(char* data, char* compressed) {
    int n = strlen(data);
    int count = 0;
    int index = 0;
    for(int i=0; i<n; i++) {
        count++;
        if(i+1 >= n || data[i] != data[i+1]) {
            compressed[index++] = data[i];
            if(count > 1) {
                char str[10];
                sprintf(str, "%d", count);
                int len = strlen(str);
                for(int j=0; j<len; j++) {
                    compressed[index++] = str[j];
                }
            }
            count = 0;
        }
    }
    compressed[index] = '\0';
    return index;
}

// Function to decompress the data
char* decompress(char* compressed) {
    int n = strlen(compressed);
    char* decompressed = (char*)malloc(sizeof(char) * n);
    int index = 0;
    for(int i=0; i<n; i++) {
        if(compressed[i] >= '0' && compressed[i] <= '9') {
            int count = compressed[i] - '0';
            for(int j=0; j<count-1; j++) {
                decompressed[index++] = decompressed[index-1];
            }
        } else {
            decompressed[index++] = compressed[i];
        }
    }
    decompressed[index] = '\0';
    return decompressed;
}

int main() {
    char data[101], compressed[201];
    printf("Enter the data to be compressed: ");
    scanf("%[^\n]", data);

    // Compress the data
    int len = compress(data, compressed);
    printf("Compressed data: %s\n", compressed);

    // Decompress the data
    char* decompressed = decompress(compressed);
    printf("Decompressed data: %s\n", decompressed);

    return 0;
}