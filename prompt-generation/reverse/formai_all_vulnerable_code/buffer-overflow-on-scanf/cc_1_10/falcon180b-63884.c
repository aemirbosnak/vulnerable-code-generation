//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_FILE_NAME_SIZE 100

// Function to check if a character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to generate a random key
void generate_key(char key[MAX_KEY_SIZE]) {
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = is_letter(rand() % 26 + 'a');
    }
}

// Function to encrypt a file
void encrypt_file(char key[MAX_KEY_SIZE], char input_file[MAX_FILE_NAME_SIZE], char output_file[MAX_FILE_NAME_SIZE]) {
    FILE *in_file, *out_file;
    char buffer[1024];
    int buffer_len = 0;
    int i;

    in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(in_file);
        exit(1);
    }

    // Read in the entire input file
    while ((buffer_len = fread(buffer, 1, 1024, in_file)) > 0) {
        for (i = 0; i < buffer_len; i++) {
            // Shift the character by the key value
            if (is_letter(buffer[i])) {
                buffer[i] = is_letter(buffer[i] + key[i % MAX_KEY_SIZE]);
            }
        }
        fwrite(buffer, 1, buffer_len, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

int main() {
    char input_file[MAX_FILE_NAME_SIZE];
    char output_file[MAX_FILE_NAME_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the input file name from the user
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // Get the output file name from the user
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Generate a random key
    generate_key(key);

    // Encrypt the file
    encrypt_file(key, input_file, output_file);

    printf("File encrypted successfully!\n");

    return 0;
}