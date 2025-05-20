//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (ch + 13) % 26;
            ch = tolower(ch);
        }
        fputc(ch, output_file);
    }
}

// Function to decrypt the file
void decrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (ch - 13 + 26) % 26;
            ch = tolower(ch);
        }
        fputc(ch, output_file);
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Create output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // Encrypt the file
    encrypt_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");

    return 0;
}