//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_SIZE 100000

typedef struct {
    char key[MAX_KEY_SIZE];
    char filename[MAX_FILE_SIZE];
} Encryptor;

Encryptor encryptor;

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            key[i] = tolower(key[i]);
        }
    }
}

void read_file(char *filename) {
    FILE *fp;
    char ch;
    int i = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            encryptor.filename[i++] = ch;
        }
    }

    fclose(fp);
}

void encrypt(char *filename) {
    FILE *fp;
    char ch, key[MAX_KEY_SIZE];

    printf("Enter encryption key: ");
    scanf("%s", key);

    generate_key(key);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    printf("Encrypting %s...\n", filename);

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ch = (ch - 'a' + (int) encryptor.key[0] - 97) % 26 + 'a';
        }

        fprintf(stdout, "%c", ch);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file> <key>\n", argv[0]);
        return 1;
    }

    strcpy(encryptor.filename, argv[1]);

    encrypt(argv[1]);

    return 0;
}