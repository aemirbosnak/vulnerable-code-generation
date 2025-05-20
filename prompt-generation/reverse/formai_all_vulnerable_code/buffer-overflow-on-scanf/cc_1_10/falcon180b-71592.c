//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 16
#define MAX_FILE_NAME_LEN 64

typedef struct {
    char key[MAX_KEY_LEN];
    int key_len;
    FILE *fp;
} Romeo;

void init_key(Romeo *r) {
    printf("Enter encryption key: ");
    fgets(r->key, MAX_KEY_LEN, stdin);
    r->key_len = strlen(r->key);
}

int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void encrypt_file(Romeo *r) {
    char line[MAX_FILE_NAME_LEN];
    char *filename = "encrypted.txt";
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "%s\n", r->key);

    while (fgets(line, MAX_FILE_NAME_LEN, r->fp)!= NULL) {
        char *p = line;
        while (*p!= '\n') {
            if (is_alpha(*p)) {
                *p = tolower(*p);
                if (*p == 'j') {
                    *p = 'r';
                } else if (*p == 'r') {
                    *p = 'j';
                }
            }
            p++;
        }
        fprintf(fp, "%s", line);
    }

    fclose(r->fp);
    fclose(fp);
    printf("File encrypted successfully.\n");
}

int main() {
    Romeo r;
    init_key(&r);
    printf("Enter file name: ");
    scanf("%s", r.key);
    strcat(r.key, ".txt");
    r.fp = fopen(r.key, "r");

    if (r.fp == NULL) {
        printf("Error opening file %s\n", r.key);
        exit(1);
    }

    encrypt_file(&r);

    return 0;
}