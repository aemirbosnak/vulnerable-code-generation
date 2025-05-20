//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

void encrypt(char *file_name, char *output_file) {
    FILE *input_file, *output_file_ptr;
    char ch;
    int i = 0;

    input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    output_file_ptr = fopen(output_file, "wb");
    if (output_file_ptr == NULL) {
        printf("Error: Unable to create output file.\n");
        fclose(input_file);
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        ch = ch ^ KEY[i];
        fputc(ch, output_file_ptr);
        i = (i + 1) % strlen(KEY);
    }

    fclose(input_file);
    fclose(output_file_ptr);
}

void decrypt(char *file_name, char *output_file) {
    FILE *input_file, *output_file_ptr;
    char ch;
    int i = 0;

    input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    output_file_ptr = fopen(output_file, "wb");
    if (output_file_ptr == NULL) {
        printf("Error: Unable to create output file.\n");
        fclose(input_file);
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        ch = ch ^ KEY[i];
        fputc(ch, output_file_ptr);
        i = (i + 1) % strlen(KEY);
    }

    fclose(input_file);
    fclose(output_file_ptr);
}

int main() {
    char file_name[50], output_file[50];

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", file_name);

    strcpy(output_file, file_name);
    strcat(output_file, ".enc");

    encrypt(file_name, output_file);
    printf("File encrypted successfully.\n");

    printf("Enter the name of the encrypted file to be decrypted: ");
    scanf("%s", file_name);

    strcpy(output_file, file_name);
    strcat(output_file, ".dec");

    decrypt(file_name, output_file);
    printf("File decrypted successfully.\n");

    return 0;
}