//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char name[20];
    int size;
    int checksum;
} File;

int calculate_checksum(char *buffer, int size) {
    int checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += buffer[i];
    }
    return checksum % 256;
}

void print_file_info(File *file) {
    printf("Name: %s\n", file->name);
    printf("Size: %d\n", file->size);
    printf("Checksum: %d\n", file->checksum);
}

int main() {
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    char buffer[MAX_SIZE];
    fread(buffer, size, 1, fp);
    fclose(fp);

    File file;
    strcpy(file.name, filename);
    file.size = size;
    file.checksum = calculate_checksum(buffer, size);

    print_file_info(&file);

    return 0;
}