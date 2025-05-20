//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size (1 MB)

// Function to encrypt the file contents
void encrypt(char* file_contents) {
    int i = 0;
    while (file_contents[i]) {
        if (isalpha(file_contents[i])) {
            char temp = file_contents[i];
            file_contents[i] = tolower(temp);
        }
        i++;
    }
}

// Function to write the encrypted file contents to a new file
void write_encrypted_file(char* file_name, char* file_contents) {
    FILE* output_file = fopen(file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    fwrite(file_contents, strlen(file_contents), 1, output_file);
    fclose(output_file);
}

int main() {
    char file_name[50];
    char file_contents[MAX_FILE_SIZE];

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", file_name);

    // Open the input file
    FILE* input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read the file contents
    char ch;
    int count = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        file_contents[count++] = ch;
    }
    fclose(input_file);

    // Encrypt the file contents
    encrypt(file_contents);

    // Write the encrypted file contents to a new file
    char encrypted_file_name[50];
    strcpy(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".encrypted");

    write_encrypted_file(encrypted_file_name, file_contents);

    printf("File encrypted successfully!\n");

    return 0;
}