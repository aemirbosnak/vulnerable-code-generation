//FormAI DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

typedef struct CompressionAlgorithm_t {
    char name[32];
    void (*compress)(char*);
    void (*decompress)(char*);
} CompressionAlgorithm ;

// Define your compression algorithms here

void simpleCompression(char* data) {
    char compressed[MAX_LENGTH];
    int len = strlen(data);
    int index = 0;
    for (int i = 0; i < len; i++) {
        compressed[index++] = data[i];
        compressed[index++] = '-';
    }
    compressed[index] = '\0';
    printf("Compressed data: %s\n", compressed);
}

void simpleDecompression(char* data) {
    char decompressed[MAX_LENGTH];
    int len = strlen(data);
    int index = 0;
    for (int i = 0; i < len; i=i+2) {
        decompressed[index++] = data[i];
    }
    decompressed[index] = '\0';
    printf("Decompressed data: %s\n", decompressed);
}

void advancedCompression(char* data) {
    // Add advanced compression algorithm
}

void advancedDecompression(char* data) {
    // Add advanced decompression algorithm
}

CompressionAlgorithm algorithms[] = {
    {"Simple Compression", simpleCompression, simpleDecompression},
    {"Advanced Compression", advancedCompression, advancedDecompression}
};

int main() {
    char data[MAX_LENGTH];
    printf("Enter data to be compressed: ");
    fgets(data, MAX_LENGTH, stdin);
    printf("\n");

    for (int i = 0; i < sizeof(algorithms)/sizeof(CompressionAlgorithm); i++) {
        printf("%d) %s\n", i+1, algorithms[i].name);
    }
    printf("Choose an algorithm to compress your data: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > sizeof(algorithms)/sizeof(CompressionAlgorithm)) {
        printf("Invalid choice!\n");
        return 1;
    }

    algorithms[choice-1].compress(data);

    printf("\n");

    printf("Do you want to decompress the data? Press Y for Yes and N for No: ");
    char ch;
    scanf(" %c", &ch);

    if (ch == 'Y' || ch == 'y') {
        algorithms[choice-1].decompress(data);
    }

    return 0;
}