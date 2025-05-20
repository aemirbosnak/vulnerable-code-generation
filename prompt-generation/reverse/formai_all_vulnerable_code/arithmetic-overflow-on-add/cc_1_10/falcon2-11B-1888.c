//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_KEY_LENGTH 20

int main() {
    char file_name[MAX_FILE_NAME_LENGTH] = "input.txt";
    char key[MAX_KEY_LENGTH] = "mysecretkey";
    char cipher_text[MAX_FILE_NAME_LENGTH];
    int file_size = 0;

    // Open the input file and read its contents
    FILE *input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    rewind(input_file);

    // Read the input file contents into a buffer
    char buffer[file_size + 1];
    fread(buffer, sizeof(char), file_size, input_file);
    buffer[file_size] = '\0';

    // Encrypt the input file contents using the key
    int i, j;
    for (i = 0, j = 0; i < strlen(key); i++, j++) {
        cipher_text[j] = buffer[i];
    }

    // Write the cipher text to a new file
    char output_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(output_file_name, file_name);
    strcat(output_file_name, ".encrypted");
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    fwrite(cipher_text, sizeof(char), strlen(cipher_text), output_file);
    fclose(output_file);

    printf("Encrypted file saved as %s.\n", output_file_name);

    return 0;
}