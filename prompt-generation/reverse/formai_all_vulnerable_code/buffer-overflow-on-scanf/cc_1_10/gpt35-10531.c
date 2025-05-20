//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c += key % 26;
            if (c > 'z') {
                c -= 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            c += key % 26;
            if (c > 'Z') {
                c -= 26;
            }
        }
        str[i] = c;
    }
}

void decipher(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c -= key % 26;
            if (c < 'a') {
                c += 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            c -= key % 26;
            if (c < 'A') {
                c += 26;
            }
        }
        str[i] = c;
    }
}

int main() {
    char str[256];
    int key;
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    cipher(str, key);
    printf("Encrypted string: %s\n", str);
    decipher(str, key);
    printf("Decrypted string: %s\n", str);
    return 0;
}