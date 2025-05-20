//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *filename;
    int num_lines;
    char *lines[MAX_NUM_LINES];
} FileData;

void read_file(FileData *file_data, FILE *file) {
    char line[MAX_LINE_LENGTH];
    int line_num = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line_num >= MAX_NUM_LINES) {
            printf("Error: File contains more than %d lines.\n", MAX_NUM_LINES);
            exit(1);
        }

        file_data->lines[line_num] = strdup(line);
        line_num++;
    }

    file_data->num_lines = line_num;
}

void write_file(FileData *file_data, FILE *file) {
    for (int i = 0; i < file_data->num_lines; i++) {
        fprintf(file, "%s", file_data->lines[i]);
    }
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    FileData input_file_data;
    read_file(&input_file_data, input_file);

    fclose(input_file);

    char output_filename[MAX_FILE_NAME_LENGTH];
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Cannot create output file.\n");
        return 1;
    }

    write_file(&input_file_data, output_file);

    fclose(output_file);
    printf("File backup completed.\n");

    return 0;
}