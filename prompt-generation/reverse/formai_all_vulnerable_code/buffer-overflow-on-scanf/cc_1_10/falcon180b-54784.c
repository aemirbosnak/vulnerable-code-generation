//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_KEY_LENGTH 64
#define MAX_FILE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char file_path[MAX_FILE_LENGTH];
} EncryptionParams;

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt_file(EncryptionParams* params) {
    FILE* file = fopen(params->file_path, "r");
    if (file == NULL) {
        printf("Error: file not found\n");
        exit(1);
    }

    char* file_content = malloc(MAX_FILE_LENGTH);
    fread(file_content, 1, MAX_FILE_LENGTH, file);
    fclose(file);

    int file_length = strlen(file_content);
    for (int i = 0; i < file_length; i++) {
        file_content[i] = toupper(file_content[i]);
        file_content[i] = file_content[i] + params->key[i % MAX_KEY_LENGTH];
    }

    FILE* encrypted_file = fopen("encrypted_file.txt", "w");
    fwrite(file_content, 1, file_length, encrypted_file);
    fclose(encrypted_file);

    printf("File encrypted successfully!\n");
}

int main() {
    EncryptionParams params;
    printf("Enter file path: ");
    scanf("%s", params.file_path);

    generate_key(params.key);

    printf("Key generated successfully!\n");
    printf("Do you want to encrypt the file? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y') {
        encrypt_file(&params);
    }

    return 0;
}