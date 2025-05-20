//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    char message[1000];
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]", message);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, strlen(message));
    SHA256_Final(hash, &sha256);

    printf("Hash of the message is: ");
    for(int i=0; i<SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    char salt[3];
    printf("Enter the salt: ");
    scanf("%2s", salt);

    char pepper[100];
    printf("Enter the pepper: ");
    scanf("%99s", pepper);

    char password[100];
    printf("Enter the password: ");
    scanf("%99s", password);

    char password_salt_pepper[SHA256_DIGEST_LENGTH + 4];
    strcpy(password_salt_pepper, salt);
    strcat(password_salt_pepper, password);
    strcat(password_salt_pepper, pepper);

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password_salt_pepper, strlen(password_salt_pepper));
    SHA256_Final(hash, &sha256);

    printf("Salted and peppered hash of the password is: ");
    for(int i=0; i<SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}