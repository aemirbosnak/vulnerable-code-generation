//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000

typedef struct {
    char file_name[256];
    char file_type[32];
    int file_size;
    int file_location;
} file_info;

int main() {
    int num_files = 0;
    file_info files[MAX_FILES];
    char input_file[256];
    FILE *input;

    // Open input file
    input = fopen("input.txt", "r");

    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read in file information
    while (fscanf(input, "%s %s %d %d\n", files[num_files].file_name, files[num_files].file_type, &files[num_files].file_size, &files[num_files].file_location)!= EOF) {
        num_files++;
        if (num_files >= MAX_FILES) {
            printf("Error: Maximum number of files exceeded.\n");
            exit(1);
        }
    }

    // Sort files by size
    for (int i = 0; i < num_files - 1; i++) {
        for (int j = i + 1; j < num_files; j++) {
            if (files[i].file_size > files[j].file_size) {
                file_info temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    // Print sorted file information
    printf("Sorted by size:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%s) - %d bytes - location: %d\n", files[i].file_name, files[i].file_type, files[i].file_size, files[i].file_location);
    }

    // Close input file
    fclose(input);

    return 0;
}