#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
    int key = 12345;
    int plaintext = 1234;
    int ciphertext = 0;

    ciphertext = encrypt(key, plaintext);

    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);

    return 0;
}

int encrypt(int key, int plaintext)
{
    return (plaintext + key) % 2;
}
