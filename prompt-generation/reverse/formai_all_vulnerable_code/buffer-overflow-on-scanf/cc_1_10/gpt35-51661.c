//FormAI DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

const char* key = "secretkey"; // Store encryption key

// encrypt the file using XOR method
void encrypt_file(FILE* fp) {
    unsigned char byte;
    int i = 0;
    while (fread(&byte, sizeof(unsigned char), 1, fp) > 0) {
        byte = byte ^ key[i % 8]; // XOR with key byte
        fseek(fp, -1, SEEK_CUR); // go back one position
        fwrite(&byte, sizeof(unsigned char), 1, fp); // write to the same position
        i++;
    }
}

// decrypt the file using XOR method
void decrypt_file(FILE* fp) {
    unsigned char byte;
    int i = 0;
    while (fread(&byte, sizeof(unsigned char), 1, fp) > 0) {
        byte = byte ^ key[i % 8]; // XOR with key byte
        fseek(fp, -1, SEEK_CUR); // go back one position
        fwrite(&byte, sizeof(unsigned char), 1, fp); // write to the same position
        i++;
    }
}

int main() {
    char file_name[100];
    int choice;
    FILE *fp;
    printf("Enter the file name: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "r+");
    if (fp == NULL) {
        printf("Cannot open the file.\n");
        exit(0);
    }
    while (1) {
        printf("Choose the operation you want to perform:\n1. Encrypt file\n2. Decrypt file\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                encrypt_file(fp); // call encrypt function
                printf("File encrypted successfully!\n");
                break;
            case 2:
                decrypt_file(fp); // call decrypt function
                printf("File decrypted successfully!\n");
                break;
            case 3:
                fclose(fp); // close the file
                exit(0); // exit program
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}