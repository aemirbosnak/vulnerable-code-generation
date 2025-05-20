//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
#define ENCRYPT 1
#define DECRYPT 2

// function to encrypt/decrypt the file
void process_file(FILE *fp, int mode) {
    char ch, prev_ch = '\0';
    int count = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (mode == ENCRYPT) {
                if (isupper(ch)) {
                    ch = (ch + 13) % 26 + 'A';
                } else {
                    ch = (ch + 13) % 26 + 'a';
                }
            } else if (mode == DECRYPT) {
                if (isupper(ch)) {
                    ch = (ch - 13) % 26 + 'A';
                } else {
                    ch = (ch - 13) % 26 + 'a';
                }
            }
        }
        if (mode == ENCRYPT && count == 0) {
            prev_ch = ch;
            count++;
        }
        if (mode == DECRYPT && count == 0) {
            prev_ch = ch;
            count++;
        }
        fputc(ch, fp);
    }
    fclose(fp);
}

int main() {
    char filename[SIZE], mode;
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the mode (E for Encrypt or D for Decrypt): ");
    scanf(" %c", &mode);
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    process_file(fp, mode);
    printf("File %s successfully %crypted.\n", filename, mode);
    return 0;
}