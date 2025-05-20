//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int num_lines;
} FileInfo;

int main() {
    FILE *file_pointer;
    char file_name[MAX_FILE_NAME_LENGTH];
    int num_files = 0;
    int num_lines = 0;

    printf("Enter the name of the file to backup: ");
    scanf("%s", file_name);

    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    while (fgets(file_name, MAX_FILE_NAME_LENGTH, file_pointer)!= NULL) {
        num_lines++;
    }

    fclose(file_pointer);

    printf("Number of lines in the file: %d\n", num_lines);

    FileInfo file_info[MAX_NUM_FILES];
    int num_files_copied = 0;

    for (int i = 0; i < num_files; i++) {
        sprintf(file_name, "%s_backup_%d.txt", file_name, i + 1);
        file_pointer = fopen(file_name, "w");
        if (file_pointer == NULL) {
            printf("Failed to open file for backup.\n");
            return 1;
        }

        fputs("--------------------\n", file_pointer);
        fputs("Backed up on: ", file_pointer);
        fputs(file_name, file_pointer);
        fputs("\n--------------------\n", file_pointer);

        fputs("Line 1:\n", file_pointer);
        fputs(file_name, file_pointer);
        fputs("\n", file_pointer);
        fputs("Line 2:\n", file_pointer);
        fputs(file_name, file_pointer);
        fputs("\n", file_pointer);
        fputs("Line 3:\n", file_pointer);
        fputs(file_name, file_pointer);
        fputs("\n", file_pointer);

        fclose(file_pointer);
        num_files_copied++;
    }

    printf("Number of files copied: %d\n", num_files_copied);

    return 0;
}