//Falcon-180B DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256
#define ENCRYPTION_KEY "mysecretkey"
#define KEY_LENGTH (strlen(ENCRYPTION_KEY))

char *encrypt(char *message, char *key) {
    int i, j, k;
    char result[strlen(message)];
    for(i=0, j=0; message[i]!='\0'; i++, j++) {
        if(isalpha(message[i])) {
            result[j] = (char) (((int)message[i] + (int)key[j % KEY_LENGTH]) % 26 + 65);
        } else {
            result[j] = message[i];
        }
    }
    return result;
}

char *decrypt(char *message, char *key) {
    int i, j, k;
    char result[strlen(message)];
    for(i=0, j=0; message[i]!='\0'; i++, j++) {
        if(isalpha(message[i])) {
            k = ((int)message[i] - (int)key[j % KEY_LENGTH] - 65) % 26;
            if(k < 0) {
                k += 26;
            }
            result[j] = (char) k;
        } else {
            result[j] = message[i];
        }
    }
    return result;
}

int main() {
    char message[MAX_CHAR];
    char key[MAX_CHAR];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);
    char *encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);
    char *decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}