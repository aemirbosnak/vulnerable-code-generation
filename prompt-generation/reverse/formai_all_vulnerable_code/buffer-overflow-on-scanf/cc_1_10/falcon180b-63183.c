//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPT 1
#define DECRYPT 2

void generate_key(char *key, int key_length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+";
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = chars[rand() % strlen(chars)];
    }
    key[key_length] = '\0';
}

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char input_buffer[4096];
    char output_buffer[4096];
    int input_bytes_read;
    int output_bytes_written;
    int key_index = 0;
    while ((input_bytes_read = fread(input_buffer, 1, sizeof(input_buffer), input_file)) > 0) {
        for (int i = 0; i < input_bytes_read; i++) {
            output_buffer[i] = input_buffer[i] ^ key[key_index % strlen(key)];
            key_index++;
        }
        output_bytes_written = fwrite(output_buffer, 1, input_bytes_read, output_file);
    }
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char input_buffer[4096];
    char output_buffer[4096];
    int input_bytes_read;
    int output_bytes_written;
    int key_index = 0;
    while ((input_bytes_read = fread(input_buffer, 1, sizeof(input_buffer), input_file)) > 0) {
        for (int i = 0; i < input_bytes_read; i++) {
            output_buffer[i] = input_buffer[i] ^ key[key_index % strlen(key)];
            key_index++;
        }
        output_bytes_written = fwrite(output_buffer, 1, input_bytes_read, output_file);
    }
}

int main() {
    char input_file_name[256];
    char output_file_name[256];
    char key[256];
    int mode;
    printf("Enter input file name: ");
    scanf("%s", input_file_name);
    printf("Enter output file name: ");
    scanf("%s", output_file_name);
    printf("Enter mode (1 for encrypt, 2 for decrypt): ");
    scanf("%d", &mode);
    generate_key(key, strlen(key));
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }
    if (mode == ENCRYPT) {
        encrypt_file(input_file, output_file, key);
    } else if (mode == DECRYPT) {
        decrypt_file(input_file, output_file, key);
    } else {
        printf("Invalid mode.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}