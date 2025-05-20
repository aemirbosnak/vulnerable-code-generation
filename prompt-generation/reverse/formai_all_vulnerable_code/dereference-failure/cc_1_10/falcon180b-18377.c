//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_NAME 256
#define MAX_FILE_SIZE 1000000

int main(int argc, char *argv[]) {
    char key[MAX_KEY_SIZE];
    char file_name[MAX_FILE_NAME];
    char file_buffer[MAX_FILE_SIZE];
    FILE *fp;
    int file_size;
    int i;

    // Prompt user for key
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0';

    // Prompt user for file name
    printf("Enter file name to encrypt: ");
    fgets(file_name, MAX_FILE_NAME, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';

    // Open input file
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Read file into buffer
    fread(file_buffer, 1, file_size, fp);

    // Encrypt file
    for (i = 0; i < file_size; i++) {
        file_buffer[i] ^= key[i % MAX_KEY_SIZE];
    }

    // Write encrypted file to output
    char output_file_name[MAX_FILE_NAME];
    strcpy(output_file_name, file_name);
    strcat(output_file_name, ".enc");
    fp = fopen(output_file_name, "wb");
    if (fp == NULL) {
        printf("Error: Could not create output file\n");
        return 1;
    }
    fwrite(file_buffer, 1, file_size, fp);
    fclose(fp);

    printf("File encrypted successfully\n");
    return 0;
}