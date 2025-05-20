//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char name[20];
    int size;
} File;

int main() {
    FILE *fp;
    char filename[20];
    int i, j, k;
    int num_files;
    File files[100];

    printf("Enter the name of the corrupted file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    if (file_size == 0) {
        printf("File is empty.\n");
        return 1;
    }

    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    fread(buffer, 1, file_size, fp);
    fclose(fp);

    int index = 0;
    while (index < file_size) {
        if (buffer[index] == '\0') {
            files[num_files].name[k] = '\0';
            files[num_files].size = index - j;
            num_files++;
            k = 0;
        } else if (buffer[index] == '\n') {
            files[num_files].name[k] = '\0';
            files[num_files].size = index - j;
            num_files++;
            k = 0;
        } else {
            strncat(files[num_files].name, &buffer[index], 1);
            k++;
        }
        index++;
    }

    if (num_files == 0) {
        printf("No files found.\n");
        return 1;
    }

    printf("Recovered files:\n");
    for (i = 0; i < num_files; i++) {
        printf("Name: %s\nSize: %d\n", files[i].name, files[i].size);
    }

    return 0;
}