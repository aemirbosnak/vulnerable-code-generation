//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

uint32_t calculate_crc32(const char *input);

int main(void)
{
    char input[1024];
    uint32_t hashed_value;

    printf("Enter the string to hash: ");
    fgets(input, 1024, stdin);
    input[strlen(input) - 1] = '\0';

    hashed_value = calculate_crc32(input);

    printf("The hashed value of %s is 0x%x\n", input, hashed_value);

    return 0;
}

uint32_t calculate_crc32(const char *input)
{
    uint32_t crc_table[256];
    uint32_t crc = 0xffffffff;
    uint32_t length = strlen(input);

    // Generate the CRC table
    for (uint32_t i = 0; i < 256; i++) {
        uint32_t c = i;
        for (int j = 0; j < 8; j++) {
            if (c & 1)
                c = 0xedb88320L ^ (c >> 1);
            else
                c = c >> 1;
        }
        crc_table[i] = c;
    }

    // Calculate the CRC hash
    for (uint32_t i = 0; i < length; i++) {
        crc = crc_table[(crc ^ input[i]) & 0xff] ^ (crc >> 8);
    }

    // Return the final hash value
    return crc ^ 0xffffffff;
}