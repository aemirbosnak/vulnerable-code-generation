//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define ROTL(x,n) ((x) << (n)) | ((x) >> (32 - (n))) //Left Rotation
#define ROTR(x,n) ((x) >> (n)) | ((x) << (32 - (n))) //Right Rotation

//MD5 Functions
uint32_t F1(uint32_t x, uint32_t y, uint32_t z) { return (x & y) | (~x & z); }
uint32_t F2(uint32_t x, uint32_t y, uint32_t z) { return (x & z) | (y & ~z); }
uint32_t F3(uint32_t x, uint32_t y, uint32_t z) { return x ^ y ^ z; }
uint32_t F4(uint32_t x, uint32_t y, uint32_t z) { return y ^ (x | ~z); }

//Endian Conversion Functions
uint32_t swap32(uint32_t num) { return (((num & 0xff) << 24) | ((num & 0xff00) << 8) | ((num & 0xff0000) >> 8) | ((num & 0xff000000) >> 24)); }
uint64_t swap64(uint64_t num) { return (((num & 0xff) << 56) | ((num & 0xff00) << 40) | ((num & 0xff0000) << 24) | ((num & 0xff000000) << 8) | ((num & 0xff00000000) >> 8) | ((num & 0xff0000000000) >> 24) | ((num & 0xff000000000000) >> 40) | ((num & 0xff00000000000000) >> 56)); }

//Main Hash Function
void md5_hash(uint8_t *message, uint32_t message_length, uint32_t *result) {
    uint32_t i, j, k;
    uint32_t a0 = 0x67452301, b0 = 0xefcdab89, c0 = 0x98badcfe, d0 = 0x10325476;
    uint64_t bitlen = message_length * 8;
    uint32_t m[16], s[4], a, b, c, d, f, g;

    //Pad message with bit 1 followed by zeros and 64-bit message length
    uint32_t padding_length = (message_length % 64 < 56) ? (64 - (message_length % 64)) : (128 - (message_length % 64));
    uint8_t *padded_message = calloc(message_length + padding_length + 8, 1);
    memcpy(padded_message, message, message_length);
    padded_message[message_length] = 0x80;
    memcpy((padded_message + message_length + padding_length), &bitlen, 8);

    //Process each 512-bit block of the padded message
    for (i = 0; i < (message_length + padding_length + 8) / 64; i++) {
        //Copy block into message schedule
        for (j = 0; j < 16; j++) {
            m[j] = (padded_message[i * 64 + j * 4 + 0] << 0) | (padded_message[i * 64 + j * 4 + 1] << 8) | (padded_message[i * 64 + j * 4 + 2] << 16) | (padded_message[i * 64 + j * 4 + 3] << 24);
        }

        //Initialize hash values for this block
        a = a0; b = b0; c = c0; d = d0;

        //Main loop for this block
        for (j = 0; j < 64; j++) {
            if (j < 16) {
                f = F1(b, c, d);
                g = j;
            } else if (j < 32) {
                f = F2(b, c, d);
                g = (5 * j + 1) % 16;
            } else if (j < 48) {
                f = F3(b, c, d);
                g = (3 * j + 5) % 16;
            } else {
                f = F4(b, c, d);
                g = (7 * j) % 16;
            }

            //Update hash values
            f += a + m[g] + (uint32_t)(0x100000000 * fabs(sin(j + 1)));
            a = d;
            d = c;
            c = b;
            b = b + ROTL(f, s[j % 4]);
        }

        //Add hash values for this block to in-progress result
        a0 += a;
        b0 += b;
        c0 += c;
        d0 += d;
    }

    //Store result, little-endian byte order
    result[0] = swap32(a0);
    result[1] = swap32(b0);
    result[2] = swap32(c0);
    result[3] = swap32(d0);

    //Free allocated memory
    free(padded_message);
}

int main() {
    uint8_t message[1000];
    uint32_t result[4];
    int i;

    printf("Enter message to hash: ");
    fgets((char *)message, 1000, stdin);

    //Strip trailing newline character, if any
    if (message[strlen((char *)message) - 1] == '\n') message[strlen((char *)message) - 1] = 0;

    //Convert to uppercase
    for (i = 0; i < strlen((char *)message); i++) message[i] = toupper(message[i]);

    //Hash message and print result
    md5_hash(message, strlen((char *)message), result);
    printf("%08x%08x%08x%08x\n", result[0], result[1], result[2], result[3]);

    return 0;
}