//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define ENCRYPTION_KEY "secret"

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH], output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int file_size;
    int i;

    // Check if correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Copy input and output file names from command line arguments
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get size of input file
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    rewind(input_file);

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Encrypt input file and write to output file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        for (i = 0; line[i]!= '\0'; i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]) ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
            }
        }
        fputs(line, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encryption complete.\n");
    return 0;
}