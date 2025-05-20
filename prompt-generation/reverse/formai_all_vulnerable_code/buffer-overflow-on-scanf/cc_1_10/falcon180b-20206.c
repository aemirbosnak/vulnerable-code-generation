//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover data from a corrupted file
void recover_data(FILE *file, char *output_file) {
    char ch;
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    // Read each character from the input file
    while ((ch = fgetc(file))!= EOF) {
        // Check if the character is valid
        if (ch >= 32 && ch <= 126) {
            // Write the character to the output file
            fprintf(output, "%c", ch);
        } else {
            // Replace invalid characters with a space
            fprintf(output, " ");
        }
    }

    // Close the input and output files
    fclose(file);
    fclose(output);
    printf("Data recovery successful!\n");
}

int main() {
    FILE *file;
    char input_file[100], output_file[100];

    // Get input file name from user
    printf("Enter the name of the corrupted file: ");
    scanf("%s", input_file);

    // Open the input file for reading
    file = fopen(input_file, "r");
    if (file == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    // Generate output file name
    strcpy(output_file, input_file);
    strcat(output_file, "_recovered.txt");

    // Recover data and save to output file
    recover_data(file, output_file);

    return 0;
}