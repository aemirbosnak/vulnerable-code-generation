//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<openssl/sha.h>
#include<openssl/md5.h>
#define MAX 100000 

void sha256_asynchronous(unsigned char* str, int len, unsigned char* hash) {

    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);
    SHA256_Update(&sha256_ctx, str, len);
    SHA256_Final(hash, &sha256_ctx);
}

void md5_asynchronous(unsigned char* str, int len, unsigned char* hash) {

    MD5_CTX md5_ctx;
    MD5_Init(&md5_ctx);
    MD5_Update(&md5_ctx, str, len);
    MD5_Final(hash, &md5_ctx);
}

void print_hash(unsigned char* hash) {

    printf("Calculated Hash Value : ");

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {

    int n;
    unsigned char str[MAX];
    unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
    unsigned char md5_hash[MD5_DIGEST_LENGTH];
    srand(time(0));
    printf("Enter a number : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        str[i] = (char)(rand() % 26 + 'a');
    }

    printf("String : %s\n", str);
    printf("String length : %d\n", strlen((const char*)str)); 

    sha256_asynchronous(str, strlen((const char*)str), sha256_hash);
    print_hash(sha256_hash);

    md5_asynchronous(str, strlen((const char*)str), md5_hash);
    print_hash(md5_hash);

    return 0;
}