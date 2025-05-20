//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

void encrypt(char *filename);
void decrypt(char *filename);

int main() {
    char filename[100], choice;
    printf("\nWelcome to the File Encryptor!\n\n");
    do {
        printf("Select an option:\n");
        printf("  1. Encrypt a file\n");
        printf("  2. Decrypt a file\n");
        printf("  3. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("\nEnter the filename to encrypt: ");
                scanf("%s", filename);
                encrypt(filename);
                printf("File encrypted successfully!\n");
                break;
            case '2':
                printf("\nEnter the filename to decrypt: ");
                scanf("%s", filename);
                decrypt(filename);
                printf("File decrypted successfully!\n");
                break;
            case '3':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again...\n");
                break;
        }
    } while (choice != '3');
    return 0;
}

void encrypt(char *filename) {
    FILE *fp;
    int i, key;
    char ch;
    srand(time(0));
    key = rand() % 1000;
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Unable to open file for encryption!");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            for (i=0; i<key; i++) {
                if (ch == '9') {
                    ch = '0';
                } else if (ch == 'Z') {
                    ch = 'A';
                } else if (ch == 'z') {
                    ch = 'a';
                } else {
                    ch++;
                }
            }
            fseek(fp, -1, SEEK_CUR);
            fputc(ch, fp);
        }
    }
    fprintf(fp, "%d", key);
    fclose(fp);
}

void decrypt(char *filename) {
    FILE *fp;
    int i, key;
    char ch;
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Unable to open file for decryption!");
        exit(1);
    }
    fseek(fp, -1, SEEK_END);
    fscanf(fp, "%d", &key);
    fseek(fp, 0, SEEK_SET);
    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            for (i=0; i<key; i++) {
                if (ch == '0') {
                    ch = '9';
                } else if (ch == 'A') {
                    ch = 'Z';
                } else if (ch == 'a') {
                    ch = 'z';
                } else {
                    ch--;
                }
            }
            fseek(fp, -1, SEEK_CUR);
            fputc(ch, fp);
        }
    }
    fclose(fp);
}