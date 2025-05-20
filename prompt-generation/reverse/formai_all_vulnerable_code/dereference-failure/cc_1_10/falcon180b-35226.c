//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_SIZE 1024
#define KEY_FILE "key.txt"

char *get_key() {
    FILE *fp = fopen(KEY_FILE, "r");
    if (fp == NULL) {
        printf("Error: Key file not found.\n");
        exit(1);
    }

    char *key = (char *) malloc(MAX_KEY_SIZE * sizeof(char));
    if (key == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    int key_len = 0;
    int c;
    while ((c = fgetc(fp))!= EOF) {
        if (isalnum(c)) {
            key[key_len++] = c;
        }
    }
    key[key_len] = '\0';

    fclose(fp);
    return key;
}

void encrypt_file(char *filename, char *key) {
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    int file_size = 0;
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    char *buffer = (char *) malloc(file_size * sizeof(char));
    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    int i = 0;
    while (fread(buffer + i, 1, 1, fp)!= 0) {
        i++;
    }

    fclose(fp);

    int key_len = strlen(key);
    for (i = 0; i < file_size; i++) {
        char c = buffer[i];
        if (isalnum(c)) {
            c = (c - 'a' + key_len) % key_len + 'a';
        }
        buffer[i] = c;
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: File write failed.\n");
        exit(1);
    }

    fwrite(buffer, 1, file_size, fp);
    fclose(fp);
}

int main() {
    char *key = get_key();
    char *filename = "test.txt";

    encrypt_file(filename, key);

    printf("File encrypted successfully.\n");
    return 0;
}