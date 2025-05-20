//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_FILES 100

typedef struct {
    char *file_name;
    int num_lines;
} FileInfo;

int compare_file_info(const void *a, const void *b) {
    FileInfo *file_info_a = (FileInfo *)a;
    FileInfo *file_info_b = (FileInfo *)b;

    return strcmp(file_info_a->file_name, file_info_b->file_name);
}

int get_num_lines(FILE *file) {
    int num_lines = 0;
    char ch;

    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            num_lines++;
        }
    }

    rewind(file);

    return num_lines;
}

void read_files(FileInfo *files, int num_files) {
    int i;

    for (i = 0; i < num_files; i++) {
        files[i].num_lines = get_num_lines(fopen(files[i].file_name, "r"));
    }
}

int main(int argc, char *argv[]) {
    int num_files;
    FileInfo files[MAX_NUM_FILES];

    printf("Enter number of files to synchronize: ");
    scanf("%d", &num_files);

    printf("Enter file names:\n");

    int i;
    for (i = 0; i < num_files; i++) {
        char file_name[MAX_FILE_NAME_LENGTH];
        scanf("%s", file_name);

        files[i].file_name = strdup(file_name);
    }

    read_files(files, num_files);

    qsort(files, num_files, sizeof(FileInfo), compare_file_info);

    printf("Sorted files:\n");

    for (i = 0; i < num_files; i++) {
        printf("%s\n", files[i].file_name);
    }

    return 0;
}