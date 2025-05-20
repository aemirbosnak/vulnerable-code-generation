//Falcon-180B DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
    int line_count;
} File;

int compare_file_names(const void *a, const void *b) {
    const char *file_name_a = ((File *)a)->file_name;
    const char *file_name_b = ((File *)b)->file_name;
    return strcmp(file_name_a, file_name_b);
}

int main() {
    int num_files;
    char input_buffer[MAX_LINE_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    File *files = (File *)malloc(MAX_NUM_FILES * sizeof(File));
    int i;

    printf("Enter the number of files to be processed: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter file name %d: ", i+1);
        scanf("%s", file_name);
        strcpy(files[i].file_name, file_name);
        files[i].fp = fopen(file_name, "r");
        if (files[i].fp == NULL) {
            printf("Error opening file %s\n", file_name);
            exit(1);
        }
        files[i].line_count = 0;
    }

    qsort(files, num_files, sizeof(File), compare_file_names);

    for (i = 0; i < num_files; i++) {
        printf("File %d: %s\n", i+1, files[i].file_name);
        while (fgets(input_buffer, MAX_LINE_LENGTH, files[i].fp)!= NULL) {
            int j;
            for (j = 0; j < strlen(input_buffer); j++) {
                if (isalpha(input_buffer[j])) {
                    input_buffer[j] = toupper(input_buffer[j]);
                }
            }
            printf("%s", input_buffer);
            files[i].line_count++;
        }
        printf("\nTotal lines in file %d: %d\n", i+1, files[i].line_count);
        fclose(files[i].fp);
    }

    free(files);
    return 0;
}