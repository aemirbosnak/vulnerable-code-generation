//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000000

typedef struct {
    char data[SIZE];
    int pos;
} Buffer;

void initBuffer(Buffer* buffer) {
    buffer->pos = 0;
    memset(buffer->data, 0, SIZE);
}

void writeBuffer(Buffer* buffer, const char* data, int len) {
    memcpy(buffer->data + buffer->pos, data, len);
    buffer->pos += len;
}

void encryptFile(FILE* inFile, FILE* outFile, int key) {
    char ch;
    Buffer inBuffer, outBuffer;

    initBuffer(&inBuffer);
    initBuffer(&outBuffer);

    while ((ch = fgetc(inFile))!= EOF) {
        if (isalpha(ch)) {
            ch = (char) (((ch - 'a') + key) % 26 + 'a');
        }
        writeBuffer(&outBuffer, &ch, 1);
    }

    fwrite(outBuffer.data, 1, outBuffer.pos, outFile);
}

int main() {
    FILE* inFile, *outFile;
    char inputFileName[100], outputFileName[100];
    int key;

    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    printf("Enter key: ");
    scanf("%d", &key);

    inFile = fopen(inputFileName, "rb");
    outFile = fopen(outputFileName, "wb");

    if (inFile == NULL || outFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    encryptFile(inFile, outFile, key);

    fclose(inFile);
    fclose(outFile);

    printf("File encrypted successfully!\n");

    return 0;
}