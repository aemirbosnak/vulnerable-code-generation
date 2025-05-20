//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt_file(char *file_path, char *key) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Could not open the file!\n");
        return;
    }

    char output_file[strlen(file_path) + 10]; // Adding space for ".encrypted"
    sprintf(output_file, "%s.encrypted", file_path);
    FILE *encrypted_file = fopen(output_file, "w");

    int key_index = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (!isalpha(ch)) {
            fputc(ch, encrypted_file); // Keep non-alpha characters as-is
            continue;
        }

        int shifted_index = ((tolower(ch) - 'a') + (tolower(key[key_index]) - 'a')) % 26;
        char shifted_ch = shifted_index + 'a';

        // Preserve the case of the original character
        if (isupper(ch)) {
            shifted_ch = toupper(shifted_ch);
        }

        fputc(shifted_ch, encrypted_file);
        key_index++;
        key_index %= strlen(key);
    }

    fclose(file);
    fclose(encrypted_file);
}

int main() {
    char file_path[100];
    printf("Enter the path of the file you want to encrypt: ");
    scanf("%s", file_path);

    char key[20];
    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt_file(file_path, key);
    printf("File encrypted successfully!\n");

    return 0;
}