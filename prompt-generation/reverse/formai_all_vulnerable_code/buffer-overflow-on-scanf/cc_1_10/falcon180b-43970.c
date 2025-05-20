//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH], output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int key;

    // Get input file name and encryption key from user
    printf("Enter input file name: ");
    fgets(input_filename, MAX_LINE_LENGTH, stdin);
    input_filename[strcspn(input_filename, "\n")] = '\0'; // Remove newline character from input filename

    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Open input file for reading and output file for writing
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_file = fopen("encrypted.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        exit(1);
    }

    // Encrypt and write each line of input file to output file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]) + key;
            if (isalpha(line[i])) {
                line[i] = toupper(line[i]);
            }
        }
        fputs(line, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Input file encrypted successfully and saved as encrypted.txt.\n");

    return 0;
}