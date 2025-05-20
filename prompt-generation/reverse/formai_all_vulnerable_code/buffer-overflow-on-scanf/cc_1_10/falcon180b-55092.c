//Falcon-180B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char filename[MAX_FILE_NAME];
    FILE *fp;
} File;

int main() {
    int num_files;
    char input_file[MAX_FILE_NAME];
    char line[MAX_LINE_LENGTH];
    File *files = (File*)malloc(sizeof(File) * 10);
    int i;

    printf("Enter the number of input files: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter input file name %d: ", i+1);
        scanf("%s", input_file);

        files[i].fp = fopen(input_file, "r");

        if (files[i].fp == NULL) {
            printf("Error opening file %s\n", input_file);
            exit(1);
        }

        strcpy(files[i].filename, input_file);
    }

    printf("Enter the search string: ");
    scanf("%s", line);

    for (i = 0; i < num_files; i++) {
        rewind(files[i].fp);

        while (fgets(line, MAX_LINE_LENGTH, files[i].fp)!= NULL) {
            if (strstr(line, line)!= NULL) {
                printf("Found in file %s:\n%s", files[i].filename, line);
            }
        }
    }

    for (i = 0; i < num_files; i++) {
        fclose(files[i].fp);
    }

    free(files);

    return 0;
}