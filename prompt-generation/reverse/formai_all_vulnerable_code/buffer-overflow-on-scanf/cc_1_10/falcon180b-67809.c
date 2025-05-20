//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to be encrypted

// Function to generate a random key
void generate_key(char* key) {
    const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key_length = rand() % 20 + 10; // Key length between 10 and 29 characters
    for (int i = 0; i < key_length; i++) {
        key[i] = alphanum[rand() % strlen(alphanum)];
    }
    key[key_length] = '\0';
}

// Function to encrypt the file
void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char buffer[MAX_FILE_SIZE];
    int buffer_size;
    while ((buffer_size = fread(buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'A' + rand() % 26) % 26 + 'A';
            } else if (isdigit(c)) {
                c = (c - '0' + rand() % 10) % 10 + '0';
            }
            c = (c + key[i % strlen(key)]) % 36;
            fwrite(&c, 1, 1, output_file);
        }
    }
}

int main() {
    srand(time(0));
    char input_file_name[100];
    char output_file_name[100];
    char key[30];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);
    generate_key(key);
    FILE* input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }
    encrypt_file(input_file, output_file, key);
    fclose(input_file);
    fclose(output_file);
    printf("File encryption completed successfully.\n");
    return 0;
}