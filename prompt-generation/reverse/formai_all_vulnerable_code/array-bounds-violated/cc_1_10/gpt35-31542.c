//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) ((x << n) | (x >> (32 - n)))

uint32_t F(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) | (~x & z);
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & z) | (y & ~z);
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z)
{
    return x ^ y ^ z;
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z)
{
    return y ^ (x | ~z);
}

void FF(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac)
{
    *a = ROTL((*a + F(b, c, d) + x + ac), s) + b;
}

void GG(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac)
{
    *a = ROTL((*a + G(b, c, d) + x + ac), s) + b;
}

void HH(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac)
{
    *a = ROTL((*a + H(b, c, d) + x + ac), s) + b;
}

void II(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac)
{
    *a = ROTL((*a + I(b, c, d) + x + ac), s) + b;
}

void md5_hash(uint8_t *initial_msg, size_t initial_len, uint8_t *digest)
{
    uint32_t s[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22 };
    uint32_t K[] = {
        0xD76AA478, 0xE8C7B756, 0x242070DB, 0xC1BDCEEE,
        0xF57C0FAF, 0x4787C62A, 0xA8304613, 0xFD469501,
        0x698098D8, 0x8B44F7AF, 0xFFFF5BB1, 0x895CD7BE,
        0x6B901122, 0xFD987193, 0xA679438E, 0x49B40821,
        0xF61E2562, 0xC040B340, 0x265E5A51, 0xE9B6C7AA,
        0xD62F105D, 0x02441453, 0xD8A1E681, 0xE7D3FBC8,
        0x21E1CDE6, 0xC33707D6, 0xF4D50D87, 0x455A14ED,
        0xA9E3E905, 0xFCEFA3F8, 0x676F02D9, 0x8D2A4C8A,
        0xFFFA3942, 0x8771F681, 0x6D9D6122, 0xFDE5380C,
        0xA4BEEA44, 0x4BDECFA9, 0xF6BB4B60, 0xBEBFBC70,
        0x289B7EC6, 0xEAA127FA, 0xD4EF3085, 0x04881D05,
        0xD9D4D039, 0xE6DB99E5, 0x1FA27CF8, 0xC4AC5665,
        0xF4292244, 0x432AFF97, 0xAB9423A7, 0xFC93A039,
        0x655B59C3, 0x8F0CCC92, 0xFFEFF47D, 0x85845DD1,
        0x6FA87E4F, 0xFE2CE6E0, 0xA3014314, 0x4E0811A1,
        0xF7537E82, 0xBD3AF235, 0x2AD7D2BB, 0xEB86D391
    };
    uint32_t h0, h1, h2, h3;
    uint8_t *msg = NULL;
    size_t new_len, offset;
    uint32_t *w, a, b, c, d, i, f, g, temp;

    new_len = ((((initial_len + 8) + 63) / 64) * 64);
    msg = calloc(new_len + 64, 1);
    if (msg == NULL) {
        return;
    }
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = (uint8_t)0x80;
    offset = new_len - 8;
    msg[offset + 0] = (uint8_t)(initial_len * 8);
    msg[offset + 1] = (uint8_t)((initial_len * 8) >> 8);
    msg[offset + 2] = (uint8_t)((initial_len * 8) >> 16);
    msg[offset + 3] = (uint8_t)((initial_len * 8) >> 24);
    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;
    for (i = 0; i < new_len; i += 64) {
        w = (uint32_t *)(msg + i);
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        for (uint32_t j = 0; j < 64; j++) {
            if (j < 16) {
                f = F(b, c, d);
                g = j;
            }
            else if (j < 32) {
                f = G(b, c, d);
                g = (5 * j + 1) % 16;
            }
            else if (j < 48) {
                f = H(b, c, d);
                g = (3 * j + 5) % 16;
            }
            else {
                f = I(b, c, d);
                g = (7 * j) % 16;
            }
            temp = d;
            d = c;
            c = b;
            b = b + ROTL((a + f + K[j] + w[g]), s[j]);
            a = temp;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }
    free(msg);
    memcpy(digest, &h0, sizeof(h0));
    memcpy(digest + sizeof(h0), &h1, sizeof(h1));
    memcpy(digest + sizeof(h0) + sizeof(h1), &h2, sizeof(h2));
    memcpy(digest + sizeof(h0) + sizeof(h1) + sizeof(h2), &h3, sizeof(h3));
}

int main() {
    char input[] = "Hello, World";
    uint8_t digest[16];
    md5_hash((uint8_t *)input, strlen(input), digest);
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}