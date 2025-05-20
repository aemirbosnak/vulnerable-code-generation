//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char file_name[100];
    char input_key[100];
    char output_key[100];
    char *file_data;
    char *encrypted_data;
    int file_size;
    int i, j;

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", file_name);

    printf("Enter the encryption key: ");
    scanf("%s", input_key);

    file_data = (char*)malloc(1000000);
    encrypted_data = (char*)malloc(1000000);

    FILE *file = fopen(file_name, "rb");
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    fread(file_data, file_size, 1, file);
    fclose(file);

    for (i = 0; i < strlen(input_key); i++) {
        for (j = i + 1; j < strlen(input_key); j++) {
            if (tolower(input_key[i]) == tolower(input_key[j])) {
                printf("Error: The encryption key must not contain repeating characters.\n");
                exit(1);
            }
        }
    }

    for (i = 0; i < strlen(input_key); i++) {
        output_key[i] = tolower(input_key[i]);
    }

    int key_index = 0;
    for (i = 0; i < file_size; i++) {
        char c = file_data[i];
        if (isalpha(c)) {
            c = tolower(c);
            char k = output_key[key_index % strlen(output_key)];
            if (isalpha(k)) {
                encrypted_data[i] = (c - k + 26) % 26 + 'a';
            } else {
                encrypted_data[i] = c;
            }
        } else {
            encrypted_data[i] = c;
        }
        key_index++;
    }

    FILE *encrypted_file = fopen("encrypted_file.txt", "wb");
    fwrite(encrypted_data, file_size, 1, encrypted_file);
    fclose(encrypted_file);

    printf("File encrypted successfully!\n");

    return 0;
}