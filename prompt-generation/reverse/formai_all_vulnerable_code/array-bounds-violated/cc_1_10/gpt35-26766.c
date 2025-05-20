//FormAI DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH 100
#define MAX_INPUT_LENGTH 1000

void encrypt(char *input, char *key) {  // function to encrypt the input string with a given key
    int input_len = strlen(input);
    int key_len = strlen(key);
    int key_index = 0;

    for(int i = 0; i < input_len; i++) {
        input[i] = input[i] ^ key[key_index];  // bitwise XOR between the input character and the key character
        key_index = (key_index + 1) % key_len;  // move to the next character in the key
    }
}

void encrypt_file(char *file_path, char *key) {  // function to encrypt the contents of a file with a given key
    FILE *file_ptr;
    char input[MAX_INPUT_LENGTH];

    file_ptr = fopen(file_path, "r+");

    if(file_ptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while(fgets(input, MAX_INPUT_LENGTH, file_ptr) != NULL) {
        encrypt(input, key);  // encrypt each line of the file
        fseek(file_ptr, -strlen(input), SEEK_CUR);  // move the file pointer back to the beginning of the line
        fputs(input, file_ptr);  // write the encrypted line back to the file
    }

    fclose(file_ptr);

    printf("File encrypted successfully!\n");
}

int main() {
    char file_path[MAX_FILE_PATH], key[MAX_INPUT_LENGTH];

    printf("Enter the file path: ");
    fgets(file_path, MAX_FILE_PATH, stdin);

    // remove trailing newline character from the file path
    if(file_path[strlen(file_path) - 1] == '\n') {
        file_path[strlen(file_path) - 1] = '\0';
    }

    printf("Enter the encryption key: ");
    fgets(key, MAX_INPUT_LENGTH, stdin);

    // remove trailing newline character from the key
    if(key[strlen(key) - 1] == '\n') {
        key[strlen(key) - 1] = '\0';
    }

    encrypt_file(file_path, key);

    return 0;
}