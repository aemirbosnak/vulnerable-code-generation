//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_SIZE 100

typedef struct {
    char *key;
    int keylen;
    char *filename;
} FileEncryptor;

void generate_key(char *key, int keylen) {
    int i;
    for(i=0; i<keylen; i++) {
        key[i] = rand()%26 + 'a';
    }
    key[keylen] = '\0';
}

void encrypt_file(FILE *fpin, FILE *fpout, char *key) {
    int c;
    while((c = fgetc(fpin))!= EOF) {
        if(isalpha(c)) {
            if(isupper(c)) {
                c = (c - 'A' + 13) % 26 + 'A';
            } else {
                c = (c - 'a' + 13) % 26 + 'a';
            }
        }
        fputc(c, fpout);
    }
}

void decrypt_file(FILE *fpin, FILE *fpout, char *key) {
    int c;
    while((c = fgetc(fpin))!= EOF) {
        if(isalpha(c)) {
            if(isupper(c)) {
                c = (c - 'A' - 13 + 26) % 26 + 'A';
            } else {
                c = (c - 'a' - 13 + 26) % 26 + 'a';
            }
        }
        fputc(c, fpout);
    }
}

int main() {
    system("mkdir encrypted_files");
    int i, j;
    FileEncryptor encryptor;
    char filename[MAX_SIZE];
    for(i=0; i<5; i++) {
        printf("Enter filename %d: ", i+1);
        scanf("%s", filename);
        encryptor.filename = filename;
        generate_key(encryptor.key, strlen(filename));
        encryptor.keylen = strlen(encryptor.key);
        system(sprintf("cp %s encrypted_files/%s", filename, filename));
        system(sprintf("cat encrypted_files/%s | openssl enc -aes-256-cbc -k '%s' > encrypted_files/%s.aes", filename, encryptor.key, filename));
        printf("\n%s encrypted successfully!\n", filename);
        fflush(stdout);
    }
    return 0;
}