//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

void encrypt(char* message, char* key) {
    int i, j, k;
    char encrypted[100];
    strcpy(encrypted, message);

    for (i = 0, j = 0; encrypted[i]!= '\0'; i++, j++) {
        if (j % strlen(key) == 0) {
            k = encrypted[i] + (int)key[j % strlen(key)] - 65;
            if (k > 90) {
                k -= 26;
            }
            if (k < 65) {
                k += 26;
            }
            encrypted[i] = (char)k;
        }
    }

    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char* message, char* key) {
    int i, j, k;
    char decrypted[100];
    strcpy(decrypted, message);

    for (i = 0, j = 0; decrypted[i]!= '\0'; i++, j++) {
        if (j % strlen(key) == 0) {
            k = (int)decrypted[i] - (int)key[j % strlen(key)] - 65;
            if (k < 0) {
                k += 26;
            }
            if (k > 25) {
                k -= 26;
            }
            decrypted[i] = (char)k + 65;
        }
    }

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[100], key[100];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}