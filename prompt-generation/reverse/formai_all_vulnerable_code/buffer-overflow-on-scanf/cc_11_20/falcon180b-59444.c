//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main() {
    int i, j;
    char str[SIZE];
    char key[SIZE];
    char *p;
    int key_size = rand() % (SIZE - 1) + 1;
    printf("Enter the message to be encrypted: ");
    scanf("%s", str);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encryption process
    for (i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
    for (i = 0; i < strlen(str); i++) {
        for (j = 0; j < strlen(key); j++) {
            if (str[i] == key[j]) {
                str[i] = '*';
                break;
            }
        }
    }
    for (i = 0; i < strlen(str); i++) {
        if (str[i]!= '*') {
            str[i] = toupper(str[i] - 65 + key_size % 26 + 65);
        }
    }

    // Decryption process
    for (i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
    p = strchr(key, str[0]);
    key_size = p - key;
    for (i = 0; i < strlen(str); i++) {
        for (j = 0; j < strlen(key); j++) {
            if (str[i] == key[j]) {
                str[i] = '*';
                break;
            }
        }
    }
    for (i = 0; i < strlen(str); i++) {
        if (str[i]!= '*') {
            str[i] = toupper(str[i] - 65 - key_size % 26 + 65);
        }
    }

    printf("Encrypted message: %s\n", str);
    printf("Decrypted message: %s\n", str);

    return 0;
}