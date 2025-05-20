//FormAI DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 255

int main()
{
    char fname[MAX_LEN];
    printf("Enter the name of the file to encrypt: ");
    fgets(fname, sizeof(fname), stdin);

    // Removing the newline character from the input
    int len = strlen(fname);
    if (fname[len-1] == '\n') {
        fname[len-1] = '\0';
    }

    FILE *fp;
    fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    // Creating a new file to write the encrypted data
    char enc_fname[MAX_LEN];
    sprintf(enc_fname, "%s_encrypted", fname);
    FILE *enc_fp;
    enc_fp = fopen(enc_fname, "wb");

    // Generating the encryption key
    char key[MAX_LEN];
    int key_len;
    printf("Enter the encryption key (maximum length %d): ", MAX_LEN);
    fgets(key, sizeof(key), stdin);
    key_len = strlen(key);
    if (key[key_len-1] == '\n') {
        key[key_len-1] = '\0';
    }

    // Encrypting the file
    int ch;
    int i = 0;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ key[i], enc_fp);
        i++;
        if (i == key_len) {
            i = 0;
        }
    }

    printf("File encrypted successfully! Encrypted file: %s\n", enc_fname);

    fclose(fp);
    fclose(enc_fp);

    return 0;
}