//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define KEY_SIZE 16

void encrypt(char *file_name, char *key) {
    FILE *fp;
    char ch;
    int i = 0;

    fp = fopen(file_name, "rb");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        ch = ch ^ key[i];
        fputc(ch, fp);
        i = (i + 1) % KEY_SIZE;
    }

    fclose(fp);
}

void decrypt(char *file_name, char *key) {
    FILE *fp;
    char ch;
    int i = 0;

    fp = fopen(file_name, "rb");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        ch = ch ^ key[i];
        fputc(ch, fp);
        i = (i + 1) % KEY_SIZE;
    }

    fclose(fp);
}

int main() {
    char file_name[100];
    char key[KEY_SIZE];

    printf("Enter file name: ");
    scanf("%s", file_name);

    printf("Enter encryption key: ");
    scanf("%s", key);

    printf("Enter 1 for encryption or 2 for decryption: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(file_name, key);
        printf("File encrypted successfully!\n");
    } else if (choice == 2) {
        decrypt(file_name, key);
        printf("File decrypted successfully!\n");
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}