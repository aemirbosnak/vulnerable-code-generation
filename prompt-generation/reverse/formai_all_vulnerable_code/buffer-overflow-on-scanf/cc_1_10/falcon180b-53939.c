//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

typedef struct {
    char filename[100];
    char backup_filename[100];
    time_t timestamp;
} file_t;

void create_backup_filename(char* filename, char* backup_filename) {
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
}

int compare_timestamps(const void* a, const void* b) {
    const struct tm* ta = *(const struct tm**)a;
    const struct tm* tb = *(const struct tm**)b;

    return difftime(mktime(ta), mktime(tb));
}

void backup_file(file_t* file) {
    FILE* input_file = fopen(file->filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open file '%s'\n", file->filename);
        return;
    }

    FILE* output_file = fopen(file->backup_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not create backup file '%s'\n", file->backup_filename);
        fclose(input_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fread(buffer, 1, BUFFER_SIZE, input_file) > 0) {
        fwrite(buffer, 1, BUFFER_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Backup of '%s' created: '%s'\n", file->filename, file->backup_filename);
}

int main() {
    file_t files[10];
    int num_files = 0;

    while (num_files < 10) {
        printf("Enter filename (or press enter to finish): ");
        scanf("%s", files[num_files].filename);

        if (files[num_files].filename[0] == '\0') {
            break;
        }

        create_backup_filename(files[num_files].filename, files[num_files].backup_filename);
        files[num_files].timestamp = time(NULL);
        num_files++;
    }

    qsort(files, num_files, sizeof(file_t), compare_timestamps);

    for (int i = 0; i < num_files; i++) {
        backup_file(&files[i]);
    }

    return 0;
}