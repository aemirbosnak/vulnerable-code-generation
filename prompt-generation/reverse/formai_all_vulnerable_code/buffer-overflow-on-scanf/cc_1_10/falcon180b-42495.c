//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000000

struct FileHeader {
    char magic[4];
    int version;
    int fileSize;
    char name[32];
};

void readFile(FILE *fp, struct FileHeader *header) {
    fseek(fp, 0, SEEK_SET);
    fread(header, sizeof(struct FileHeader), 1, fp);
}

void writeFile(FILE *fp, struct FileHeader *header) {
    fseek(fp, 0, SEEK_SET);
    fwrite(header, sizeof(struct FileHeader), 1, fp);
}

int main() {
    FILE *fp;
    char filename[64];
    struct FileHeader header;

    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    readFile(fp, &header);

    if (strcmp(header.magic, "FILE")!= 0) {
        printf("Error: Invalid file format.\n");
        exit(1);
    }

    int fileSize = header.fileSize;
    char *fileData = malloc(fileSize);

    fseek(fp, sizeof(struct FileHeader), SEEK_SET);
    fread(fileData, fileSize, 1, fp);

    printf("File data recovered successfully.\n");

    writeFile(fp, &header);
    fclose(fp);

    printf("File saved successfully.\n");

    return 0;
}