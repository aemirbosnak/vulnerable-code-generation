//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_LINE_LENGTH 1000

int main() {
    char key[MAX_KEY_LENGTH];
    char input_file[MAX_LINE_LENGTH];
    char output_file[MAX_LINE_LENGTH];
    FILE *input, *output;
    int key_length;

    // Get key from user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Check if key is valid
    for (int i = 0; i < strlen(key); i++) {
        if (!isalpha(key[i])) {
            printf("Error: Key must only contain letters.\n");
            return 1;
        }
    }

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input and output files
    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Output file could not be created.\n");
        fclose(input);
        return 1;
    }

    // Get key length
    key_length = strlen(key);

    // Loop through input file and encrypt each line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        int line_length = strlen(line);

        // Remove newline character from line
        line[line_length - 1] = '\0';

        // Encrypt line using key
        for (int i = 0; i < line_length; i++) {
            if (isalpha(line[i])) {
                int letter_index = tolower(line[i]) - 'a';
                int key_index = letter_index + key_length / 2;

                if (key_index >= key_length) {
                    key_index -= key_length;
                }

                line[i] = tolower(key[key_index]);
            }
        }

        // Write encrypted line to output file
        fprintf(output, "%s\n", line);
    }

    // Close input and output files
    fclose(input);
    fclose(output);

    printf("File encrypted successfully.\n");

    return 0;
}