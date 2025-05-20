//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 1000000

int main() {
    char key[MAX_KEY_SIZE];
    char input_file[100];
    char output_file[100];
    char *file_content = NULL;
    size_t file_size = 0;
    int key_size = 0;

    // Get user input for key and file paths
    printf("Enter the path to the input file: ");
    scanf("%s", input_file);
    printf("Enter the path to the output file: ");
    scanf("%s", output_file);

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);
    key_size = strlen(key);

    // Read the contents of the input file
    FILE *fp = fopen(input_file, "rb");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    file_content = (char *) malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Could not allocate memory for file content.\n");
        exit(1);
    }

    fread(file_content, file_size, 1, fp);
    fclose(fp);

    // Encrypt the file content
    for (int i = 0; i < file_size; i++) {
        file_content[i] = file_content[i] ^ key[i % key_size];
    }

    // Write the encrypted content to the output file
    fp = fopen(output_file, "wb");
    if (fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fwrite(file_content, file_size, 1, fp);
    fclose(fp);

    printf("File encrypted and saved to %s.\n", output_file);

    return 0;
}