//FormAI DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* filename, char* key) {
    FILE *fp;
    fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        c ^= key[i];
        fseek(fp, -1, SEEK_CUR);
        fputc(c, fp);
        fseek(fp, 0, SEEK_CUR);
        i++;
        if (key[i] == '\0') {
            i = 0;
        }
    }
    fclose(fp);
}

void decrypt(char* filename, char* key) {
    FILE *fp;
    fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        c ^= key[i];
        fseek(fp, -1, SEEK_CUR);
        fputc(c, fp);
        fseek(fp, 0, SEEK_CUR);
        i++;
        if (key[i] == '\0') {
            i = 0;
        }
    }
    fclose(fp);
}

int main() {
    char filename[100];
    char key[100];

    printf("Enter Filename: ");
    scanf("%s", filename);

    printf("\nEnter Key: ");
    scanf("%s", key);

    encrypt(filename, key);
    printf("\nFile Encrypted Successfully!\n");

    decrypt(filename, key);
    printf("\nFile Decrypted Successfully!\n");

    return 0;
}