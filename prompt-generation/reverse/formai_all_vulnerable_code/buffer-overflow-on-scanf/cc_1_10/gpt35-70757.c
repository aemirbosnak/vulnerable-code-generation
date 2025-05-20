//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <string.h>

// This program extracts metadata from a C source file and saves it to a separate file

struct metadata {
    char filename[50];
    char author[50];
    char date[20];
};

int main() {

    // Get input C file name from user
    char input_filename[50];
    printf("Enter the name of the C file to extract metadata from: ");
    scanf("%s", input_filename);

    // Open input C file in read mode
    FILE *input_file = fopen(input_filename, "r");
    
    // Get output metadata file name from user
    char output_filename[50];
    printf("Enter the name of the output metadata file: ");
    scanf("%s", output_filename);

    // Open output metadata file in write mode
    FILE *output_file = fopen(output_filename, "w");

    // Initialize metadata struct
    struct metadata data;
    strcpy(data.filename, input_filename);

    // Extract metadata from input C file and save it to metadata struct
    char line[100];
    while (fgets(line, 100, input_file) != NULL) {
        if (strstr(line, "Author:") != NULL) {
            sscanf(line, "Author: %[^\n]", data.author);
        } else if (strstr(line, "Date:") != NULL) {
            sscanf(line, "Date: %[^\n]", data.date);
        }
    }

    // Write metadata to output file
    fprintf(output_file, "File: %s\n", data.filename);
    fprintf(output_file, "Author: %s\n", data.author);
    fprintf(output_file, "Date: %s\n", data.date);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Metadata extracted and saved to %s.\n", output_filename);

    return 0;
}