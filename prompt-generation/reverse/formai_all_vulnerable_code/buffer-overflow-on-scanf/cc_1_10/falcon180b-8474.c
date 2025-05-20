//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 100

typedef struct {
    char filename[MAX_FILE_NAME_SIZE];
    FILE *file;
} file_t;

int main() {
    int num_files;
    char input_buffer[MAX_LINE_SIZE];
    file_t file_list[10]; // assume max 10 files

    printf("Enter number of files: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter file name for file %d: ", i+1);
        scanf("%s", file_list[i].filename);
        file_list[i].file = fopen(file_list[i].filename, "r");
        if (file_list[i].file == NULL) {
            printf("Error: could not open file %s\n", file_list[i].filename);
            exit(1);
        }
    }

    while (fgets(input_buffer, MAX_LINE_SIZE, stdin)!= NULL) {
        for (int i = 0; i < num_files; i++) {
            char *line = strchr(input_buffer, '\n'); // find the end of the line
            if (line!= NULL) *line = '\0'; // replace with null terminator
            line = strchr(input_buffer, '\r'); // find the end of the line (Windows)
            if (line!= NULL) *line = '\0'; // replace with null terminator

            FILE *file = file_list[i].file;
            char *result = fgets(file_list[i].filename, MAX_LINE_SIZE, file);

            if (result!= NULL) {
                printf("Result for file %s: %s", file_list[i].filename, result);
            }
        }
    }

    for (int i = 0; i < num_files; i++) {
        fclose(file_list[i].file);
    }

    return 0;
}