//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

void encrypt(char *file_name, char *output_file) {
    FILE *input_file, *output_file_ptr;
    char buffer[BLOCK_SIZE];
    int i, j, k;

    input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: File %s not found.\n", file_name);
        exit(1);
    }

    output_file_ptr = fopen(output_file, "wb");
    if (output_file_ptr == NULL) {
        printf("Error: Failed to create output file %s.\n", output_file);
        exit(1);
    }

    srand(time(NULL));
    for (i = 0; i < strlen(KEY); i++) {
        KEY[i] = KEY[i] ^ rand() % 26 + 'A';
    }

    while (fread(buffer, 1, BLOCK_SIZE, input_file)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = buffer[i] ^ KEY[i % strlen(KEY)];
        }
        fwrite(buffer, 1, BLOCK_SIZE, output_file_ptr);
    }

    fclose(input_file);
    fclose(output_file_ptr);
}

int main() {
    char file_name[100], output_file[100];

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", file_name);

    printf("Enter the name of the encrypted file: ");
    scanf("%s", output_file);

    encrypt(file_name, output_file);

    printf("File %s has been successfully encrypted and saved as %s.\n", file_name, output_file);

    return 0;
}