//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

typedef struct {
    unsigned char data[BUFFER_SIZE];
    unsigned int length;
    unsigned int position;
} CompressBuffer;

void compress(CompressBuffer *buffer) {
    unsigned char currentByte = buffer->data[buffer->position];
    unsigned int count = 1;

    while (buffer->position < buffer->length && buffer->data[buffer->position] == currentByte) {
        count++;
        buffer->position++;
    }

    if (count > 1) {
        buffer->data[buffer->position - count] = currentByte;
        buffer->data[buffer->position - count - 1] = count;
        buffer->position -= count;
        buffer->length -= 2;
    }
}

int main() {
    FILE *inputFile;
    CompressBuffer buffer;
    unsigned char input;
    unsigned int i;

    printf("Enter the name of the input file: ");
    char fileName[100];
    scanf("%s", fileName);

    if ((inputFile = fopen(fileName, "rb")) == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fread(buffer.data, sizeof(unsigned char), BUFFER_SIZE, inputFile);
    buffer.length = ftell(inputFile);
    fclose(inputFile);

    printf("Original Data:\n");
    for (i = 0; i < buffer.length; i++) {
        printf("%02x ", buffer.data[i]);
    }

    printf("\n\nCompressed Data:\n");
    for (buffer.position = 0; buffer.position < buffer.length;) {
        compress(&buffer);
    }

    for (i = 0; i < buffer.length; i += 2) {
        printf("%02x %02x ", buffer.data[i], buffer.data[i + 1]);
    }

    return 0;
}