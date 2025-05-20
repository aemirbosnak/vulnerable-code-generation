//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a file
void encrypt_file(FILE* input, FILE* output) {
    char ch;
    while ((ch = fgetc(input))!= EOF) {
        if (isalpha(ch)) {
            // Encrypt uppercase letters
            if (isupper(ch)) {
                ch = (ch + 13) % 26 + 'A';
            }
            // Encrypt lowercase letters
            else {
                ch = (ch + 13) % 26 + 'a';
            }
        }
        fputc(ch, output);
    }
}

int main() {
    char input_filename[100];
    char output_filename[100];

    // Get input file name
    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    // Get output file name
    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    // Open input file
    FILE* input = fopen(input_filename, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    FILE* output = fopen(output_filename, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return 1;
    }

    // Encrypt file
    encrypt_file(input, output);

    // Close files
    fclose(input);
    fclose(output);

    printf("File encrypted successfully.\n");

    return 0;
}