//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

// Function to encrypt a single character
char encrypt_char(char c) {
    if (isalpha(c)) {
        if (isupper(c)) {
            return (char) (c + 13);
        } else {
            return (char) (c - 13);
        }
    } else {
        return c;
    }
}

// Function to decrypt a single character
char decrypt_char(char c) {
    if (isalpha(c)) {
        if (isupper(c)) {
            return (char) (c - 13);
        } else {
            return (char) (c + 13);
        }
    } else {
        return c;
    }
}

// Function to encrypt a string
void encrypt_string(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = encrypt_char(str[i]);
        i++;
    }
}

// Function to decrypt a string
void decrypt_string(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = decrypt_char(str[i]);
        i++;
    }
}

int main() {
    FILE* input_file;
    FILE* output_file;
    char buffer[BUFFER_SIZE];
    char filename[100];

    // Get input and output filenames from user
    printf("Enter input filename: ");
    scanf("%s", filename);
    printf("Enter output filename: ");
    scanf("%s", filename);

    // Open input and output files
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    output_file = fopen(filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file into memory
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        // Encrypt buffer
        encrypt_string(buffer);
        // Write encrypted buffer to output file
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File encryption complete.\n");

    return 0;
}