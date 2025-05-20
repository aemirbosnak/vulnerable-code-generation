//FormAI DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_file(char *filename, int key) {
    FILE *fp, *fp_out;
    char out_filename[100], ch;
    int length;

    // Open the input file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Unable to open file '%s'\n", filename);
        return;
    }

    // Create the output file name by adding "_encrypted" to the input file name
    strcpy(out_filename, filename);
    length = strlen(out_filename);
    out_filename[length - 4] = '\0';
    strcat(out_filename, "_encrypted.txt");

    // Open the output file
    fp_out = fopen(out_filename, "wb");
    if (fp_out == NULL) {
        printf("Unable to create output file '%s'\n", out_filename);
        fclose(fp);
        return;
    }

    // Read each character of the input file and encrypt it
    while ((ch = fgetc(fp)) != EOF) {
        ch += key;
        fputc(ch, fp_out);
    }

    printf("File '%s' encrypted successfully! Encrypted file saved as '%s'\n", filename, out_filename);

    // Close the files
    fclose(fp);
    fclose(fp_out);
}

int main() {
    char filename[100];
    int key;

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", filename);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt_file(filename, key);

    return 0;
}