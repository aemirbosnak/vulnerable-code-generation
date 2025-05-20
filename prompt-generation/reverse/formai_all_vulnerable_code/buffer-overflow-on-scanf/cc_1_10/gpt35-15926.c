//FormAI DATASET v1.0 Category: File Encyptor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// Function to encrypt a character using Caesar Cipher with a given shift key
char encrypt_char(char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        return 'a' + ((c - 'a' + shift) % 26);
    } else if (c >= 'A' && c <= 'Z') {
        return 'A' + ((c - 'A' + shift) % 26);
    } else {
        return c;
    }
}

// Function to encrypt a given file with a given shift key and write the output to a new file
void encrypt_file(char* input_filename, char* output_filename, int shift) {
    FILE* input_file = fopen(input_filename, "r");
    FILE* output_file = fopen(output_filename, "w");
    char buffer[MAX_BUFFER_SIZE];

    if (input_file == NULL) {
        printf("Error: Input file not found!\n");
        exit(1);
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, input_file) != NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            fprintf(output_file, "%c", encrypt_char(buffer[i], shift));
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    int shift;

    // Get input file name from user
    printf("Enter input file name: ");
    fgets(input_filename, MAX_FILENAME_LENGTH, stdin);
    input_filename[strcspn(input_filename, "\n")] = 0;

    // Get output file name from user
    printf("Enter output file name: ");
    fgets(output_filename, MAX_FILENAME_LENGTH, stdin);
    output_filename[strcspn(output_filename, "\n")] = 0;

    // Get shift key from user
    printf("Enter shift key: ");
    scanf("%d", &shift);

    // Encrypt the input file and write the result to the output file
    encrypt_file(input_filename, output_filename, shift);

    printf("File encrypted successfully!\n");

    return 0;
}