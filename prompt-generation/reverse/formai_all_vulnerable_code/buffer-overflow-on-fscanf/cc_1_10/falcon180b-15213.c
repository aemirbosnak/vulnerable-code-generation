//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    int deleted;
} FileInfo;

int main() {
    FILE *input_file, *output_file;
    char *input_filename = "input.txt";
    char *output_filename = "output.txt";
    FileInfo *file_info_array;
    int num_files = 0;
    int i;

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read in file names and sizes
    while (fscanf(input_file, "%s %d %d", file_info_array[num_files].file_name, &file_info_array[num_files].file_size, &file_info_array[num_files].deleted) == 3) {
        num_files++;
        if (num_files >= MAX_FILE_NAME_LENGTH) {
            printf("Error: too many files.\n");
            exit(1);
        }
    }
    fclose(input_file);

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write out file names and sizes
    for (i = 0; i < num_files; i++) {
        fprintf(output_file, "%s %d %d\n", file_info_array[i].file_name, file_info_array[i].file_size, file_info_array[i].deleted);
    }
    fclose(output_file);

    return 0;
}