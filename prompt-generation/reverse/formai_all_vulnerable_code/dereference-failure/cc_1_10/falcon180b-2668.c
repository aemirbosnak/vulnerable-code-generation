//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 20
#define MAX_FILE_SIZE 1000000

void encrypt(FILE *fp, char *key) {
    int key_size = strlen(key);
    char buffer[MAX_FILE_SIZE];
    char *p = buffer;
    char *q = buffer;
    int i = 0;

    while (fgets(buffer, MAX_FILE_SIZE, fp)!= NULL) {
        for (i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i])) {
                *p++ = tolower(buffer[i]) ^ key[i % key_size];
            } else {
                *p++ = buffer[i];
            }
        }
        *p = '\0';
        fputs(buffer, fp);
    }
}

void decrypt(FILE *fp, char *key) {
    int key_size = strlen(key);
    char buffer[MAX_FILE_SIZE];
    char *p = buffer;
    char *q = buffer;
    int i = 0;

    while (fgets(buffer, MAX_FILE_SIZE, fp)!= NULL) {
        for (i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i])) {
                *p++ = toupper(buffer[i] ^ key[i % key_size]);
            } else {
                *p++ = buffer[i];
            }
        }
        *p = '\0';
        fputs(buffer, fp);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <mode> <key> <filename>\n", argv[0]);
        return 1;
    }

    char mode = argv[1][0];
    char *key = argv[2];
    char *filename = argv[3];

    FILE *fp = fopen(filename, "r+b");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    if (mode == 'e' || mode == 'E') {
        encrypt(fp, key);
    } else if (mode == 'd' || mode == 'D') {
        decrypt(fp, key);
    } else {
        printf("Invalid mode\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}