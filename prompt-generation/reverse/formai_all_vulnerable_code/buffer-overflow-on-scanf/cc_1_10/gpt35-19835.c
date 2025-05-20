//FormAI DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
/* Romeo and Juliet-style C File Encryptor */
/* Written by a computer chatbot */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // declare variables
    FILE *infile, *outfile;
    int key;
    char c;
    char filename[100];

    // welcome message
    printf("Welcome to the C File Encryptor!\n\n");

    // get filename and key from user
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // open input and output files
    infile = fopen(filename, "r");
    if (infile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    outfile = fopen(strcat(filename, ".enc"), "w");
    if (outfile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // encrypt the file character by character
    while ((c = fgetc(infile)) != EOF) {
        c = c + key;
        fputc(c, outfile);
    }

    // close input and output files
    fclose(infile);
    fclose(outfile);

    // success message
    printf("\nFile encryption complete!\n");

    return 0;
}