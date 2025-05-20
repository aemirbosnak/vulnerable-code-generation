//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000
#define KEY_LENGTH 32

int main() {
    char input_file[MAX_LINE_LENGTH];
    char output_file[MAX_LINE_LENGTH];
    char key[KEY_LENGTH];
    FILE *input, *output;
    char line[MAX_LINE_LENGTH];
    char encrypted_line[MAX_LINE_LENGTH];
    int line_count = 0;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Get encryption key from user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Open input and output files
    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Encrypt input file and write to output file
    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        line_count++;
        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                if (isupper(line[i])) {
                    encrypted_line[i] = line[i] + (rand() % 26) - 13;
                } else {
                    encrypted_line[i] = line[i] + (rand() % 26) - 13;
                }
            } else {
                encrypted_line[i] = line[i];
            }
        }
        encrypted_line[strlen(line)] = '\0';
        fprintf(output, "Line %d: %s\n", line_count, encrypted_line);
    }

    // Close input and output files
    fclose(input);
    fclose(output);

    printf("File encryption completed successfully.\n");

    return 0;
}