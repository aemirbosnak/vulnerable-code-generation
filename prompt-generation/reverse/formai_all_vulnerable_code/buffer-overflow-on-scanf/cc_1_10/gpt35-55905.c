//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_FILENAME_SIZE 100

void encrypt(char input_file[MAX_FILENAME_SIZE], char output_file[MAX_FILENAME_SIZE], int key) {
    FILE *fptr_in, *fptr_out;
    char curr_char;
    char encrypted[MAX_INPUT_SIZE];
    int i = 0;

    // Open input file
    fptr_in = fopen(input_file, "r");

    // Check if the input file exists
    if (fptr_in == NULL) {
        printf("Input file '%s' does not exist. Exiting.\n", input_file);
        exit(1);
    }

    // Open output file
    fptr_out = fopen(output_file, "w");

    // Read characters one by one and encrypt them
    while ((curr_char = fgetc(fptr_in)) != EOF) {
        encrypted[i] = curr_char + key;
        i++;

        // Write to output file for every 50 characters encrypted
        if (i == 50) {
            encrypted[i] = '\0'; // Add null character to end of string
            fprintf(fptr_out, "%s", encrypted);
            i = 0;
        }
    }

    // If there are any remaining characters, write them to the output file
    if (i != 0) {
        encrypted[i] = '\0';
        fprintf(fptr_out, "%s", encrypted);
    }

    // Close file pointers
    fclose(fptr_in);
    fclose(fptr_out);
}

int main() {
    char input_file[MAX_FILENAME_SIZE];
    char output_file[MAX_FILENAME_SIZE];
    int key;

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", input_file);

    printf("Enter the key for encryption: ");
    scanf("%d", &key);

    // Create output file name
    strcpy(output_file, "encrypted_");
    strcat(output_file, input_file);

    // Encrypt the file
    encrypt(input_file, output_file, key);

    printf("Encryption complete. Output written to '%s'.\n", output_file);

    return 0;
}