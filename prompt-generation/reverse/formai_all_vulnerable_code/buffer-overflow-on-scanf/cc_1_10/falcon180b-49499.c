//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000

// Function to encrypt the file
void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char ch;
    int key_index = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = ch + key[key_index % strlen(key)];
            key_index++;
        }
        fputc(ch, output_file);
    }
}

int main() {
    char input_file_name[MAX_FILE_NAME_LENGTH];
    char output_file_name[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get input file name
    printf("Enter the input file name: ");
    scanf("%s", input_file_name);

    // Get output file name
    printf("Enter the output file name: ");
    scanf("%s", output_file_name);

    // Get encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Open input file for reading
    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Open output file for writing
    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    // Encrypt the file
    encrypt_file(input_file, output_file, key);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
    return 0;
}