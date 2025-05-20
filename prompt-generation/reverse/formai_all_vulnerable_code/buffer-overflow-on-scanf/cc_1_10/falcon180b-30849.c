//Falcon-180B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
} File;

int main() {
    int num_files;
    char file_name[MAX_FILE_NAME_LENGTH];
    File *files = malloc(sizeof(File) * 10);
    int i;

    printf("Enter the number of files to be opened: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter the file name for file %d: ", i + 1);
        scanf("%s", file_name);
        strcpy(files[i].file_name, file_name);
        files[i].fp = fopen(file_name, "r");
        if (files[i].fp == NULL) {
            printf("Error opening file %s\n", file_name);
            exit(1);
        }
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (line[0] == 'q') {
            printf("Closing files...\n");
            for (i = 0; i < num_files; i++) {
                fclose(files[i].fp);
            }
            free(files);
            exit(0);
        }
        for (i = 0; i < num_files; i++) {
            fputs(line, files[i].fp);
        }
    }

    printf("Exiting...\n");
    for (i = 0; i < num_files; i++) {
        fclose(files[i].fp);
    }
    free(files);
    return 0;
}