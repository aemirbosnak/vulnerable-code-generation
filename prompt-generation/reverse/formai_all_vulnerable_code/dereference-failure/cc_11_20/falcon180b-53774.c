//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    char *data;
    int size;
} File;

int main() {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char line[1024];
    int line_number = 0;
    int num_files = 0;
    File files[100];

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read input file and store data in array of structs
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        if (line_number >= MAX_FILE_SIZE) {
            printf("Error: Input file is too large.\n");
            exit(1);
        }
        if (strlen(line) > 0 && line[0]!= '#') {
            files[num_files].filename = strdup(line);
            files[num_files].size = strlen(line);
            files[num_files].data = malloc(files[num_files].size + 1);
            strcpy(files[num_files].data, line);
            num_files++;
        }
        line_number++;
    }

    // Sort files by size in descending order
    for (int i = 0; i < num_files - 1; i++) {
        for (int j = i + 1; j < num_files; j++) {
            if (files[i].size < files[j].size) {
                File temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Write sorted data to output file
    for (int i = 0; i < num_files; i++) {
        fprintf(output_file, "%s\n", files[i].data);
    }

    // Close files and free memory
    fclose(input_file);
    fclose(output_file);
    for (int i = 0; i < num_files; i++) {
        free(files[i].data);
        free(files[i].filename);
    }

    return 0;
}