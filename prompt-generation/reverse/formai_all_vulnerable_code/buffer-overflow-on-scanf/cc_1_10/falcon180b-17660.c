//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

void generate_key(char *key, int key_length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < key_length; i++) {
        int random_index = rand() % strlen(charset);
        key[i] = charset[random_index];
    }
    key[key_length] = '\0';
}

void encrypt_file(char *file_name, char *key) {
    FILE *input_file = fopen(file_name, "rb");
    FILE *output_file = fopen("encrypted.txt", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file(s).\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char encrypted_line[MAX_LINE_LENGTH];
        for (int i = 0; i < strlen(line); i++) {
            char c = line[i];
            int key_index = c - 'A';
            if (isalpha(c)) {
                key_index = (key_index + rand() % 26) % 26;
            }
            encrypted_line[i] = (char) (c + key_index);
        }
        encrypted_line[strlen(line)] = '\0';
        fputs(encrypted_line, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter the file name to encrypt: ");
    scanf("%s", file_name);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    if (strlen(key)!= 26) {
        printf("Error: Key must be 26 characters long.\n");
        exit(1);
    }

    encrypt_file(file_name, key);

    printf("File encrypted successfully!\n");

    return 0;
}