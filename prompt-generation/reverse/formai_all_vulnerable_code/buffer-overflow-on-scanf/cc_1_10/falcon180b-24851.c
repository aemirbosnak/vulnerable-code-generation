//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH 256
#define BUFFER_SIZE 1024

typedef struct {
    char source_path[MAX_FILE_PATH];
    char destination_path[MAX_FILE_PATH];
} file_t;

void read_files(file_t files[], int *num_files) {
    char input[MAX_FILE_PATH];
    printf("Enter the number of files you want to synchronize: ");
    scanf("%d", num_files);

    for (int i = 0; i < *num_files; i++) {
        printf("Enter file %d source path: ", i + 1);
        scanf("%s", input);
        strcpy(files[i].source_path, input);

        printf("Enter file %d destination path: ", i + 1);
        scanf("%s", input);
        strcpy(files[i].destination_path, input);
    }
}

int compare_files(const void *a, const void *b) {
    file_t *file1 = (file_t *) a;
    file_t *file2 = (file_t *) b;

    return strcmp(file1->source_path, file2->source_path);
}

void synchronize_files(file_t files[], int num_files) {
    qsort(files, num_files, sizeof(file_t), compare_files);

    for (int i = 0; i < num_files; i++) {
        FILE *source_file = fopen(files[i].source_path, "rb");
        if (source_file == NULL) {
            printf("Error: Could not open source file '%s'.\n", files[i].source_path);
            continue;
        }

        FILE *destination_file = fopen(files[i].destination_path, "wb");
        if (destination_file == NULL) {
            printf("Error: Could not open destination file '%s'.\n", files[i].destination_path);
            fclose(source_file);
            continue;
        }

        char buffer[BUFFER_SIZE];
        while (fread(buffer, sizeof(char), BUFFER_SIZE, source_file) > 0) {
            fwrite(buffer, sizeof(char), BUFFER_SIZE, destination_file);
        }

        fclose(source_file);
        fclose(destination_file);

        printf("File '%s' synchronized successfully.\n", files[i].destination_path);
    }
}

int main() {
    file_t files[MAX_FILE_PATH];
    int num_files = 0;

    read_files(files, &num_files);
    synchronize_files(files, num_files);

    return 0;
}