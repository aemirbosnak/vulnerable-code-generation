//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_CONTENT_LEN 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char file_content[MAX_FILE_CONTENT_LEN];
    time_t last_modified;
} File;

int main() {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char input_file_name[MAX_FILE_NAME_LEN];
    char output_file_name[MAX_FILE_NAME_LEN];
    char line[MAX_FILE_CONTENT_LEN];
    File file;

    printf("Enter the input file name: ");
    scanf("%s", input_file_name);

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    printf("Enter the output file name: ");
    scanf("%s", output_file_name);

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    while (fgets(line, MAX_FILE_CONTENT_LEN, input_file)!= NULL) {
        strcpy(file.file_content, line);
        strcpy(file.file_name, input_file_name);
        file.last_modified = time(NULL);

        fwrite(&file, sizeof(File), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File backup completed successfully.\n");

    return 0;
}