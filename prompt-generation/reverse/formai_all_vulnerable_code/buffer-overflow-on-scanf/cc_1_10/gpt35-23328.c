//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000

void encrypt(char* file_name);
void decrypt(char* file_name);

int main(void) {
    char file_name[MAX_INPUT];
    int mode;
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter 1 for encryption or 2 for decryption: ");
    scanf("%d", &mode);
    if (mode == 1) {
        encrypt(file_name);
        printf("Encryption complete.\n");
    } else if (mode == 2) {
        decrypt(file_name);
        printf("Decryption complete.\n");
    } else {
        printf("Invalid mode selected.\n");
    }
    return 0;
}

void encrypt(char* file_name) {
    FILE* file_in = fopen(file_name, "r");
    FILE* file_out = fopen("encrypted.txt", "w");
    int key = 3;
    char ch;
    while ((ch = fgetc(file_in)) != EOF) {
        // Encryption algorithm - shift by key places
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A') + key) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a') + key) % 26 + 'a';
        }
        fputc(ch, file_out);
    }
    fclose(file_in);
    fclose(file_out);
}

void decrypt(char* file_name) {
    FILE* file_in = fopen(file_name, "r");
    FILE* file_out = fopen("decrypted.txt", "w");
    int key = 3;
    char ch;
    while ((ch = fgetc(file_in)) != EOF) {
        // Decryption algorithm - shift by key places
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A') - key + 26) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a') - key + 26) % 26 + 'a';
        }
        fputc(ch, file_out);
    }
    fclose(file_in);
    fclose(file_out);
}