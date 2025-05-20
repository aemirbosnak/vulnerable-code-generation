//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1024 * 1024 * 100 // 100MB

typedef struct {
    char *data;
    int size;
} file_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_t file;
    file.data = NULL;
    file.size = 0;

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file.size = ftell(fp);
    rewind(fp);

    file.data = malloc(file.size + 1);
    if (file.data == NULL) {
        printf("Error allocating memory\n");
        fclose(fp);
        return 1;
    }

    fread(file.data, file.size, 1, fp);
    fclose(fp);
    file.data[file.size] = '\0';

    int sum = 0;
    for (int i = 0; i < file.size; i++) {
        sum += tolower(file.data[i]);
    }

    printf("Checksum: %d\n", sum);

    free(file.data);
    return 0;
}