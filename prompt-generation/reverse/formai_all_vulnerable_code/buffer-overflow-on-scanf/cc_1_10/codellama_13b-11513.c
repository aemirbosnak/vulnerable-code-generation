//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: careful
// File Encryptor Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt a file
void encryptFile(char *infile, char *outfile, char *key) {
    // open the input and output files
    FILE *in = fopen(infile, "r");
    FILE *out = fopen(outfile, "w");

    // read the contents of the input file
    char buffer[1024];
    int bytesRead = fread(buffer, 1, sizeof(buffer), in);

    // encrypt the contents of the input file
    for (int i = 0; i < bytesRead; i++) {
        buffer[i] = buffer[i] + key[i % strlen(key)];
    }

    // write the encrypted contents to the output file
    fwrite(buffer, 1, bytesRead, out);

    // close the input and output files
    fclose(in);
    fclose(out);
}

// function to decrypt a file
void decryptFile(char *infile, char *outfile, char *key) {
    // open the input and output files
    FILE *in = fopen(infile, "r");
    FILE *out = fopen(outfile, "w");

    // read the contents of the input file
    char buffer[1024];
    int bytesRead = fread(buffer, 1, sizeof(buffer), in);

    // decrypt the contents of the input file
    for (int i = 0; i < bytesRead; i++) {
        buffer[i] = buffer[i] - key[i % strlen(key)];
    }

    // write the decrypted contents to the output file
    fwrite(buffer, 1, bytesRead, out);

    // close the input and output files
    fclose(in);
    fclose(out);
}

int main() {
    // prompt the user for the input file and key
    char infile[100];
    char outfile[100];
    char key[100];
    printf("Enter the name of the input file: ");
    scanf("%s", infile);
    printf("Enter the name of the output file: ");
    scanf("%s", outfile);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // encrypt the file
    encryptFile(infile, outfile, key);

    // decrypt the file
    decryptFile(outfile, infile, key);

    return 0;
}