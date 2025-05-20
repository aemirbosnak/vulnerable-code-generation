//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a file
void encrypt_file(FILE *infile, FILE *outfile, char *key) {
    int c, i, j;
    char buffer[1024];

    // Read the input file in chunks
    while ((c = fgetc(infile))!= EOF) {
        // Encrypt the character
        i = (int)c;
        j = 0;
        while (key[j]) {
            i = (i - (int)key[j]) % 26 + 65;
            if (isalpha(i)) {
                fputc(i, outfile);
            }
            j++;
        }
    }

    // Close the input and output files
    fclose(infile);
    fclose(outfile);
}

// Function to decrypt a file
void decrypt_file(FILE *infile, FILE *outfile, char *key) {
    int c, i, j;
    char buffer[1024];

    // Read the input file in chunks
    while ((c = fgetc(infile))!= EOF) {
        // Decrypt the character
        i = (int)c;
        j = 0;
        while (key[j]) {
            i = ((i - 65 + (int)key[j]) % 26) + 65;
            if (isalpha(i)) {
                fputc(i, outfile);
            }
            j++;
        }
    }

    // Close the input and output files
    fclose(infile);
    fclose(outfile);
}

int main() {
    char filename[100], key[100];
    FILE *infile, *outfile;

    // Get the filename and key from the user
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", filename);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Open the input and output files
    infile = fopen(filename, "r");
    if (infile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    outfile = fopen("encrypted.txt", "w");
    if (outfile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Encrypt the file
    encrypt_file(infile, outfile, key);

    // Close the input and output files
    fclose(infile);
    fclose(outfile);

    printf("File encrypted successfully!\n");

    return 0;
}