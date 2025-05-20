//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64

// ROTATE_LEFT rotates x left n bits
#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n)))

// F, G, H and K are basic SHA1 functions
#define F(x, y, z) ((x & y) | ((~x) & z))
#define G(x, y, z) ((x & y) | (x & z) | (y & z))
#define H(x, y, z) (x ^ y ^ z)
#define K 0x5A827999

void sha1_transform(unsigned int *state, unsigned char *buffer)
{
    unsigned int a, b, c, d, e, i, j, t, m[80];

    // initialize hash values
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];

    // copy buffer to M
    for (i = 0, j = 0; i < 16; ++i, j += 4)
        m[i] = (buffer[j] << 24) | (buffer[j + 1] << 16) | (buffer[j + 2] << 8) | (buffer[j + 3]);
    for ( ; i < 80; ++i)
        m[i] = ROTATE_LEFT((m[i-3] ^ m[i-8] ^ m[i-14] ^ m[i-16]), 1);

    // main loop
    for (i = 0; i < 80; ++i)
    {
        if (i < 20)
            t = F(b, c, d) + K;
        else if (i < 40)
            t = G(b, c, d) + 0x6ED9EBA1;
        else if (i < 60)
            t = H(b, c, d) + 0x8F1BBCDC;
        else
            t = G(b, c, d) + 0xCA62C1D6;

        t += ROTATE_LEFT(a, 5) + e + m[i];
        e = d;
        d = c;
        c = ROTATE_LEFT(b, 30);
        b = a;
        a = t;
    }

    // add this chunk's hash to result so far
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
}

void sha1(char *string, char output[41])
{
    unsigned char buffer[BLOCK_SIZE];
    unsigned int state[5] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };
    unsigned int i, j;
    unsigned long long message_length = strlen(string) * 8;

    // loop through the message
    for (i = 0; i < strlen(string); ++i)
    {
        j = (i % BLOCK_SIZE);
        buffer[j] = string[i];
        if ((i > 0) && (i % BLOCK_SIZE == 0))
            sha1_transform(state, buffer);
    }

    // append bit '1' to the message
    buffer[j++] = 0x80;

    // if necessary, append zeros
    if (j > 56)
    {
        while (j < BLOCK_SIZE)
            buffer[j++] = 0x00;
        sha1_transform(state, buffer);
        j = 0;
    }
    while (j < (BLOCK_SIZE - 8))
        buffer[j++] = 0x00;

    // append message length
    for (i = 7; i >= 0; --i)
    {
        buffer[j++] = (message_length >> (i * 8)) & 0xFF;
    }

    // final transformation
    sha1_transform(state, buffer);

    // output hash value
    for (i = 0; i < 5; ++i)
    {
        sprintf(output + i * 8, "%08x", state[i]);
    }
    output[40] = '\0';
}

int main()
{
    char message[1000];
    char output[41];
    printf("Enter a message to hash: ");
    scanf("%[^\n]", message);
    sha1(message, output);
    printf("SHA1 hash of '%s' is: %s\n", message, output);
    return 0;
}