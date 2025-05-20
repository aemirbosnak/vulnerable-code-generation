//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_COUNT 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    bool is_synced;
} File;

void read_files(File* files, int* file_count) {
    FILE* input_file = fopen("files.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    *file_count = 0;
    while (fscanf(input_file, "%s", files[*file_count].name)!= EOF) {
        files[*file_count].is_synced = false;
        (*file_count)++;
    }

    fclose(input_file);
}

void write_files(File* files, int file_count) {
    FILE* output_file = fopen("files.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    for (int i = 0; i < file_count; i++) {
        fprintf(output_file, "%s\n", files[i].name);
    }

    fclose(output_file);
}

void sync_files(File* files, int file_count) {
    for (int i = 0; i < file_count; i++) {
        if (!files[i].is_synced) {
            printf("Syncing file: %s\n", files[i].name);
            files[i].is_synced = true;
        }
    }
}

int main() {
    File files[MAX_FILE_COUNT];
    int file_count = 0;

    read_files(files, &file_count);
    sync_files(files, file_count);
    write_files(files, file_count);

    return 0;
}