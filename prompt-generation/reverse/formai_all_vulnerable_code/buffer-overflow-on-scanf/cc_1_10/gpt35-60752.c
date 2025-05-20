//FormAI DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *filename, char *key) {
    FILE *fp;
    fp = fopen(filename, "rb+");
    if(fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    int key_size = strlen(key);
    char ch;
    int key_index = 0;
    while((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ key[key_index], fp);
        key_index = (key_index + 1) % key_size;
    }
    fclose(fp);
}

void decrypt(char *filename, char *key) {
    FILE *fp;
    fp = fopen(filename, "rb+");
    if(fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    int key_size = strlen(key);
    char ch;
    int key_index = 0;
    while((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ key[key_index], fp);
        key_index = (key_index + 1) % key_size;
    }
    fclose(fp);
}

int main() {
    char filename[100];
    char key[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(filename, key);
    printf("File encrypted successfully\n");

    printf("Do you want to decrypt the file? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y') {
        decrypt(filename, key);
        printf("File decrypted successfully\n");
    }

    return 0;
}