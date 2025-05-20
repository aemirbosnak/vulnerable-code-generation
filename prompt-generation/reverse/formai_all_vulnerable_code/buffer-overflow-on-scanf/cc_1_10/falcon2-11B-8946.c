//Falcon2-11B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100

int main() {
    char input_file[50], output_file[50];
    char buf[BUF_SIZE];

    // Read input file name from user
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // Read output file name from user
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Open input file for reading
    FILE *input_file_ptr = fopen(input_file, "r");
    if (input_file_ptr == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Open output file for writing
    FILE *output_file_ptr = fopen(output_file, "w");
    if (output_file_ptr == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(input_file_ptr);
        return 1;
    }

    // Read data from input file and process it
    while (fgets(buf, BUF_SIZE, input_file_ptr)) {
        // Process the data here (e.g., convert to uppercase)
        strcpy(buf, toupper(buf));

        // Write the processed data to output file
        fputs(buf, output_file_ptr);
    }

    // Close input and output files
    fclose(input_file_ptr);
    fclose(output_file_ptr);

    printf("File processing completed successfully.\n");

    return 0;
}