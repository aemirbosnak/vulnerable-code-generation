//FormAI DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

void encrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' + key) % 26) + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' + key) % 26) + 'A';
        } else if (str[i] >= '0' && str[i] <= '9') {
            str[i] = ((str[i] - '0' + key) % 10) + '0';
        } else {
            // ignore non-alphanumeric characters
        }
    }
}

void decrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' - key + 26) % 26) + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' - key + 26) % 26) + 'A';
        } else if (str[i] >= '0' && str[i] <= '9') {
            str[i] = ((str[i] - '0' - key + 10) % 10) + '0';
        } else {
            // ignore non-alphanumeric characters
        }
    }
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character

    int key;
    printf("Enter a key (integer): ");
    scanf("%d", &key);

    encrypt(str, key);
    printf("Encrypted string: %s\n", str);

    decrypt(str, key);
    printf("Decrypted string: %s\n", str);

    return 0;
}