//FormAI DATASET v1.0 Category: File Encyptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define KEY 5

int encrypt(char *filename);
int decrypt(char *filename);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    int choice;
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: encrypt(filename); break;
        case 2: decrypt(filename); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}

int encrypt(char *filename) {
    FILE *fp1 = fopen(filename, "rb");
    if(fp1 == NULL) {
        printf("Unable to open file %s\n", filename);
        return -1;
    }
    char enc_filename[MAX_FILENAME_LENGTH] = "enc_";
    strcat(enc_filename, filename);
    FILE *fp2 = fopen(enc_filename, "wb");
    if(fp2 == NULL) {
        printf("Unable to create encrypted file!\n");
        fclose(fp1);
        return -1;
    }
    char c;
    while((c = fgetc(fp1)) != EOF) {
        c = c + KEY;
        fputc(c, fp2);
    }
    printf("File encrypted successfully!\nEncrypted filename: %s\n", enc_filename);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

int decrypt(char *filename) {
    char dec_filename[MAX_FILENAME_LENGTH] = "dec_";
    strcat(dec_filename, filename);
    FILE *fp1 = fopen(filename, "rb");
    if(fp1 == NULL) {
        printf("Unable to open file %s\n", filename);
        return -1;
    }
    FILE *fp2 = fopen(dec_filename, "wb");
    if(fp2 == NULL) {
        printf("Unable to create decrypted file!\n");
        fclose(fp1);
        return -1;
    }
    char c;
    while((c = fgetc(fp1)) != EOF) {
        c = c - KEY;
        fputc(c, fp2);
    }
    printf("File decrypted successfully!\nDecrypted filename: %s\n", dec_filename);
    fclose(fp1);
    fclose(fp2);
    return 0;
}