//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[50];
    int file_size;
    char *data;
} FILE_DATA;

int main() {
    FILE_DATA *file_data;
    int num_files;
    int i;
    char input_file[50];
    char output_file[50];
    char line[100];
    FILE *in_file, *out_file;

    // Open input file
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read header from input file
    fgets(line, 100, in_file);
    sscanf(line, "%d", &num_files);

    // Allocate memory for file data
    file_data = (FILE_DATA *) malloc(num_files * sizeof(FILE_DATA));
    if (file_data == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    // Read file data from input file
    for (i = 0; i < num_files; i++) {
        fgets(line, 100, in_file);
        sscanf(line, "%s %d", file_data[i].file_name, &file_data[i].file_size);
        file_data[i].data = (char *) malloc(file_data[i].file_size);
        if (file_data[i].data == NULL) {
            printf("Error allocating memory.\n");
            exit(1);
        }
        fgets(line, 100, in_file);
        strcpy(file_data[i].data, line);
    }

    // Close input file
    fclose(in_file);

    // Open output file
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);
    out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write header to output file
    fprintf(out_file, "%d\n", num_files);

    // Write file data to output file
    for (i = 0; i < num_files; i++) {
        fprintf(out_file, "%s %d\n%s\n", file_data[i].file_name, file_data[i].file_size, file_data[i].data);
    }

    // Close output file
    fclose(out_file);

    return 0;
}