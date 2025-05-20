//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_NAME_SIZE 100

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    char encrypted_file_name[MAX_FILE_NAME_SIZE];
    char key[MAX_KEY_SIZE];
} FileInfo;

void generate_key(char *key) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;

    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }

    key[MAX_KEY_SIZE - 1] = '\0';
}

int main() {
    int num_files, i;
    char file_name[MAX_FILE_NAME_SIZE];
    char encrypted_file_name[MAX_FILE_NAME_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter the number of files to encrypt: ");
    scanf("%d", &num_files);

    printf("Enter the file names to encrypt:\n");
    for (i = 0; i < num_files; i++) {
        scanf("%s", file_name);

        strcpy(encrypted_file_name, file_name);
        generate_key(key);

        int j;
        for (j = 0; j < strlen(encrypted_file_name); j++) {
            encrypted_file_name[j] = encrypted_file_name[j] ^ key[j % MAX_KEY_SIZE];
        }

        printf("Encrypted file name: %s\n", encrypted_file_name);
    }

    return 0;
}