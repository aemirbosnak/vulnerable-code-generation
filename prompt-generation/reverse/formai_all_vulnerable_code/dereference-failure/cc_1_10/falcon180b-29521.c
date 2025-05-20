//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt_file(FILE *file) {
    char ch;
    int key = 3;

    // Loop through the file
    while ((ch = fgetc(file))!= EOF) {
        // Encrypt the character
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ((ch - 65 + key) % 26) + 65;
            } else {
                ch = ((ch - 97 + key) % 26) + 97;
            }
        }

        // Write the encrypted character to the file
        fputc(ch, file);
    }

    // Seek to the beginning of the file
    rewind(file);
}

int main() {
    char input_file[100];
    char output_file[100];
    FILE *in, *out;

    // Get input and output file names
    printf("Enter the input file name: ");
    scanf("%s", input_file);
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    // Open input file
    in = fopen(input_file, "r");

    // Check if input file exists
    if (in == NULL) {
        printf("Input file not found.\n");
        exit(1);
    }

    // Open output file
    out = fopen(output_file, "w");

    // Check if output file was created successfully
    if (out == NULL) {
        printf("Could not create output file.\n");
        exit(1);
    }

    // Encrypt the file
    encrypt_file(in);

    // Close files
    fclose(in);
    fclose(out);

    printf("File encrypted successfully.\n");
    return 0;
}