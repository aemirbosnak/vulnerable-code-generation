#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *key = "secret";
    char *msg = "Hello, world!";
    int len = strlen(msg) + 1;
    char *enc_msg = malloc(len);

    printf("Original message: %s\n", msg);

    encrypt(key, msg, enc_msg, len);

    printf("Encrypted message: %s\n", enc_msg);

    free(enc_msg);

    return 0;
}

void encrypt(char *key, char *msg, char *enc_msg, int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        enc_msg[i] = msg[i] ^ key[i % strlen(key)];
    }
}
