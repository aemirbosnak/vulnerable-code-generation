//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define KEY 7 //Encryption key

void encrypt(char *file_name) {
    FILE *fp;
    char ch;

    fp = fopen(file_name, "r+");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", file_name);
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        ch = ch + KEY;
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
    }

    fclose(fp);
}

void decrypt(char *file_name) {
    FILE *fp;
    char ch;

    fp = fopen(file_name, "r+");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", file_name);
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        ch = ch - KEY;
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
    }

    fclose(fp);
}

int main() {
    char file_name[20];
    int choice;

    printf("█▀▀ █░█ █▀█ █▀▀ ░█▀▀█ █░░█ █▀▄▀█   █▀▀▀ ░▀░ █████ ▄▀▀▄ ▄▀▄\n");
    printf("█░░ █░█ █▀▀ ██▄ ░█▄▄█ █▄█▄█ █░▀░█   █░▀█ ▀█▀ █████ █▀▄░ █░█\n");
    printf("▀▀▀ ░▀░ ▀▀▀ █▄▄ ░█░▒█ ▄▀░▀▄ ▀░░░▀   ▀▀▀▀ ▀▀▀ ▀▀▀▀ ▀▀▀░ ▀▀░\n");

    printf("\n 1. Encrypt a file\n 2. Decrypt a file\n 3. Exit\n");
    printf(" Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n Enter the file name to encrypt: ");
            scanf("%s", file_name);
            encrypt(file_name);
            printf("\n File successfully encrypted.\n");
            break;
        case 2:
            printf("\n Enter the file name to decrypt: ");
            scanf("%s", file_name);
            decrypt(file_name);
            printf("\n File successfully decrypted.\n");
            break;
        case 3:
            printf("\n Thank you for using our program. Good bye!\n");
            break;
        default:
            printf("\n Invalid choice.\n");
    }

    return 0;
}