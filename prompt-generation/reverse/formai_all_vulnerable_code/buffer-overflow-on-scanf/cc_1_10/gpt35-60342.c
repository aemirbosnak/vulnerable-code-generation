//FormAI DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100

void backup(char* file_name) {
    FILE* input_file;
    FILE* output_file;
    char output_file_name[MAX_FILE_NAME];
    char buffer;

    // Generate output file name
    strcpy(output_file_name, file_name);
    strcat(output_file_name, ".backup");

    // Open input file
    input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    // Open output file
    output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Could not create backup file %s\n", output_file_name);
        fclose(input_file);
        return;
    }

    // Copy contents from input file to output file
    while (fread(&buffer, 1, 1, input_file) == 1) {
        fwrite(&buffer, 1, 1, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Backup of %s created successfully as %s\n", file_name, output_file_name);
}

int main() {
    char file_name[MAX_FILE_NAME];

    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    backup(file_name);

    return 0;
}