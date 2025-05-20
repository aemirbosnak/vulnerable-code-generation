//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    int file_size;
    char file_content[MAX_FILE_SIZE];
} File;

int main() {
    char input_file_path[MAX_FILE_NAME_LEN];
    char output_file_path[MAX_FILE_NAME_LEN];
    FILE* input_file;
    FILE* output_file;
    int file_count = 0;
    int i;

    printf("Enter the path of the input file: ");
    scanf("%s", input_file_path);

    input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    rewind(input_file);

    File files[MAX_FILE_SIZE];

    while (fread(&files[file_count], sizeof(File), 1, input_file) == 1) {
        printf("File %d:\n", file_count + 1);
        printf("Name: %s\n", files[file_count].file_name);
        printf("Size: %d bytes\n", files[file_count].file_size);
        printf("Content:\n%s\n", files[file_count].file_content);
        file_count++;

        if (file_count >= MAX_FILE_SIZE) {
            printf("Error: Maximum number of files reached.\n");
            break;
        }
    }

    printf("Enter the path of the output file: ");
    scanf("%s", output_file_path);

    output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    for (i = 0; i < file_count; i++) {
        fprintf(output_file, "%s\n", files[i].file_name);
        fprintf(output_file, "%d\n", files[i].file_size);
        fprintf(output_file, "%s\n", files[i].file_content);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery complete.\n");

    return 0;
}