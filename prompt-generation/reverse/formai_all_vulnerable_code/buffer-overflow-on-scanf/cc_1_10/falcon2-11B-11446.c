//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1000

int main() {
    char buf[BUF_SIZE];
    FILE *fp;
    char *cipher = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char *decipher = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyz0123456789";

    printf("Enter a file to encrypt: ");
    fgets(buf, BUF_SIZE, stdin);
    fp = fopen(buf, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the length of the key: ");
    int key_len;
    scanf("%d", &key_len);

    if (key_len > BUF_SIZE) {
        printf("Key length cannot be greater than %d.\n", BUF_SIZE);
        return 1;
    }

    char key[key_len];
    fgets(key, key_len, stdin);

    for (int i = 0; i < BUF_SIZE; i++) {
        buf[i] = cipher[buf[i] - 'A'];
    }

    printf("Encrypted file:\n");
    for (int i = 0; i < BUF_SIZE; i++) {
        printf("%c", buf[i]);
    }
    fclose(fp);

    fp = fopen(buf, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < BUF_SIZE; i++) {
        fp = fputc(decipher[buf[i] - 'A'], fp);
    }
    fclose(fp);

    return 0;
}