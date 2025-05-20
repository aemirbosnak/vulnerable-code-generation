//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10

typedef struct {
    char filename[100];
    int filesize;
    char data[MAX_FILE_SIZE];
} file_t;

int main() {
    int num_files = 0;
    file_t *files = NULL;

    printf("Enter the number of files to recover: ");
    scanf("%d", &num_files);

    files = (file_t *) malloc(num_files * sizeof(file_t));

    for (int i = 0; i < num_files; i++) {
        printf("Enter the filename for file %d: ", i+1);
        scanf("%s", files[i].filename);
        printf("Enter the filesize for file %s: ", files[i].filename);
        scanf("%d", &files[i].filesize);
    }

    printf("Recovering files...\n");
    for (int i = 0; i < num_files; i++) {
        printf("Recovering %s...\n", files[i].filename);
        FILE *fp = fopen(files[i].filename, "rb");
        if (fp == NULL) {
            printf("%s not found.\n", files[i].filename);
            continue;
        }

        fseek(fp, 0, SEEK_END);
        files[i].filesize = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        if (files[i].filesize > MAX_FILE_SIZE) {
            printf("%s is too large.\n", files[i].filename);
            fclose(fp);
            continue;
        }

        fread(files[i].data, files[i].filesize, 1, fp);
        fclose(fp);
    }

    printf("Recovery complete.\n");

    for (int i = 0; i < num_files; i++) {
        printf("Writing %s to file...\n", files[i].filename);
        FILE *fp = fopen(files[i].filename, "wb");
        if (fp == NULL) {
            printf("%s could not be written.\n", files[i].filename);
            continue;
        }

        fwrite(files[i].data, files[i].filesize, 1, fp);
        fclose(fp);
    }

    printf("All files written successfully.\n");

    free(files);
    return 0;
}