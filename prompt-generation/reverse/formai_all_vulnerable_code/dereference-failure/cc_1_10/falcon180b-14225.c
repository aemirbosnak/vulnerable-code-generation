//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 1000
#define KEY_SIZE 16

void generate_key(char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        char c = rand() % 26 + 'a';
        key[i] = toupper(c);
    }
}

void encrypt(char *file_name, char *key) {
    FILE *fp;
    char ch;
    int count = 0;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char *buffer = malloc(MAX_SIZE);
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (ch >= 'A' && ch <= 'Z') {
                ch = 'A' + ((ch - 'A') + count) % 26;
                count = (count + 1) % KEY_SIZE;
            }
        }
        strncat(buffer, &ch, 1);
    }
    fclose(fp);
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s", buffer);
    fclose(fp);
}

void decrypt(char *file_name, char *key) {
    FILE *fp;
    char ch;
    int count = 0;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char *buffer = malloc(MAX_SIZE);
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (ch >= 'A' && ch <= 'Z') {
                ch = 'A' + ((ch - 'A' - count + 26) % 26);
                count = (count - 1 + KEY_SIZE) % KEY_SIZE;
            }
        }
        strncat(buffer, &ch, 1);
    }
    fclose(fp);
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s", buffer);
    fclose(fp);
}

int main() {
    char key[KEY_SIZE];
    generate_key(key);
    char file_name[MAX_SIZE];
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter mode (e/d): ");
    char mode;
    scanf("%c", &mode);
    if (mode == 'e') {
        encrypt(file_name, key);
        printf("File encrypted successfully\n");
    } else if (mode == 'd') {
        decrypt(file_name, key);
        printf("File decrypted successfully\n");
    } else {
        printf("Invalid mode\n");
    }
    return 0;
}