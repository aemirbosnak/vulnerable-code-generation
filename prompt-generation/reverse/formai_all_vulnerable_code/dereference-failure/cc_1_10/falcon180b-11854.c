//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/md5.h>

struct hash {
    char* message;
    unsigned char* digest;
};

struct hash* create_hash(char* message) {
    struct hash* hash = (struct hash*) malloc(sizeof(struct hash));
    hash->message = message;
    hash->digest = (unsigned char*) malloc(MD5_DIGEST_LENGTH);
    MD5((unsigned char*) message, strlen(message), hash->digest);
    return hash;
}

void print_hash(struct hash* hash) {
    int i;
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash->digest[i]);
    }
}

struct hash* generate_hash(char* message) {
    struct hash* hash = create_hash(message);
    printf("Message: %s\n", hash->message);
    printf("Hash: ");
    print_hash(hash);
    printf("\n");
    return hash;
}

int main() {
    srand(time(NULL));
    char* message = (char*) malloc(100);
    int length = rand() % 100;
    int i;
    for (i = 0; i < length; i++) {
        message[i] = rand() % 26 + 'a';
    }
    message[length] = '\0';
    struct hash* hash = generate_hash(message);
    free(message);
    free(hash->digest);
    free(hash);
    return 0;
}