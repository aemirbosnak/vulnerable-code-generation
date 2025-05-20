//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "secret key"

/* Function to encrypt a file */
void encrypt_file(FILE* input_file, FILE* output_file) {
    char ch;
    int i = 0;

    while ((ch = fgetc(input_file))!= EOF) {
        ch ^= KEY[i];
        fputc(ch, output_file);
        i++;
        if (i == strlen(KEY)) {
            i = 0;
        }
    }
}

/* Function to decrypt a file */
void decrypt_file(FILE* input_file, FILE* output_file) {
    char ch;
    int i = 0;

    while ((ch = fgetc(input_file))!= EOF) {
        ch ^= KEY[i];
        fputc(ch, output_file);
        i++;
        if (i == strlen(KEY)) {
            i = 0;
        }
    }
}

/* Function to get the size of a file */
long get_file_size(FILE* file) {
    long current_pos = ftell(file);
    long size = 0;

    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, current_pos, SEEK_SET);

    return size;
}

int main() {
    FILE* input_file;
    FILE* output_file;
    char input_filename[100];
    char output_filename[100];
    long file_size;

    /* Get the input file name from the user */
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    /* Open the input file for reading */
    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    /* Get the output file name from the user */
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    /* Open the output file for writing */
    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(input_file);
        exit(1);
    }

    /* Get the size of the input file */
    file_size = get_file_size(input_file);

    /* Encrypt the input file and write the encrypted data to the output file */
    printf("Encrypting file...\n");
    encrypt_file(input_file, output_file);

    /* Close the input and output files */
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}