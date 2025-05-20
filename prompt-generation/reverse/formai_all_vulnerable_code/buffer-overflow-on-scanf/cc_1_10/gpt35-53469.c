//FormAI DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void encrypt(char *str, int key) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Shift the character by key positions
            str[i] = (((str[i] + key) - 'a') % 26) + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            // Shift the character by key positions
            str[i] = (((str[i] + key) - 'A') % 26) + 'A';
        }
    }
}

void decrypt(char *str, int key) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Shift the character back by key positions
            str[i] = (((str[i] - key) - 'a' + 26) % 26) + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            // Shift the character back by key positions
            str[i] = (((str[i] - key) - 'A' + 26) % 26) + 'A';
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    int key;

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    printf("Enter a key: ");
    scanf("%d", &key);

    printf("Original string: %s\n", input);

    encrypt(input, key);
    printf("Encrypted string: %s\n", input);

    decrypt(input, key);
    printf("Decrypted string: %s\n", input);

    return 0;
}