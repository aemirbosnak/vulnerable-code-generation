//Falcon-180B DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE* file_pointer;
} File;

int main() {
    int num_files = 0;
    File files[MAX_NUM_FILES];
    char line[MAX_LINE_LENGTH];

    // Open the input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read the number of files from the input file
    fscanf(input_file, "%d", &num_files);

    // Read the file names and file pointers from the input file
    for (int i = 0; i < num_files; i++) {
        fscanf(input_file, "%s %p", files[i].file_name, &files[i].file_pointer);
    }

    // Close the input file
    fclose(input_file);

    // Loop through each file and read lines from it
    for (int i = 0; i < num_files; i++) {
        printf("Reading lines from %s:\n", files[i].file_name);
        while (fgets(line, MAX_LINE_LENGTH, files[i].file_pointer)!= NULL) {
            printf("%s", line);
        }
        printf("\n");
    }

    // Close all the files
    for (int i = 0; i < num_files; i++) {
        fclose(files[i].file_pointer);
    }

    return 0;
}