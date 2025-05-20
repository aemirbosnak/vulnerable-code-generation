//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    int size;
    char *data;
} File;

int main() {
    FILE *fp;
    char c;
    int file_count = 0;
    File files[100];

    fp = fopen("data.bin", "rb");
    if (fp == NULL) {
        printf("Error: data.bin not found\n");
        return 1;
    }

    while (fread(&c, 1, 1, fp)!= 0) {
        if (c == '\n') {
            file_count++;
        }
    }

    rewind(fp);

    int i = 0;
    while (fread(&c, 1, 1, fp)!= 0) {
        if (c == '\n') {
            files[i].filename = malloc(file_count + 1);
            files[i].size = 0;
            files[i].data = malloc(MAX_FILE_SIZE);

            int j = 0;
            while (fread(&c, 1, 1, fp)!= 0) {
                if (c == '\n') {
                    files[i].filename[j] = '\0';
                    break;
                } else {
                    files[i].filename[j++] = c;
                }
            }

            int k = 0;
            while (fread(&c, 1, 1, fp)!= 0) {
                if (c == '\n') {
                    break;
                } else {
                    files[i].data[k++] = c;
                }
            }

            files[i].size = k;

            i++;
        }
    }

    fclose(fp);

    for (int j = 0; j < i; j++) {
        printf("Filename: %s\nSize: %d\n", files[j].filename, files[j].size);
        printf("Data:\n");
        for (int k = 0; k < files[j].size; k++) {
            printf("%c", files[j].data[k]);
        }
        printf("\n");
    }

    for (int j = 0; j < i; j++) {
        free(files[j].filename);
        free(files[j].data);
    }

    return 0;
}